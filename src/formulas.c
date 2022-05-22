/************************************************************************
各种公式的算法(公式库核心部分)。
Copyright (C) 2021-2022 NULL_703. All rights reserved.
Created on 2021.10.7  17:39
Created by NULL_703
Last change time on 2022.5.22  19:21
************************************************************************/
#include "include/formulas.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

double ASCF(double term1, int term_num, double cd)
{
    return term1 + (term_num - 1) * cd;
}

double GSCF(double term1, int term_num, double cr)
{
    return term1 * shk_pow(cr, term_num - 1);
}

double PTPF(double x1, double x2, double y1, double y2)
{
    return sqrt(shk_pow((x2 - x1), 2) + shk_pow((y2 - y1), 2));
}

double shk_mip(double x1, double x2)
{
    return (x1 + x2) / 2;
}

double CRS(double r)
{
    return M_PI * shk_pow(r, 2);
}

double CRC(double r)
{
    return 2 * M_PI * r;
}

double SHV(double r)
{
    return (4 / 3) * M_PI * shk_pow(r, 3);
}

double SHS(double r)
{
    return 4 * M_PI * shk_pow(r, 2);
}

double CLEV(double sh, double ht)
{
    return (1 / 3) * sh * ht;
}

double CLEFS(double r, double l)
{
    return M_PI * r * (r + l);
}

double CLCRV(double r, double h)
{
    return M_PI * shk_pow(r, 2) * h;
}

double CLCRS(double r, double l)
{
    return 2 * M_PI * r * (r + l);
}

double shk_randf(double max, double min)
{
    srand(time(NULL));
    return min + (double)(rand()) / 0x7fff * (max - (min));
}

int shk_rand(int max, int min)
{
    srand((unsigned)(time(NULL)));
    return rand()%(max - min + 1) + min;
}

double shk_EarthDistance(double lng1, double lng2, double lat1, double lat2)
{
    double Earth_r = 6371.0;
    double tmp;
    double result;
    double dLng = (lng2 - lng1) * M_PI / 180;
    double dLat = (lat2 - lat1) * M_PI / 180;
    lat1 = lat1 * M_PI / 180;
    lat2 = lat2 * M_PI / 180;
    tmp = sin(dLat / 2) * sin(dLat / 2) + cos(lat1) * cos(lat2) * sin(dLng / 2) * sin(dLng / 2);
    result = 2 *Earth_r * asin(sqrt(tmp));
    return result;
}

double shk_sqrt(double num)
{
    double temp = 0.0;
    double result = 1.0;
    if(num <= 0)
        return 0;
    while(result != temp)
    {
        temp = result;
        result = (result + num / result) / 2;
    }
    return result;
}

double shk_gradient(double x1, double x2, double y1, double y2)
{
    double k;
    if(x1 == x2)
    {
        return NAN;
    }else{
        k = (y2 - y1) / (x2 - x1);
    }
    return k;
}

long shk_perm(int tpn, int lwn)
{
    if(lwn > 10)
        return NAN;
    long result = 1;
    for(; lwn > 0; lwn--)
    {
        result *= tpn;
        tpn--;
    }
    return result;
}

long shk_fact(int num)
{
    long result = shk_perm(num, num);
    return result;
}

double shk_avg(double* datas, int term)
{
    double result;
    double temp = 0;
    for(int i = term; i >= 0; i--)
        temp += datas[i];
    result = temp / term;
    return result;
}

double shk_deviation(double* datas, double mean, int term)
{
    double temp = 0;
    double result;
    for(int i = term; i >= 0; i--)
    {
        temp += shk_pow(datas[i] - mean, 2);
    }
    result = (1.0 / term) * temp;
    return result;
}

double shk_RootDeviantion(double* datas, double mean, int term)
{
    return shk_sqrt(shk_deviation(datas, mean, term));
}

double PTL(double epA, double epB, double epC, double x, double y)
{
    double temp1;
    double temp2;
    double result;
    temp1 = shk_abs(epA * x + epB * y + epC);
    temp2 = shk_pow(epA, 2) + shk_pow(epB, 2);
    result = temp1 / sqrt(temp2);
    return result;
}

int shk_FibonacciSON(int n)
{
    if(n <= 0)
        return NAN;
    double result;
    double t1 = 1 / sqrt(5);
    double t2 = ((1 + sqrt(5)) / 2);
    double t3 = ((1 - sqrt(5)) / 2);
    result = t1 * (shk_pow(t2, n) - shk_pow(t3, n));
    return (int)result;
}

double** shk_MatrixAdd(double *InputExpr1, double *InputExpr2, int row, int col)
{
    //start-->初始化最终的矩阵，动态分配最终结果的变量内存
    double** result = (double**)malloc(row * sizeof(double));
    for(int k = 0; k < col; ++k)
        result[k] = (double*)malloc(col * sizeof(double));
    //<--end
    int count = 0;
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            result[i][j] = InputExpr1[count] + InputExpr2[count];
            count++;
        }
    }
    return result;
}

double** shk_MatrixSub(double *InputExpr1, double *InputExpr2, int row, int col)
{
    //start-->初始化最终的矩阵，动态分配最终结果的变量内存
    double** result = (double**)malloc(row * sizeof(double));
    for(int k = 0; k < col; ++k)
        result[k] = (double*)malloc(col * sizeof(double));
    //<--end
    int count = 0;
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            result[i][j] = InputExpr1[count] - InputExpr2[count];
            count++;
        }
    }
    return result;
}

double shk_spaPTPF(SHK_SOPCA addr1, SHK_SOPCA addr2)
{
    double result;
    result = shk_sqrt(shk_pow(addr1.rho, 2) + shk_pow(addr2.rho, 2));
    result -= 2 * addr1.rho * addr2.rho * cos(addr1.theta - addr2.theta);
    return result;
}

SHK_PRACSA shk_CoorSysPan(SHK_PRACSA objAddr, SHK_PRACSA newOrigPointAddr, int calcMode)
{
    SHK_PRACSA result;
    switch(calcMode)
    {
        //某点在平面直角坐标系中平移，已知平移后的坐标和平移后点O的新坐标，求该点的原坐标
        case 0: {
            result.x = objAddr.x + newOrigPointAddr.x;
            result.y = objAddr.y + newOrigPointAddr.y;
            break;
        }
        //某点在平面直角坐标系中平移，已知该点原先的坐标和平移后点O的新坐标，求平移后该点的坐标
        case 1: {
            result.x = objAddr.x - newOrigPointAddr.x;
            result.y = objAddr.y - newOrigPointAddr.y;
            break;
        }
    }
    return result;
}

SHK_PRACSA shk_GetOldPoint_Pan(SHK_PRACSA newAddr, SHK_PRACSA newOrigPointAddr)
{
    return shk_CoorSysPan(newAddr, newOrigPointAddr, 0);
}

SHK_PRACSA shk_GetNewPoint_Pan(SHK_PRACSA oldAddr, SHK_PRACSA newOrigPointAddr)
{
    return shk_CoorSysPan(oldAddr, newOrigPointAddr, 1);
}

SHK_PRACSA shk_CoorSysRev(SHK_PRACSA objAddr, double angle, int calcMode)
{
    SHK_PRACSA result;
    switch(calcMode)
    {
        //求旋转前该点的坐标
        case 0: {
            result.x = objAddr.x * cos(angle) - objAddr.y * sin(angle);
            result.y = objAddr.x * sin(angle) + objAddr.y * cos(angle);
            break;
        }
        //求旋转后该点的坐标
        case 1: {
            result.x = objAddr.x * cos(angle) + objAddr.y * sin(angle);
            result.y = -objAddr.x * sin(angle) + objAddr.y * cos(angle);
            break;
        }
    }
    return result;
}

SHK_PRACSA shk_GetOldPoint_Rev(SHK_PRACSA newAddr, double angle)
{
    return shk_CoorSysRev(newAddr, angle, 0);
}

SHK_PRACSA shk_GetNewPoint_Rev(SHK_PRACSA oldAddr, double angle)
{
    return shk_CoorSysRev(oldAddr, angle, 1);
}

SHK_PRACSA shk_CoorSysNormalChange(SHK_PRACSA objAddr, SHK_PRACSA newOrigPointAddr, double angle,
                                int calcMode)
{
    SHK_PRACSA result;
    double temp = 0.0;
    switch(calcMode)
    {
        //求原坐标
        case 0: {
            result.x = objAddr.x * cos(angle) - objAddr.y * sin(angle) + newOrigPointAddr.x;
            result.y = objAddr.x * sin(angle) + objAddr.y * cos(angle) + newOrigPointAddr.y;
            break;
        }
        //求新坐标
        case 1: {
            temp = (objAddr.x - newOrigPointAddr.x) * cos(angle);
            result.x = temp + (objAddr.x - newOrigPointAddr.y) * sin(angle);
            //刷新临时变量为第二个临时变量的值
            temp = -(objAddr.x - newOrigPointAddr.x) * sin(angle);
            result.y = temp + (objAddr.y - newOrigPointAddr.y) * cos(angle);
            break;
        }
    }
    return result;
}

SHK_PRACSA shk_GetOldPoint_NC(SHK_PRACSA newAddr, SHK_PRACSA newOrigPointAddr, double angle)
{
    return shk_CoorSysNormalChange(newAddr, newOrigPointAddr, angle, 0);
}

SHK_PRACSA shk_GetNewPoint_NC(SHK_PRACSA oldAddr, SHK_PRACSA newOrigPointAddr, double angle)
{
    return shk_CoorSysNormalChange(oldAddr, newOrigPointAddr, angle, 1);
}