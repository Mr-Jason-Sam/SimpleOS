#ifndef OS_GLOBAL_H
#define OS_GLOBAL_H

#define FONTWIDETH 8
#define FONTHIGHTH 16
#define KEYWORDNUM 9

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

//extern int lableNum;
//extern string lable;
//extern string keyword[];
//extern vector<string>   codeStream;

typedef struct {
    double red;
    double green;
    double blue;
    double alpha;
}FontRGBA;

//typedef struct Draw{
//    int column;
//    int row;
//    FontRGBA rbga;
//    struct Draw *next;
//}Paint;

//enum var_type{
//    int_var,
//    int_array,
//    string_var,
//    string_array
//};

//enum number_type{
//    int_type,
//    float_type,
//    double_type
//};

//enum exp_type{
//    if_type,
//    while_exp
//};

//class symbol{
//public:
//    string symbolName;
//    int array_size;
//    var_type type;
//};

//extern vector<symbol> symbolTable;


//bool symbolSearch(string symbolName);
//void symbolInsert(string name,var_type);
//var_type matchSymbolType(string name);
//symbol getSymbol(string name);

//string getLable(string);


//void error(string error);
//int string2int(string str);
//char * string2char(string str);


#endif // OS_GLOBAL_H
