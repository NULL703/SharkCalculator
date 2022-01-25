/************************************************************************
计算引擎函数的声明。
Copyright (C) 2022 NULL_703. All rights reserved.
Created on 2022.1.14  18:42
Created by NULL_703
Last change time on 2022.1.14  19:03
************************************************************************/
#ifndef SHARKCALCULATOR_CALCENGINE_H
#define SHARKCALCULATOR_CALCENGINE_H

#include "incs.h"
#include "calculate.h"

namespace calculateEngine
{
    class mixcalc{
        public:
            double normalExprProcess(const char* expr);
            double functionExpr(const char* expr);
        private:
    };
}    //namespace calculateEngine
#endif    //SHARKCLACULATOR_CALCENGINE_H