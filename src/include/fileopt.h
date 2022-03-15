/************************************************************************
文件操作模块的函数声明。
Copyright (C) 2021-2022 NULL_703. All rights reserved.
Created on 2021.12.24  13:41
Created by NULL_703
Last change time on 2022.2.26  13:18
************************************************************************/
#ifndef SHARKCALCULATOR_FILEOPT_H
#define SHARKCALCULATOR_FILEOPT_H

#include "incs.h"

#define defaultFileName "Output.txt"
#ifdef __WIN32
    #define access _access
#endif

void configLog(int flag, int line, const char* fileName, const char* funcName);
void deleteFile();
void saveResult();

#endif     //SHARKCALCULATOR_FILEOPT_H