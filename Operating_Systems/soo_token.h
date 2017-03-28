//
//  token.h
//  Soo
//
//  Created by leviathan on 15/9/8.
//  Copyright (c) 2015年 leviathan. All rights reserved.
//

#ifndef SOO_TOKEN_H_
#define SOO_TOKEN_H_

#include <iostream>
#include <string>
#include "soo_global.h"
using namespace std;

class token
{
public:
    char * string2char(string str);
    static string infile;
    static string outfile;
    bool tokeninit();
    void readline();
};
#endif /* defined(SOO_TOKEN_H_) */
