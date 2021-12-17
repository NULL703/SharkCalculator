/************************************************************************
主程序函数声明.
Copyright (C) 2021 NULL_703. All rights reserved.
Created on 2021.10.8  12:32
Created by NULL_703
Last change time on 2021.12.15  12:53
************************************************************************/
#ifndef SHARKCALCULATOR_MAIN_H
#define SHARKCALCILATOR_MAIN_H

#include "calculate.h"
#include "incs.h"

void configLog(int flag, int line, const char* fileName, const char* funcName);
int basicCalculate();
enum calc calcOper(char oper);
void commandProc();
void normalCalc();

#endif     //SHARKCALCULATOR_MAIN_H