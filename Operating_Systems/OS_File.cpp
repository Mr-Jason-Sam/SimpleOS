#include "OS_File.h"

OS_File *OS_File::file = NULL;

OS_File *OS_File::GetInstance(){
    if (file == NULL){
        file = new OS_File();
    }
    return file;
}

void OS_File::setReadFile(string readFile){
    mReadFile = readFile;
}

void OS_File::setWriteFile(string writeFile){
    mWriteFile = writeFile;
}

string OS_File::getWriteFile(){
    return mWriteFile;
}

string OS_File::getReadFile(){
    return mReadFile;
}



