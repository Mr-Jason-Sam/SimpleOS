#include <gtk/gtk.h>
#include <OS_Bitmap.h>
#include <pthread.h>
#include <unistd.h>
#include <vector>
#include <iostream>
#include <gdk/gdkkeysyms.h>
#include "OS_File.h"
#include "OS_Global.h"

using namespace std;

/* Surface to store current scribbles */
static cairo_surface_t *surface = NULL;
static int cin_signal = 0;
static unsigned int mColumn = 0;
static unsigned int mRow = 0;
static unsigned int mLastColumn = 0;
static unsigned int mLastRow = 0;
static unsigned int fontCount = 0;

pthread_t flashing;
pthread_t drawing;
vector<char> command;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void clear_surface (void){
    cairo_t *cr;

    cr = cairo_create (surface);

    cairo_set_source_rgb (cr, 0, 0, 0);
    cairo_paint (cr);

    cairo_destroy (cr);
}

//创建一个新的表面适当大小的存储我们的涂鸦
gboolean configure_event_cb (GtkWidget *widget,  GdkEventConfigure *event,gpointer data){
    if (surface)
        cairo_surface_destroy (surface);

    surface = gdk_window_create_similar_surface (
                gtk_widget_get_window (widget),
                CAIRO_CONTENT_COLOR,
                gtk_widget_get_allocated_width (widget),
                gtk_widget_get_allocated_height (widget));

    /* Initialize the surface to black */
    clear_surface ();

    /* We've handled the configure event, no need for further processing. */
    return TRUE;
}

gboolean draw_cb (GtkWidget *widget, cairo_t *cr,gpointer data){
    cairo_set_source_surface (cr, surface, 0, 0);
    cairo_paint (cr);

    return FALSE;
}

void draw_pixel(FontRGBA rgba, cairo_t *canvas, int x, int y);
void draw_pixel(FontRGBA rgba, cairo_t *canvas, int x, int y){
    cairo_set_source_rgba(canvas, rgba.red, rgba.green, rgba.blue, rgba.alpha);
    cairo_rectangle (canvas, x+ 8 * mColumn , y +mRow , 1, 1);
    cairo_fill (canvas);
}

void draw_character_brush (GtkWidget *widget,gchar character){
    cairo_t *canvas;
    FontRGBA rgba;
    canvas = cairo_create (surface);
    int* bit = NULL;
    Bitmap characterBitmap = Bitmap();
    bit = characterBitmap.print(character);

    for(int row = 0; row < 16; row++){
        for(int column = 0; column < 8; column++){
            if(bit[row * 8 + column] == 1){
                rgba.red     = 1.0;
                rgba.green = 1.0;
                rgba.blue    = 1.0;
                rgba.alpha  = 1.0;
                draw_pixel(rgba,canvas,column,row);
            }else{
                rgba.red     = 0;
                rgba.green = 0;
                rgba.blue    = 0;
                rgba.alpha  = 1;
                draw_pixel(rgba,canvas,column,row);
            }
        }
    }

    cairo_destroy (canvas);
    gtk_widget_queue_draw(widget);
    mColumn++;
    cin_signal = 0;

    pthread_cond_signal(&cond);
}

void restore(GtkWidget *widget){
    GtkWidget *window = (GtkWidget*)widget;
    cairo_t *canvas;
    canvas = cairo_create (surface);
    cairo_set_source_rgb (canvas, 0, 0, 0);

    cairo_rectangle (canvas,  8 * mLastColumn , mLastRow , 8, 16);
    cairo_fill (canvas);
    cairo_destroy (canvas);

    gtk_widget_queue_draw(window);
    gtk_widget_show_all (window);
}

int checkCommand(int character,GtkWidget* window){
    if(character == 65293){
        mLastColumn = mColumn;
        mLastRow = mRow;
        mRow += FONTHIGHTH;
        mColumn = 0;

        command.clear();
        restore(window);
        return 0;
    }else if(character == 65288){
        mLastColumn = mColumn;
        mLastRow = mRow;
        restore(window);
        mColumn--;
        if(mColumn < 0){
            mColumn = 0;
            return 0;
        }
        command.pop_back();
        return 0;
    }
    return 1;
}

gboolean key_press_event(GtkWidget *widget, GdkEventKey *event, gpointer data){
    if (surface == NULL)
        return FALSE;

    fontCount++;
    char character =  (char)event->keyval;
    //g_print("%d",event->keyval);
    if(!checkCommand(event->keyval,widget)){
        return TRUE;
    }

    cin_signal = 1;

    command.push_back(character);

    draw_character_brush(widget,event->keyval);

    return TRUE;
}

void close_window (void){
    if (surface)
        cairo_surface_destroy (surface);

    gtk_main_quit ();
}

void *appear_cursor(void *widget){
    GtkWidget *window = (GtkWidget*)widget;
    cairo_t *canvas;
    canvas = cairo_create (surface);

    cairo_set_source_rgb (canvas, 1, 1, 1);

    cairo_rectangle (canvas,  8 * mColumn , mRow , 8, 16);
    cairo_fill (canvas);


    cairo_destroy (canvas);

    //printf("appear");

    gtk_widget_queue_draw(window);
    gtk_widget_show_all (window);
    return 0;
}

void *disappear_cursor(void *widget){
    GtkWidget *window = (GtkWidget*)widget;
    cairo_t *canvas;
    canvas = cairo_create (surface);
    cairo_set_source_rgb (canvas, 0, 0, 0);

    cairo_rectangle (canvas,  8 * mColumn , mRow , 8, 16);
    cairo_fill (canvas);
    cairo_destroy (canvas);

    gtk_widget_queue_draw(window);
    gtk_widget_show_all (window);
    return 0;
}

void *flash(void *widget){
    GtkWidget *window = (GtkWidget*)widget;
    while(1){
        pthread_mutex_lock (&mutex);

        while(cin_signal)
            pthread_cond_wait(&cond, &mutex);

        appear_cursor(window);
        usleep(600000);
        disappear_cursor(window);
        usleep(600000);

        pthread_mutex_unlock (&mutex);
    }
}

void *draw_thread(void* widget);
void *draw_thread(void* widget){
    GtkWidget *window = (GtkWidget*)widget;
    g_signal_connect(window,"key-press-event",
                     G_CALLBACK(key_press_event),NULL);
}

void activate (void *widget){
    GtkWidget *window = (GtkWidget*)widget;
    GtkWidget *drawing_area;
    drawing_area = gtk_drawing_area_new ();

    int flashing_success = pthread_create(&flashing,
                                                                        NULL,
                                                                        flash,
                                                                        window);
    if(flashing_success){
        printf("Create pthread error!");
        exit(1);
    }

    gtk_window_set_title (GTK_WINDOW (window), "OS_Terminal");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_widget_set_size_request(window, 500, 700);

    gtk_container_add (GTK_CONTAINER (window), drawing_area);

    /* Signals used to handle the backing surface */
    g_signal_connect (drawing_area, "draw",
                      G_CALLBACK (draw_cb), NULL);
    g_signal_connect (drawing_area,"configure-event",
                      G_CALLBACK (configure_event_cb), NULL);

    g_signal_connect (window, "destroy", G_CALLBACK (close_window), NULL);

    gtk_widget_add_events (window, GDK_KEY_PRESS_MASK );
    //gtk_widget_add_events (drawing_area,GDK_BUTTON_PRESS_MASK);

    /* Event signals */


//    int drawing_success = pthread_create(&drawing,
//                                                                        NULL,
//                                                                        draw_thread,
//                                                                        window);

    g_signal_connect(window,"key-press-event",
                     G_CALLBACK(key_press_event),NULL);

//    g_signal_connect(drawing_area,"button-press-event",
//                     G_CALLBACK(button_press_event),NULL);


    gtk_widget_show_all (window);
}

