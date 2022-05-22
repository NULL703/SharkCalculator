/************************************************************************
shcalc的计算引擎算法实现——运算符处理。
Copyright (C) 2022 NULL_703. All rights reserved.
Created on 2022.2.16  18:05
Created by NULL_703
Last change time on 2022.3.20  9:38
************************************************************************/
#include "include/calcEngine.h"

using namespace CalculateEngine;

KeyChars mixcalc::operProc(char op)
{
    switch(op)
    {
        case '+': return chadd; break;
        case '-': return chsub; break;
        case '*': return chmul; break;
        case '/': return chdiv; break;
        case '(': return chslfinc; break;
        case ')': return chsrhinc; break;
        case ',': return chcma; break;
        case ';': return chsem; break;
        case '{': return chblfinc; break;
        case '}': return chbrhinc; break;
        case '<': return chlflb; break;
        case '>': return chrhlb; break;
        case '$': return chsl; break;
        case '[':
        case ']':
        case '=':
        case ':': 
        default: return cherr;
    }
}

int mixcalc::operType(char oper)
{
    switch(oper)
    {
        /* 二元运算符 */
        case '+':
        case '-':
        case '*':
        case '/': return 0; break;
        /* 括号类运算符 */
        case '(':
        case ')':
        case '[':
        case ']':
        case '{':
        case '}': return 1; break;
        default: return -1;
    }
}