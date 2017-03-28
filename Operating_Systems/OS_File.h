#ifndef OS_FILE_H
#define OS_FILE_H

#include <string>
#include <iostream>

using namespace std;

class OS_File
{
private:
    static OS_File *file;
    string mReadFile,mWriteFile;
    OS_File(){}
public:
    static OS_File *GetInstance();
    string getReadFile();
    string getWriteFile();
    void   setReadFile(string readFile);
    void   setWriteFile(string writeFile);

};

#endif // OS_FILE_H
