/************************************************************************
基本计算方法的声明。
Copyright (C) 2021 NULL_703. All rights reserved.
Created on 2021.11.29  16:19
Created by NULL_703
Last change time on 2021.12.16  17:51
************************************************************************/
#ifndef SHARKCALCULATOR_CALCULATE_H
#define SHARKCALCULATOR_CALCULATE_H

#include "incs.h"

enum calc{cadd, csub, cmul, cdiv, err};

void immediateCalculate(int argc, const char** argv);
double calcTypeProc(enum calc calctype, double x, double y);
double add(double x, double y);
double sub(double x, double y);
double mul(double x, double y);
double div(double x, double y);

#endif     //SHARKCALCULATOR_CALCULATE_H