/************************************************************************
shcalc的计算引擎算法实现。
Copyright (C) 2022 NULL_703. All rights reserved.
Created on 2022.1.14  18:40
Created by NULL_703
Last change time on 2022.3.17  10:37
************************************************************************/
#include "include/calcEngine.h"
#include "include/calculate.h"

using namespace CalculateEngine;

#define keyCharsIndex 17    //关键字符的数量
#define keywordsIndex 19    //关键字的数量
static int kwIndex = 0;
//表达式模式和脚本模式的关键字符
char keyChars[keyCharsIndex] = {
    '+', '-', '*', '/', '(', ')', ',', ';', '{', '}', '<', '>', '$',       /* 关键字符 */
    '[', ']', '=', ':'                                                     /* 保留字符 */
};
//关键字
char keywords[keywordsIndex][0xf] = {
    "log", "ln", "fx", "tan", "atan", "sin", "asin", "cos", "acos", "rot",                /* 关键字 */
    "mat", "div", "rand", "clear", "if", "else", "range", "while", "ret"                  /* 保留字 */
};

//字符匹配，若该字符不在关键字符列表中则返回1，否则返回0
int mixcalc::keycharMatch(char ch)
{
    for(int i = 0; i <= keyCharsIndex; ++i)
    {
        if(keyChars[i] == ch)
            return 0;
    }
    return 1;
}

//关键字匹配，若该字符串不在关键字列表中则返回1，否则返回0
int mixcalc::keywordMatch(const char* keyword)
{
    for(int i = 0; i <= keywordsIndex; ++i)
    {
        if(strcmp(keywords[i], keyword) == 0)
        {
            kwIndex = i;
            return 0; 
        }
    }
    return 1;
}

double mixcalc::exprCalc(double x, double y, KeyChars operChar)
{
    if(operType(operChar) != 0) return x;
    switch(operChar)
    {
        case chadd: return x + y; break;    /* + */
        case chsub: return x - y; break;    /* - */
        case chmul: return x * y; break;    /* * */
        case chdiv: return x / y; break;    /* / */
        default: return 0;
    }
}

SHK_BOOL mixcalc::symbolCheck(const char* symbols, int index)
{
    if(shk_IsStrNum(symbols, SHK_FALSE) == SHK_FALSE) return SHK_FALSE;
    if(keywordMatch(symbols) == 0) return SHK_FALSE;
}

double mixcalc::normalExprProcess(const char* expr)
{
    double results[0x20];
    char bufchar[0x400][0xff];
    int bufIndex = 0;
    int resultIndex = 0;
    for(int i = 0, j = 0, k = 0; expr[i] != '\0'; i++)
    {
        if(keycharMatch(expr[i]) == 0 && expr[i] != '.' && i != 0)
        {
            opchars[j] = operProc(expr[i]);
            bufchar[bufIndex][k] = '\0';
            if(bufIndex != 0)
            {
                if(symbolCheck(bufchar[bufIndex], j) == SHK_FALSE) return NAN;
                results[resultIndex] = atof(bufchar[bufIndex]);
                results[resultIndex - 1] = exprCalc(results[resultIndex - 1], results[resultIndex], opchars[j]);
                bufIndex--;
                resultIndex--;
                j--;
            }else{
                results[resultIndex] = atof(bufchar[bufIndex]);
                resultIndex++;
            }
            k = 0;
            j++;    //运算符匹配到后变量j自增，同时字符串索引值自增继续下一个数值的读取
            bufIndex++;
            continue;
        }
        bufchar[bufIndex][k] = expr[i];
        k++;
    }
}

double mixcalc::functionExpr(const char* expr)
{
    ;
}