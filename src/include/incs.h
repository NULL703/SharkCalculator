/************************************************************************
包含项目所需要的头文件。
Copyright (C) 2021 NULL_703. All rights reserved.
Created on 2021.10.7  17:32
Created by NULL_703
Last change time on 2021.12.15  12:51
************************************************************************/
#ifndef SHARKCALCULATOR_INCS_H
#define SHARKCALCULATOR_INCS_H

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string>
#include <cstring>
#include <list>
#include <stack>
#include "Colors.h"
#include "logtexts.h"
#include "formulas.h"
//程序文本默认为英文，若要使用中文版则在此头文件的开头添加宏定义“#define zh_CN”或在编译器选项中添加“zh_CN”的宏定义
#ifndef zh_CN
    #include "texts.h"
#else
    #include "text_zh_CN.h"
#endif

using namespace std;

#ifdef __WIN32
    #include <windows.h>
#endif

#endif     //SHARKCALCULATOR_INCS_H