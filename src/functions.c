/************************************************************************
公式库附属的专用函数。
Copyright (C) 2021-2022 NULL_703. All rights reserved.
Created on 2021.11.4  19:31
Created by NULL_703
Last change time on 2022.5.22  19:14
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

double shk_musqrt(double x, double y)
{
    double temp = x;
    double result;
    if(x == 0)
        return 0;
    if(x <= 0 && shk_IsOdd(y) == SHK_FALSE)
        return NAN;
    result = ((y - 1) * temp / y) + (x / (pow(temp, y - 1) * y));
    while(shk_abs(result - temp) > 1e-8)
    {
        temp = result;
        result = ((y - 1) * temp / y) + (x / (pow(temp, y - 1) * y));
    }
    return result;
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
    return pow(M_E, x);
}

int shk_strlen(const char* s)
{
    const char *sc;
    for(sc = s; *sc; ++sc){;}
    return sc - s;
}

SHK_BOOL shk_IsOdd(int x)
{
    return (shk_mod(x, 2) == 0) ? SHK_FALSE : SHK_TRUE;
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
    for(result = 1; stdNum < x; result++)
        stdNum *= 10;
    return result;
}

int shk_mod(int x, int y)
{
    return x - ((int)(x / y) * y);
}

SHK_BOOL shk_IsStrNum(const char* num, SHK_BOOL intMode)
{
    int count = shk_strlen(num);
    SHK_BOOL decPoint = SHK_FALSE;
    for(int i = 0; i < count; i++)
    {
        if(num[i] > 57 || num[i] < 48)
        {
            if(num[i] == '-' && i == 0) continue;    //负数只需要检测到第一个字符为'-'号即可
            if(intMode == SHK_TRUE)
                return SHK_FALSE;
            else{
                if(num[i] != '.')
                    return SHK_FALSE;
                if(num[i] == '.' && decPoint == SHK_FALSE)    //小数点只能出现一次
                    decPoint = SHK_TRUE;
            }
        }
    }
    return SHK_TRUE;
}

int shk_AsciiToNum(const char* number)
{
    int numBit = 0;
    int result = 0;
    SHK_BOOL nav = SHK_FALSE;
    numBit = shk_strlen(number);
    if(numBit >= 10 || shk_IsStrNum(number, SHK_TRUE) == SHK_FALSE)
        return NAN;
    for(int i = 0; i < numBit; i++)
    {
        if(number[i] == 45 && i == 0)
        {
            nav = SHK_TRUE;
            continue;
        }
        result += (number[i] - 48) * (shk_pow(10, numBit - i) / 10);
    }
    if(nav == SHK_TRUE) return -result;
    return result;
}

char* shk_NumToAscii(int number)
{
    static char result[10];
    int temp = number;
    int index = 0;
    if(shk_NumberLevel(number) > 9)
        return NOTEQUAL;
    for(int i = index; i < 9; ++i, index = i)
    {
        if(i == shk_NumberLevel(number))
            break;
        result[i] = shk_mod(temp, 10) + 48;
        temp /= 10;
    }
    if(number < 0)
        result[index] = 45;
    return shk_StrInvert(result);
}

int shk_adder(int min, int max)
{
    int result = min;
    for(int i = 0; i < max - min; i++)
        result += min + (i + 1);
    return result;
}

char* shk_StrInvert(const char* str)
{
    int charCount = shk_strlen(str);
    if(charCount > 0xffff)
        return STRTOOLONG;
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
            return BITTOOLONG;
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
            return NAN;
    }
    return result;
}

SHK_BINARY shk_BitCalc(const SHK_BINARY bin1, const SHK_BINARY bin2, int calcMode)
{
    static char result[0x100];
    if((shk_strlen(bin1) != shk_strlen(bin2)) || shk_strlen(bin1) > 0x100 || shk_strlen(bin2) > 0x100)
        return NOTEQUAL;
    for(int i = 0; i <= 0x100; ++i)
    {
        if((int)bin1[i] < 48 || (int)bin2[i] < 48 || (int)bin1[i] > 49 || (int)bin2[i] > 49)
            return result;
        if(calcMode == 0)     //与运算
        {
            if(bin1[i] == '1' && bin2[i] == '1')
                result[i] = '1';
            else
                result[i] = '0';
        }else if(calcMode == 1){     //或运算
            if(bin1[i] == '1' || bin2[i] == '1')
                result[i] = '1';
            else
                result[i] = '0';
        }else
            return OPTIONERR;
    }
    return result;
}

SHK_BINARY shk_BitAnd(const SHK_BINARY bin1, const SHK_BINARY bin2)
{
    return shk_BitCalc(bin1, bin2, 0);
}

SHK_BINARY shk_BitOr(const SHK_BINARY bin1, const SHK_BINARY bin2)
{
    return shk_BitCalc(bin1, bin2, 1);
}

SHK_BINARY shk_BitNot(const SHK_BINARY bin)
{
    static char result[0x100];
    if(shk_strlen(bin) > 0x100)
        return NOTEQUAL;
    for(int i = 0; i <= 0x100; ++i)
    {
        if((int)bin[i] < 48 || (int)bin[i] > 49)
            return result;
        if(bin[i] == '1')
            result[i] = '0';
        else
            result[i] = '1';
    }
    return result;
}

double shk_frac(SHK_FRACTION x)
{
    if((int)x.numerator == 0)
        return NAN;
    return x.numerator / x.denominator;
}

SHK_BOOL shk_InRange(double max, double min, double objValue, SHK_BOOL openRange)
{
    if(openRange == SHK_TRUE)
    {
        if(objValue < max && objValue > min)
            return SHK_TRUE;
        else
            return SHK_FALSE;
    }else{
        if(objValue <= max && objValue >= min)
            return SHK_TRUE;
        else
            return SHK_FALSE;
    }
}

double shk_cot(double x)
{
    /* This function follow formula: cot = cos(x) / sin(x) */
    return cos(x) / sin(x);
}

double shk_csc(double x)
{
    /* This function follow formula: csc = 1 / sin(x) */
    return 1.0 / sin(x);
}

double shk_sec(double x)
{
    /* This function follow formula: sec = 1 / cos(x) */
    return 1.0 / cos(x);
}

double shk_fmod(double x, double y)
{
    double fm = x;
    while(fm > y) fm -= y;
    return fm;
}

SHK_BOOL shk_incscmp(const char* incstr, const char* str)
{
    for(int i = 0; incstr[i] != '\0'; i++)
        if(incstr[i] != str[i]) return SHK_FALSE;
    return SHK_TRUE;
}