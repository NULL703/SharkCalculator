/************************************************************************
formulas.c的函数声明。
Copyright (C) 2021-2022 NULL_703. All rights reserved.
Created on 2021.10.7  21:39
Created by NULL_703
Last change time on 2022.4.1  6:58
************************************************************************/
#ifndef LIBFORMULA_FORMULAS_H
#define LIBFORMULA_FORMULAS_H

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*FirstProcess:预处理部分
*定义自定义变量类型及其他处理
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include "functions.h"
#include "defvar.h"     //类型、常量定义位于defvar.h中。

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
//点到直线的距离公式
double PTL(double epA, double epB, double epC, double x, double y);
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
//极坐标系中两点间距离的计算公式
double shk_spaPTPF(SHK_SOPCA addr1, SHK_SOPCA addr2);
/*---------------------------------------------------------------------*/
//平面直角坐标系中点的平移坐标变换(函数组主函数)
SHK_PRACSA shk_CoorSysPan(SHK_PRACSA objAddr, SHK_PRACSA newOrigPointAddr, int calcMode);
//求平移前的坐标(函数组引导函数)
SHK_PRACSA shk_GetOldPoint_Pan(SHK_PRACSA newAddr, SHK_PRACSA newOrigPointAddr);
//求平移后的坐标(函数组引导函数)
SHK_PRACSA shk_GetNewPoint_Pan(SHK_PRACSA oldAddr, SHK_PRACSA newOrigPointAddr);
/*---------------------------------------------------------------------*/
//平面直角坐标系中点的旋转变换(函数组主函数)
SHK_PRACSA shk_CoorSysRev(SHK_PRACSA objAddr, double angle, int calcMode);
//求旋转前的坐标(函数组引导函数)
SHK_PRACSA shk_GetOldPoint_Rev(SHK_PRACSA newAddr, double angle);
//求旋转后的坐标(函数组引导函数)
SHK_PRACSA shk_GetNewPoint_Rev(SHK_PRACSA oldAddr, double angle);
/*---------------------------------------------------------------------*/
//平面直角坐标系中点的一般变换(函数组主函数)
SHK_PRACSA shk_CoorSysNormalChange(SHK_PRACSA objAddr, SHK_PRACSA newOrigPointAddr, double angle,
                                int calcMode);
//求原坐标(函数组引导函数)
SHK_PRACSA shk_GetOldPoint_NC(SHK_PRACSA newAddr, SHK_PRACSA newOrigPointAddr, double angle);
//求新坐标(函数组引导函数)
SHK_PRACSA shk_GetNewPoint_NC(SHK_PRACSA oldAddr, SHK_PRACSA newOrigPointAddr, double angle);
/*---------------------------------------------------------------------*/
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