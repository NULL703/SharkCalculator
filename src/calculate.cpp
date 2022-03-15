/************************************************************************
基本计算方法。
Copyright (C) 2021-2022 NULL_703. All rights reserved.
Created on 2021.11.29  16:17
Created by NULL_703
Last change time on 2022.3.6  11:46
************************************************************************/
#include "include/calculate.h"

#define calcoptCount 11
char calcopt[calcoptCount][0x14] = {
    "-abs", "-pow", "-ang2rad", "-add", "-sub", "-mul", "-div", "-dectobin",
    "-bintodec", "-sqrt", "-musqrt"
};

int optMatch(const char* opt)
{
    int optindex = 0;
    while(optindex != 15)
    {
        if(strcmp(opt, calcopt[optindex]) == 0) break;
        optindex++;
    }
    return optindex;
}

void formulaErrno(int count, const char**argv)
{
    for(int i = 1; i <= count; ++i)
    {
        if(argv[i] == NULL)
        {
            printf("%s%s%s", F_RED, w0006, NORMAL);
            configLog(6, __LINE__, __FILE__, __FUNCTION__);
            exit(1);
        }
    }
}

void immediateCalculate(int argc, const char** argv)
{
    switch(optMatch(argv[1]))
    {
        //abs
        case 0: {
            formulaErrno(2, argv);
            printf("%s%f\n", w0015, shk_abs(atof(argv[2])));
            break;
        }
        //pow
        case 1: {
            formulaErrno(3, argv);
            printf("%s%f\n", w0015, shk_pow(atof(argv[2]), atof(argv[3])));
            break;
        }
        //ang2rad
        case 2: {
            formulaErrno(2, argv);
            printf("%s%f\n", w0015, shk_ang2rad(atof(argv[2])));
            break;
        }
        //add
        case 3: {
            formulaErrno(3, argv);
            printf("%s%f\n", w0015, calcTypeProc(cadd, atof(argv[2]), atof(argv[3])));
            break;
        }
        //sub
        case 4: {
            formulaErrno(3, argv);
            printf("%s%f\n", w0015, calcTypeProc(csub, atof(argv[2]), atof(argv[3])));
            break;
        }
        //mul
        case 5: {
            formulaErrno(3, argv);
            printf("%s%f\n", w0015, calcTypeProc(cmul, atof(argv[2]), atof(argv[3])));
            break;
        }
        //div
        case 6: {
            formulaErrno(3, argv);
            printf("%s%f\n", w0015, calcTypeProc(cdiv, atof(argv[2]), atof(argv[3])));
            break;
        }
        //dectobin
        case 7: {
            formulaErrno(2, argv);
            printf("%s%s\n", w0015, shk_DecToBin(atof(argv[2])));
            break;
        }
        //bintodec
        case 8: {
            formulaErrno(2, argv);
            printf("%s%d\n", w0015, shk_BinToDec(argv[2]));
            break;
        }
        //sqrt
        case 9: {
            formulaErrno(2, argv);
            printf("%s%.6f\n", w0015, calcTypeProc(csqrt, atof(argv[2]), 0));
            break;
        }
        //musqrt
        case 10: {
            formulaErrno(3, argv);
            printf("%s%.6f\n", w0015, calcTypeProc(cmusqrt, atof(argv[2]), atof(argv[3])));
            break;
        }
        default: {
#ifdef __WIN32
            system("cls");
#endif
            printf("%s%s%s", F_RED, w0016, NORMAL);
            configLog(-1, __LINE__, __FILE__, __FUNCTION__);
        }
    }
    configLog(0, __LINE__, __FILE__, __FUNCTION__);
    exit(0);
}

double calcTypeProc(enum calc calcType, double x, double y)
{
    switch(calcType)
    {
        case cadd: {
            return add(x, y);
            break;
        }
        case csub: {
            return sub(x, y);
            break;
        }
        case cmul: {
            return mul(x, y);
            break;
        }
        case cdiv: {
            return div(x, y);
            break;
        }
        case csqrt: {
            return shk_sqrt(x);
            break;
        }
        case cmusqrt: {
            return shk_musqrt(x, y);
            break;
        }
        default: {
            printf("%s%s%s", F_RED, w0016, NORMAL);
            return -0xffff;
        }
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