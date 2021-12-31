/************************************************************************
公式库的物理公式（组）的实现。
Copyright (C) 2021 NULL_703. All rights reserved.
Created on 2021.12.23  8:08
Created by NULL_703
Last change time on 2021.12.23  8:19
************************************************************************/
#include "include/phyformula.h"

double shk_joule(double i, double r, double t)
{
    return shk_pow(i, 2) * r * t;
}