#include <gtk/gtk.h>
#include "soo_parse.h"
#include "soo_token.h"
#include "lvm_assembler.h"
#include "lvm_lmachine.h"
#include "window.cpp"

int main (int argc, char * argv[])
{
    token tokenmachine;
    tokenmachine.tokeninit();
    tokenmachine.readline();
    parse parsemachine;
    parsemachine.build_ast();
    //cout<<"Soo Complier is over ..."<<endl;

    Lmachine lvm;
    lvm.init();         //init lmachine
    lvm.readline();     //get code
    Assembler assembler;
    assembler.assemblerrun();
    lvm.lvmrun(assembler);
   // cout<<"lvm is over ..."<<endl;

    gtk_init(&argc, &argv);
    GtkWidget* window;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    activate(window);
    gtk_main();

    return 0;
}
