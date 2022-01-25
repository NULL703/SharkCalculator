/************************************************************************
公式库的物理公式（组）的实现。
Copyright (C) 2021-2022 NULL_703. All rights reserved.
Created on 2021.12.23  8:08
Created by NULL_703
Last change time on 2022.1.1  22:05
************************************************************************/
#include "include/phyformula.h"

/*---------------------------------------------------------------------*/

double shk_joule(double i, double r, double t)
{
    return shk_pow(i, 2) * r * t;
}

/*---------------------------------------------------------------------*/

double shk_pgshc(double cap, double mes, double delta_temi0, double delta_temi, int q_type)
{
    double delta_tem;
    if(q_type == 0)     //放热
        delta_tem = delta_temi0 - delta_temi;
    else if(q_type == 1)     //吸热
        delta_tem = delta_temi - delta_temi0;
    else
        return -0xffff;
    return cap * mes * delta_tem;
}

/*---------------------------------------------------------------------*/
