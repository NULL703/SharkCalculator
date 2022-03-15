/************************************************************************
shcalc的计算引擎算法实现。
Copyright (C) 2022 NULL_703. All rights reserved.
Created on 2022.1.14  18:40
Created by NULL_703
Last change time on 2022.3.15  10:36
************************************************************************/
#include "include/calcEngine.h"

using namespace CalculateEngine;

#define keyCharsIndex 17    //关键字符的数量
#define keywordsIndex 19    //关键字的数量
//表达式模式和脚本模式的关键字符
char keyChars[keyCharsIndex] = {
    '+', '-', '*', '/', '(', ')', ',', ';', '{', '}', '<', '>', '$',       /* 关键字符 */
    '[', ']', '=', ':'                                                     /* 保留字符 */
};
//关键字
char keywords[keywordsIndex][0x20] = {
    "log", "ln", "fx", "tan", "atan", "sin", "asin", "cos", "acos", "rot",                /* 关键字 */
    "mat", "div", "rand", "clear", "if", "else", "range", "while", "ret"               /* 保留字 */
};

//字符匹配，若该字符不在关键字符列表中则返回1，否则返回0
int mixcalc::keycharMatch(char ch)
{
    for(int i = 0; i <= keyCharsIndex; ++i)
    {
        if(keyChars[i] == ch)
            break; 
        else
            return 1;
    }
    return 0;
}

//关键字匹配，若该字符串不在关键字列表中则返回1，否则返回0
int mixcalc::keywordMatch(const char* keyword)
{
    ;
}

double mixcalc::normalExprProcess(const char* expr)
{
    char* bufchar[0xff];
    int bufIndex = 0;
    for(int i = 0, j = 0; expr; i++)
    {
        if(keycharMatch(expr[i]) == 0)
        {
            bufchar[j][i] = expr[i];
        }
        bufchar[charIndex][i] = expr[i];
    }
}

double mixcalc::functionExpr(const char* expr)
{
    ;
}