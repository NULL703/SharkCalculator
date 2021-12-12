/************************************************************************
基本计算方法。
Copyright (C) 2021 NULL_703. All rights reserved.
Created on 2021.11.29  16:17
Created by NULL_703
Last change time on 2021.12.4  19:50
************************************************************************/
#include "include/calculate.h"

double calcTypeProc(enum calc calcType, double x, double y)
{
    switch(calcType)
    {
        case cadd:
            return add(x, y);
            break;
        case csub:
            return sub(x, y);
            break;
        case cmul:
            return mul(x, y);
            break;
        case cdiv:
            return div(x, y);
            break;
        default:
            printf("%s%s%s", F_RED, w0016, NORMAL);
            return -0xffff;
    }
}

double add(double x, double y)
{
    return x + y;
}

double sub(double x, double y)
{
    return x - y;
}

double mul(double x, double y)
{
    return x * y;
}

double div(double x, double y)
{
    if(y == 0)
    {
        printf("%s%s%s", F_RED, w0003, NORMAL);
        return 0;
    }
    return x / y;
}