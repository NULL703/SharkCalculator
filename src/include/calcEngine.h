/************************************************************************
计算引擎函数的声明。
Copyright (C) 2022 NULL_703. All rights reserved.
Created on 2022.1.14  18:42
Created by NULL_703
Last change time on 2022.3.19  15:28
************************************************************************/
#ifndef SHARKCALCULATOR_CALCENGINE_H
#define SHARKCALCULATOR_CALCENGINE_H

#include "incs.h"

namespace CalculateEngine
{
    typedef enum charType{
        cherr, chadd, chsub, chmul, chdiv, chslfinc, chsrhinc,      /* + - * / ( ) */
        chcma, chsem, chblfinc, chbrhinc, chlflb, chrhlb,           /* , ; { } < > */
        chsl, chlfmdinc, chrhmdinc, chequ, chcolon                  /* $ [ ] = : */
    }KeyChars;
    typedef enum keyToken{
        shlog, shln, shfunc, shtan, shatan, shsin, shasin, shcos, shacos, shsqrt,     /* 关键字 */
        shmat, shdiv, shrand, shclear, shif, shelse, shrange, shwhile, shreturn       /* 保留字 */
    }KeyTokens;
    class mixcalc{
        public:
            double normalExprProcess(const char* expr);
            double functionExpr(const char* expr);
        private:
            KeyChars opchars[0xff];
            int keycharMatch(char ch);
            int keywordMatch(const char* keyword);
            double exprCalc(double x, double y, KeyChars operChar);
            KeyChars operProc(char op);
            int operType(char oper);
            SHK_BOOL symbolCheck(const char* symbols, int index);
    };
}    //namespace CalculateEngine
#endif    //SHARKCLACULATOR_CALCENGINE_H