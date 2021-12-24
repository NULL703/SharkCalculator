/************************************************************************
各种公式的算法(公式库)。
Copyright (C) 2021 NULL_703. All rights reserved.
Created on 2021.10.7  17:39
Created by NULL_703
Last change time on 2021.12.24  9:23
************************************************************************/
#include "include/formulas.h"
#include <stdlib.h>
#include <string.h>
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
    double Earth_r = 6371.00;
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
    double tmp = num;
    long double eps = 0.0000000001;
    double mid = tmp / 2;
    double min = 0.0;
    if(num < 0)
    {
        return -0xffff;
    }else{
        while((num - min) > eps)
        {
            if(mid * mid > tmp)
                num = mid;
            else
                min = mid;
            mid = (num + min) / 2;
        }
    }
    return mid;
}

double shk_gradient(double x1, double x2, double y1, double y2)
{
    double k;
    if(x1 == x2)
    {
        return -0xffff;
    }else{
        k = (y2 - y1) / (x2 - x1);
    }
    return k;
}

long shk_perm(int tpn, int lwn)
{
    if(lwn > 10)
        return -0xffff;
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
    return sqrt(shk_deviation(datas, mean, term));
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
        return -0xffff;
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