#ifndef BITMAP_H
#define BITMAP_H
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <cstring>
using namespace std;

#define BITMAP_SOURCE_SIZE 4096

#define BITMAP_SPACE_SIZE 128

#define BITMAP_SOURCE_PATH  "/home/jason/Desktop/OS/OS_Jason_Sam/ASC16"

class Bitmap
{

private:
    char*                     mBitmapSourcePath;
    unsigned char       mBitmapSource[BITMAP_SOURCE_SIZE];
    int                         mCharacterBitmap[BITMAP_SPACE_SIZE];
    int*                        setBitmapDataInfo(char);
    void                       initBitmapSourcePath();
    void                       initBitmapSource();
    void                       initCharacterBitmap();


public:
    Bitmap();
    int*                        print(char);

};

#endif // BITMAP_H
