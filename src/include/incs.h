/************************************************************************
包含项目所需要的头文件。
Copyright (C) 2021-2022 NULL_703. All rights reserved.
Created on 2021.10.7  17:32
Created by NULL_703
Last change time on 2022.3.6  12:18
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
#include <unistd.h>
#include "Colors.h"
#include "logtexts.h"
#include "formulas.h"
//程序文本默认为英文，若要使用中文版则在此头文件的开头添加宏定义“#define zh_CN”或在编译器选项中添加“zh_CN”的宏定义
#ifndef zh_CN
    #include "texts.h"
    #define versioninfo "shcalc V1.0.2 release version.\n"\
        "This software is open source software, shcalc and libformula of source code use MIT licence.\n"\
        "Project address: https://github.com/NULL_703/SharkCalculator \n"\
        "Author: NULL_703 <wangsonglin703@163.com>\n"
#else
    #include "text_zh_CN.h"
    #define versioninfo "shcalc V1.0.2 release version.\n"\
        "此软件是开放源代码软件，shcalc和libformula的源代码使用MIT许可证。\n"\
        "项目地址：https://github.com/NULL_703/SharkCalculator \n"\
        "作者: NULL_703 <wangsonglin703@163.com>\n"
#endif

using namespace std;

#ifdef __WIN32
    #include <windows.h>
#endif

#endif     //SHARKCALCULATOR_INCS_H