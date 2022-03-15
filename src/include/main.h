/************************************************************************
主程序函数声明.
Copyright (C) 2021-2022 NULL_703. All rights reserved.
Created on 2021.10.8  12:32
Created by NULL_703
Last change time on 2022.2.23  15:32
************************************************************************/
#ifndef SHARKCALCULATOR_MAIN_H
#define SHARKCALCULATOR_MAIN_H

#include "calculate.h"
#include "fileopt.h"
#include "incs.h"

static double results[255];    //存储池最大数据量为255
static int resultsIndex = 0;    //存储池数据写入的指针位置(存储池数据索引最大值)
static SHK_BOOL storageModeSwitch = SHK_FALSE;    //存储模式状态

SHK_BOOL getStorageStatus();    //刷新为来自主线程的存储池状态
int getResultsIndex();    //刷新为来自主线程的存储池索引指针
double getResultsValue(int index);    //刷新为来自主线程的存储池数据
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