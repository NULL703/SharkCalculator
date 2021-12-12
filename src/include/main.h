/************************************************************************
主程序函数声明.
Copyright (C) 2021 NULL_703. All rights reserved.
Created on 2021.10.8  12:32
Created by NULL_703
Last change time on 2021.12.6  15:29
************************************************************************/
#ifndef SHARKCALCULATOR_MAIN_H
#define SHARKCALCILATOR_MAIN_H

#include "formulas.h"
#include "calculate.h"
#include "incs.h"

//-->TODO下面定义将在下个版本正式投入使用
static double results[255];
static int resultsIndex = 0;
static SHK_BOOL storageModeSwitch = SHK_FALSE;
enum option{nor, formula, help, bhelp, basic};
//<--end

int basicCalculate();
enum calc calcOper(char oper);
void mainFunc(int flag);
int commandProc();
void normalCalc();

#endif     //SHARKCALCULATOR_MAIN_H