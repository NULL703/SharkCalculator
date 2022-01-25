/************************************************************************
主程序函数声明.
Copyright (C) 2021-2022 NULL_703. All rights reserved.
Created on 2021.10.8  12:32
Created by NULL_703
Last change time on 2022.1.12  8:12
************************************************************************/
#ifndef SHARKCALCULATOR_MAIN_H
#define SHARKCALCULATOR_MAIN_H

#include "calculate.h"
#include "incs.h"

int basicCalculate();
enum calc calcOper(char oper);
void commandProc();
void normalCalc();
class resultLookup{
public:
    void selectLookupMode();
    double getResult(int index);
    void showAllResult(int maxResultNumber);
private:
    int showErrorInfo();
    void showStorageStatus();
};
#endif     //SHARKCALCULATOR_MAIN_H