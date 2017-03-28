//
//  parse.h
//  Soo
//
//  Created by leviathan on 15/9/9.
//  Copyright (c) 2015年 leviathan. All rights reserved.
//

#ifndef SOO_PARSE_H_
#define SOO_PARSE_H_

#include <iostream>
#include "soo_global.h"
#include "soo_ast.h"
using namespace std;

class parse
{
public:
    static int index;
    bool judge_op(string token);
    bool judge_variable(string variable);
    bool judge_system_func(string name);
    bool lowlevel(string token,string top);
    int operation(int num1, int num2, string op);
    void build_ast();
    //int  binary_immediate();
    //int getvalue(string name);
    int string2int(string str);
    void parse_number(int number);
    void parse_defvar();						//define variable
    void parse_binary(string variable_name);	//binary expreesion
    string parse_binary_exp();
    string parse_binary_term();
    string parse_binary_factor();
    void parse_func();
    void parse_system_func();
    void parse_system_print();
    void parse_expreesion();
    void parse_if();
    void parse_while();
    void parse_judge(exp_type type,string choice);
    void parse_bool(vector<string> codes,string choice);
    bool parse_judgenumber(string num); //check array size type is int or not
    void parse_typecheck(string type);
    void parse_idcheck(string id);
    void parse_tokenjudge(string token);
    void parse_numbercheck(string num);
    void parse_operatorcheck(string op);
    string parse_getarrayinfo(string variable_name);
    string parse_get_variable_real(string variable_name);
};

#endif /* defined(SOO_PARSE_H_) */
