/************************************************************************
文件操作模块的函数声明。
Copyright (C) 2021 NULL_703. All rights reserved.
Created on 2021.12.24  13:41
Created by NULL_703
Last change time on 2021.12.31  12:50
************************************************************************/
#ifndef SHARKCALCULATOR_FILEOPT_H
#define SHARKCALCULATOR_FILEOPT_H

#include "incs.h"

void configLog(int flag, int line, const char* fileName, const char* funcName);
void deleteFile(const char* filename);

#endif     //SHARKCALCULATOR_FILEOPT_H