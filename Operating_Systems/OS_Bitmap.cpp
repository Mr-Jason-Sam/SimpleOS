#include "OS_Bitmap.h"

Bitmap::Bitmap(){
    /*Init bitmap value*/
    //initBitmapSourcePath();
    initBitmapSource();
    initCharacterBitmap();

}

void Bitmap::initBitmapSourcePath(){
    strcpy(mBitmapSourcePath,BITMAP_SOURCE_PATH);
}

void Bitmap::initCharacterBitmap(){
    for(int bit = 0; bit < 128; bit++)
        mCharacterBitmap[bit] = 0;
}

void Bitmap::initBitmapSource(){
    FILE *file;
    //unsigned char loadBitmapSource[BITMAP_SOURCE_SIZE];

    file = fopen("/home/jason/Desktop/Gtk_Drawing/ASC16", "rb");

    if (file == NULL)
    {
        printf ("read ASC16 file failed!");
        return;
    }

    fread(mBitmapSource, 1, 4096, file);
    fclose(file);
}

int* Bitmap::setBitmapDataInfo(char character){
    unsigned char *characterBit = mBitmapSource + (int)character * 16;

        for (int row = 0; row < 16; row++)
        {
            unsigned char spaceBit = 128;
            for (int column = 0; column < 8; column++)
            {
                if (*characterBit & spaceBit)
                    mCharacterBitmap[row*8+column] = 1;
                else
                    mCharacterBitmap[row*8+column] = 0;

                spaceBit >>= 1;
            }

            characterBit++;
        }

        return mCharacterBitmap;

}


int* Bitmap::print(char character){
    return setBitmapDataInfo(character);
}

