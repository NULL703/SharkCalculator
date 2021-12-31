/************************************************************************
公式库附属的专用函数。
Copyright (C) 2021 NULL_703. All rights reserved.
Created on 2021.11.4  19:31
Created by NULL_703
Last change time on 2021.12.31  14:48
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
    for(sc = s; *sc; ++sc){;}
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
    for(int i = 0; i < numBit; i++)
        result += (number[i] - 48) * (shk_pow(10, numBit - i) / 10);
    return result;
}

int shk_adder(int min, int max)
{
    int result = min;
    for(int i = 0; i < max - min; i++)
        result += min + (i + 1);
    return result;
}

SHK_BOOL shk_IsStrNum(const char* num, SHK_BOOL intMode)
{
    int count = shk_strlen(num);
    SHK_BOOL decPoint = SHK_FALSE;
    for(int i = 0; i < count; i++)
    {
        if(num[i] > 52 || num[i] < 48)
        {
            if(intMode == SHK_TRUE)
                return SHK_FALSE;
            else{
                if(num[i] != '.' || (num[i] == '.' && decPoint == SHK_TRUE))
                    return SHK_FALSE;
                if(num[i] == '.')
                    decPoint = SHK_TRUE;
            }
        }
    }
    return SHK_TRUE;
}

char* shk_StrInvert(const char* str)
{
    int charCount = shk_strlen(str);
    if(charCount > 0xffff)
        return "!SLE";
    static char result[0xffff];
    for(int i = charCount, j = 0; i >= 0; i--, j++)
        result[j] = str[i - 1];
    return result;
}

SHK_BINARY shk_DecToBin(int decNum)
{
    static char result[0x100];
    for(int i = 0; decNum >= 1; i++)
    {
        if(i >= 0x100)
            return "!BLE";
        result[i] = shk_mod(decNum, 2) + 48;
        /*在每次取模之后减去余数再除以2*/
        decNum -= shk_mod(decNum, 2);
        decNum /= 2;
    }
    return shk_StrInvert(result);     //倒置字符串得到整数对应的二进制值
}

int shk_BinToDec(const char* origbin)
{
    int index = shk_strlen(origbin);
    int result = 0;
    for(; index > 0; index--)
    {
        if(origbin[index - 1] == '1')
            result += shk_pow(2, (shk_strlen(origbin) - (index - 1) - 1));
        else if(origbin[index - 1] == '0')
            result += 0;
        else
            return 0xffff;
    }
    return result;
}

SHK_BINARY shk_BitAnd(const SHK_BINARY bin1, const SHK_BINARY bin2)
{
    static char result[0x100];
    if(shk_strlen(bin1) != shk_strlen(bin2))
        return "!NEQ";
    for(int i = 0; i <= 0x100; ++i)
    {
        if(bin1[i] < 48 || bin2[i] < 48 || bin1[i] > 49 || bin2[i] > 49)
            return "!NOB";
        if(bin1[i] == bin2[i])
            result[i] = '1';
        else
            result[i] = '0';
    }
    return result;
}