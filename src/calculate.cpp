/************************************************************************
基本计算方法。
Copyright (C) 2021 NULL_703. All rights reserved.
Created on 2021.11.29  16:17
Created by NULL_703
Last change time on 2021.12.4  19:50
************************************************************************/
#include "include/calculate.h"
#include "include/fileopt.h"
#include "include/main.h"

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
    if(argc > 1 && (strcmp(argv[1], "-abs") == 0))
    {
        formulaErrno(2, argv);
        printf("%s%f", w0015, shk_abs(atof(argv[2])));
    }else if(argc > 1 && (strcmp(argv[1], "-pow") == 0)){
        formulaErrno(3, argv);
        printf("%s%f", w0015, shk_pow(atof(argv[2]), atof(argv[3])));
    }else if(argc > 1 && (strcmp(argv[1], "-ang2rad") == 0)){
        formulaErrno(2, argv);
        printf("%s%f", w0015, shk_ang2rad(atof(argv[2])));
    }else if(argc > 1 && (strcmp(argv[1], "-add") == 0)){
        formulaErrno(3, argv);
        printf("%s%f", w0015, calcTypeProc(cadd, atof(argv[2]), atof(argv[3])));
    }else if(argc > 1 && (strcmp(argv[1], "-sub") == 0)){
        formulaErrno(3, argv);
        printf("%s%f", w0015, calcTypeProc(csub, atof(argv[2]), atof(argv[3])));
    }else if(argc > 1 && (strcmp(argv[1], "-mul") == 0)){
        formulaErrno(3, argv);
        printf("%s%f", w0015, calcTypeProc(cmul, atof(argv[2]), atof(argv[3])));
    }else if(argc > 1 && (strcmp(argv[1], "-div") == 0)){
        formulaErrno(3, argv);
        printf("%s%f", w0015, calcTypeProc(cdiv, atof(argv[2]), atof(argv[3])));
    }else if(argc > 1 && (strcmp(argv[1], "-dectobin") == 0)){
        formulaErrno(2, argv);
        printf("%s%s", w0015, shk_DecToBin(atof(argv[2])));
    }else if(argc > 1 && (strcmp(argv[1], "-bintodec") == 0)){
        formulaErrno(2, argv);
        printf("%s%d", w0015, shk_BinToDec(argv[2]));
    }else{
        printf("%s%s%s", F_RED, w0016, NORMAL);
        configLog(-1, __LINE__, __FILE__, __FUNCTION__);
    }
    configLog(0, __LINE__, __FILE__, __FUNCTION__);
    exit(0);
}

double calcTypeProc(enum calc calcType, double x, double y)
{
    switch(calcType)
    {
        case cadd:
        {
            return add(x, y);
            break;
        }
        case csub:
        {
            return sub(x, y);
            break;
        }
        case cmul:
        {
            return mul(x, y);
            break;
        }
        case cdiv:
        {
            return div(x, y);
            break;
        }
        default:
        {
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