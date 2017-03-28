//
//  global.cpp
//  Soo
//
//  Created by leviathan on 15/9/8.
//  Copyright (c) 2015年 leviathan. All rights reserved.
//

#include "soo_global.h"
#include <string>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

string node = "soo";
int nodenum = -1;
vector<string> codestream;
vector<symbol> symboltable;

bool symbol_search(string name)
{
    for (int symbol_index = 0; symbol_index < symboltable.size(); symbol_index++)
    {
        if (name == symboltable[symbol_index].symbolname)
            return true;
    }
    return false;
}

void symbol_insert(string name, var_type type)
{
    symbol newsymbol;
    newsymbol.symbolname=name;
    newsymbol.type=type;
    symboltable.push_back(newsymbol);
}

var_type symbol_gettype(string name)
{
    symbol get;
    for (int symbol_index=0; symbol_index<symboltable.size(); symbol_index++) {
        if(name==symboltable[symbol_index].symbolname)
            get=symboltable[symbol_index];
    }
    return get.type;
}

symbol symbol_getsymbol(string name)
{
    symbol nullsymbol;
    for(int symbol_index=0;symbol_index<symboltable.size();symbol_index++)
    {
        if(name==symboltable[symbol_index].symbolname)
            return symboltable[symbol_index];
    }
    return nullsymbol;
}
void error(string strerror)
{
    cout << "Error:"<<strerror << endl;
}

char * string2char(string str)
{
    return const_cast<char *>(str.c_str());
}

//get address label
string getsign(string choice)
{
    if (choice == "now")
    {
        stringstream s;
        string str;
        s << nodenum;
        s >> str;
        string sign = node + str;
        return sign;
    }
    else if (choice == "next")
    {
        nodenum++;
        stringstream s;
        string str;
        s << nodenum;
        s >> str;
        string sign = node + str;
        return sign;
    }
    else
        return "";
}

//key word
string keyword[]=
{
    //define
    "var",
    "def",
    //type
    "int",
    "string",
    //exp
    "if",
    "while",
    //system function
    "print"
    
};
