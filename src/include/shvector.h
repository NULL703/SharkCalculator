/************************************************************************
公式库的向量函数(标头文件)。
Copyright (C) 2022 NULL_703. All rights reserved.
Created on 2022.4.23  11:25
Created by NULL_703
Last change time on 2022.5.21  19:09
************************************************************************/
#ifndef LIBFORMULA_SHVERTOR_H
#define LIBFORMULA_SHVECTOR_H

#include "defvar.h"

#ifdef __cplusplus
extern "C"{
#endif

/*---------------------------------------------------------------------*/
//平面向量的坐标加、减运算(函数组主函数)
SHK_PRACSA shk_covecas(SHK_PRACSA cooradd1, SHK_PRACSA cooradd2, int calcMode);
//平面向量的坐标加运算(函数组引导函数)
SHK_PRACSA shk_covecadd(SHK_PRACSA cooradd1, SHK_PRACSA cooradd2);
//平面向量的坐标减运算(函数组引导函数)
SHK_PRACSA shk_covecsub(SHK_PRACSA cooradd1, SHK_PRACSA cooradd2);
/*---------------------------------------------------------------------*/
//平面向量的坐标数乘运算
SHK_PRACSA shk_covecnmul(SHK_PRACSA cooradd, double mulnum);
//判断两个向量是否平行
SHK_BOOL shk_isparcrvec(SHK_PRACSA coorvec1, SHK_PRACSA coorvec2);
//判断两个向量是否垂直
SHK_BOOL shk_ispercrvec(SHK_PRACSA coorvec1, SHK_PRACSA coorvec2);

#ifdef __cplusplus
}
#endif    //__cpluspplus
#endif    //LIBFORMULA_SHVECTOR_H