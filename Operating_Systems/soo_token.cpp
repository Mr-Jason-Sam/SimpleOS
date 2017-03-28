//
//  token.cpp
//  Soo
//
//  Created by leviathan on 15/9/8.
//  Copyright (c) 2015年 leviathan. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "soo_global.h"
#include "soo_token.h"
using namespace std;

//static variable
string token::infile = "";
string token::outfile = "";

char * token::string2char(string str)
{
    return const_cast<char *>(str.c_str());
}

bool token::tokeninit()
{
//    cout << "please enter source file path and name :";
//    cin >> infile;
    infile = "/home/jason/Desktop/Operating_Systems/heart.txt";
//    ifstream search;
//    char *starfile = string2char(infile);
//    search.open(starfile,ios::app);
//    if (!search)
//        cout << "source file " << infile << " not find " << endl;
//    while (!search) {
//        cout << "please input correct file  path and name :" << endl;
//        cin >> infile;
//        search.open(string2char(infile));
//    }
//    cout << "please enter output file path and name :";
//    cin >> outfile;
    outfile = "/home/jason/Desktop/Operating_Systems/heart_parsing_code.txt";
//    FILE * fp;
//    fp = fopen(string2char(outfile), "w");

    ofstream newoutfile;
    newoutfile.open(string2char(outfile));
   // newoutfile
//    if (oldoutfile){
//        remove(oldoutfile);
//        ofstream newoutfile(string2char(outfile));
        //newoutfile.open;
 //   }
//        cout << "file " << outfile << " is create success " << endl;
    return true;
}

void token::readline()
{
    int index, length;
    ifstream code;
    code.open(infile);
    string line;
    while (getline(code, line)) {
        length = int(line.length());
        index = 0;
        while (index<length) {
            //number
            if (line[index] >= '0'&&line[index] <= '9')
            {
                string token = "";
                token += line[index];
                index++;
                while (line[index] >= '0'&&line[index]<'9') {
                    token += line[index];
                    index++;
                }
                codestream.push_back(token);
            }
            //id
            else if ((line[index] >= 'a'&&line[index]<'z') || (line[index] >= 'A'&&line[index] <= 'Z'))
            {
                string token = "";
                token += line[index];
                index++;
                while ((line[index] >= 'a'&&line[index]<'z') || (line[index] >= 'A'&&line[index] <= 'Z') || (line[index] >= '0'&&line[index]<'9')) {
                    token += line[index];
                    index++;
                }
                codestream.push_back(token);
            }
            //symbol
            else if (line[index] == ';'||line[index]==','||line[index]=='"'||line[index]=='\\')
            {
                string token = "";
                token += line[index];
                index++;
                codestream.push_back(token);
            }
            //operator
            else if (line[index] == '+' || line[index] == '-' || line[index] == '*' || line[index] == '/')
            {
                string token = "";
                token += line[index];
                index++;
                codestream.push_back(token);
            }
            //comparison operator
            else if (line[index] == '=' || line[index] == '<' || line[index] == '>')
            {
                string token = "";
                token += line[index];
                index++;
                codestream.push_back(token);
            }
            //brcket
            else if (line[index] == '{' || line[index] == '}' || line[index] == '(' || line[index] == ')'||line[index]=='['||line[index]==']')
            {
                string token = "";
                token += line[index];
                index++;
                codestream.push_back(token);
            }
            //comments
            else if (line[index] == '#')
            {
                index++;
                while (index<length) {
                    index++;
                }
            }
            //space
            else if(line[index]=='\t'||line[index]=='\n'||line[index]==' ')
                index++;
        }
        string end = "\n";
        codestream.push_back(end);
    }
}
