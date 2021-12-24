/************************************************************************
formulas.c的函数声明。
Copyright (C) 2021 NULL_703. All rights reserved.
Created on 2021.10.7  21:39
Created by NULL_703
Last change time on 2021.12.24  9:23
************************************************************************/
#ifndef LIBFORMULA_FORMULAS_H
#define LIBFORMULA_FORMULAS_H

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*FirstProcess:预处理部分
*定义自定义变量类型及其他处理
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include "functions.h"
#include "defvar.h"     //定义代码位于defvar.h中。

/*End of section.*/

#ifdef __cplusplus
extern "C"{
#endif

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*Section1:数与代数，几何学基础公式
*包含基本的，常用的公式和函数
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
//等差数列通项公式
double ASCF(double term1, int term_num, double cd);
//等比数列通项公式
double GSCF(double term1, int term_num, double cr);
//两点的距离公式
double PTPF(double x1, double x2, double y1, double y2);
//中点公式
double shk_mip(double x1, double x2);
//圆的面积
double CRS(double r);
//圆的周长
double CRC(double r);
//球体体积
double SHV(double r);
//球体表面积
double SHS(double r);
//圆锥体积
double CLEV(double sh, double ht);
//圆锥表面积
double CLEFS(double r, double l);
//圆柱体积
double CLCRV(double r, double h);
//圆柱表面积
double CLCRS(double r, double l);
//浮点数随机函数
double shk_randf(double max, double min);
//整数随机函数
int shk_rand(int max, int min);
//平方根函数
double shk_sqrt(double num);
//斜率公式
double shk_gradient(double x1, double x2, double y1, double y2);
//平均数公式
double shk_avg(double* datas, int term);
//方差公式
double shk_deviation(double* datas, double mean, int term);
//标准差公式
double shk_RootDeviantion(double* datas, double mean, int term);
//斐波那契数列通项公式
int shk_FibonacciSON(int n);
/*End of section.*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*Section2:高等数学相关的公式和算法
*包含其他更具专业性的公式和函数（主要应用于科研或其他需要使用这些算法的领域）
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
//地球上任意两点间的距离公式（存在有0.5%左右的误差）
double shk_EarthDistance(double lng1, double lng2, double lat1, double lat2);
//矩阵的加法
double** shk_MatrixAdd(double *InputExpr1, double *InputExpr2, int row, int col);
//矩阵的减法
double** shk_MatrixSub(double *InputExpr1, double *InputExpr2, int row, int col);

/*End of section.*/
#ifdef __cplusplus
}
#endif     //__cpluspus
#endif     //LIBFORMULA_FORMULAS_H