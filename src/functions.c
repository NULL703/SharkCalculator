/************************************************************************
公式库附属的专用函数。
Copyright (C) 2021 NULL_703. All rights reserved.
Created on 2021.11.4  19:31
Created by NULL_703
Last change time on 2021.12.11  12:24
************************************************************************/
#include "include/functions.h"
#include <math.h>

double shk_ang2rad(double angle)
{
    return angle * (M_PI / 180);
}

double shk_abs(double number)
{
    return number > 0 ? number : -number;
}

double shk_pow(double x, int y)
{
    double z = x;
    if(y < 0)
        return 1 / shk_pow(x, shk_abs(y));
    if(y == 0)
        return 1;
    for(int i = (int)y - 1; i > 0; i--)
        x *= z;
    return x;
}

double shk_cexp(double x)
{
    return shk_pow(M_E, x);
}

int shk_strlen(const char* s)
{
    const char *sc;
    for(sc = s; *s; ++sc){;}
    return sc - s;
}

SHK_BOOL shk_IsOdd(int x)
{
    return (x / 2 == 0) ? SHK_FALSE : SHK_TRUE;
}

SHK_BOOL shk_Isfint(double x)
{
    return (x - (int)x == 0.0) ? SHK_TRUE : SHK_FALSE;
}

double shk_QuadraticFunction(double x, double a, double b, double c)
{
    return a * shk_pow(x, 2) + b * x + c;
}

int shk_NumberLevel(int x)
{
    int result;
    int stdNum = 10;
    for(result = 1; stdNum > x; result++)
        stdNum *= 10;
    return result;
}

int shk_mod(int x, int y)
{
    return x - ((int)(x / y) * y);
}

long shk_AsciiToNum(char* number)
{
    int numBit = 0;
    long result = 0;
    numBit = shk_strlen(number);
    if(numBit >= 10)
        return 0xffff;
    for(int i = numBit; i > 0; i++)
        result += (number[i - 1] - 48) * shk_pow(10, i);
    return result;
}