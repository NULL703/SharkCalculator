/************************************************************************
公式库的物理公式（组）的声明。
Copyright (C) 2021-2022 NULL_703. All rights reserved.
Created on 2021.12.23  8:05
Created by NULL_703
Last change time on 2022.1.3  11:02
************************************************************************/
#ifndef LIBFORMULA_PHYFORMULA_H
#define LIBFORMULA_PHYFORMULA_H

#include "defvar.h"
#include "functions.h"

#ifdef __cplusplus
extern "C"{
#endif

/*---------------------------------------------------------------------*/
//焦耳定律公式
double shk_joule(double i, double r, double t);
/*---------------------------------------------------------------------*/
//比热容公式
double shk_pgshc(double cap, double mes, double delta_temi0, double delta_temi, int q_type);

#ifdef __cplusplus
}
#endif     //__cplusplus
#endif     //LIBFORMULA_PHYFORMULA_H