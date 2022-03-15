/************************************************************************
计算引擎函数的声明。
Copyright (C) 2022 NULL_703. All rights reserved.
Created on 2022.1.14  18:42
Created by NULL_703
Last change time on 2022.3.15  10:38
************************************************************************/
#ifndef SHARKCALCULATOR_CALCENGINE_H
#define SHARKCALCULATOR_CALCENGINE_H

#include "incs.h"
#include "calculate.h"

namespace CalculateEngine
{
    enum charType{
        cherr, chadd, chsub, chmul, chdiv, chslfinc, chsrhinc,      /* + - * / ( ) */
        chcma, chsem, chblfinc, chbrhinc, chlflb, chrhlb,           /* , ; { } < > */
        chsl, chlfmdinc, chrhmdinc, chequ, chcolon                  /* $ [ ] = : */
    };
    class mixcalc{
        public:
            double normalExprProcess(const char* expr);
            double functionExpr(const char* expr);
        private:
            char operChar[0xfff];
            int charIndex = 0;
            int keycharMatch(char ch);
            int keywordMatch(const char* keyword);
    };
}    //namespace calculateEngine
#endif    //SHARKCLACULATOR_CALCENGINE_H