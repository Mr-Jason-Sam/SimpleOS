//#include "OS_Global.h"

//int lableNum = 0;
//string lable = "No";
//vector<string> codeStream;
//vector<symbol> symbolTable;

//bool symbolSearch(string symbolName){
//    for(int symbol_index = 0; symbol_index < symbolTable.size(); symbol_index++){
//        if(symbolTable[symbol_index].symbolName == symbolName)
//            return true;
//    }
//    return false;
//}

//void symbolInsert(string name,var_type type){
//    symbol example;
//    example.symbolName = name;
//    example.type = type;
//    symbolTable.push_back(example);
//}

//var_type matchSymbolType(string symbolName){
//    symbol example;
//    for(int symbol_index = 0; symbol_index < symbolTable.size();symbol_index++){
//        if(symbolName == symbolTable[symbol_index].symbolName){
//            example = symbolTable[symbol_index];
//        }
//    }
//    return example.type;
//}

//void error(string strerror){
//    cout << "Error:"<<strerror << endl;
//}

//int string2int(string str){
//    return atoi(str.c_str());
//}

//char * string2char(string str)
//{
//    return const_cast<char *>(str.c_str());
//}

//string getLable(string choice){
//    stringstream s;
//    string str;
//    string sign = "";
//    if(choice == "current"){
//        s << lableNum;
//        s >> str;
//        sign = lable + str;
//    }
//    else if (choice == "next"){
//        lableNum++;
//        s << lableNum;
//        s >> str;
//        sign = lable + str;
//    }
//    return sign;
//}

//string keyword [] =  {
//    //define
//    "functoin",
//    "var",
//    //type
//    "int",
//    "string",
//    //exp
//    "while",
//    "if",
//    "else",
//    "for",
//    //system func
//    "print"
//};


