/************************************************************************
公式库附属的专用函数的声明。
Copyright (C) 2021-2022 NULL_703. All rights reserved.
Created on 2021.11.4  19:33
Created by NULL_703
Last change time on 2022.2.16  21:04
************************************************************************/
#ifndef LIBFORMULA_FUNCTIONS_H
#define LIBFORMULA_FUNCTIONS_H

#include "defvar.h"

//常用的常数定义
#if (!defined (M_PI) || defined (USE_MATHCONST))
#define M_E        2.71828182845904523536   // e
#define M_LOG2E    1.44269504088896340736   // log2(e)
#define M_LOG10E   0.434294481903251827651  // log10(e)
#define M_LN2      0.693147180559945309417  // ln(2)
#define M_LN10     2.30258509299404568402   // ln(10)
#define M_PI       3.14159265358979323846   // pi
#define M_PI_2     1.57079632679489661923   // pi/2
#define M_PI_4     0.785398163397448309616  // pi/4
#define M_1_PI     0.318309886183790671538  // 1/pi
#define M_2_PI     0.636619772367581343076  // 2/pi
#define M_2_SQRTPI 1.12837916709551257390   // 2/sqrt(pi)
#define M_SQRT2    1.41421356237309504880   // sqrt(2)
#define M_SQRT1_2  0.707106781186547524401  // 1/sqrt(2)
#endif

#ifdef __cplusplus
extern "C"{
#endif
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*Math function.
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
//角度转弧度
double shk_ang2rad(double angle);
//绝对值
double shk_abs(double number);
//e的x次方
double shk_cexp(double x);
//x的y次幂
double shk_pow(double x, int y);
//奇数判断
SHK_BOOL shk_IsOdd(int x);
//判断一个浮点数是否为整数(即等于2.000000的形式)
SHK_BOOL shk_Isfint(double x);
//二次函数
double shk_QuadraticFunction(double x, double a, double b, double c);
//整数的数位级
int shk_NumberLevel(int x);
//取模运算
int shk_mod(int x, int y);
//计算x的y次方根
double shk_musqrt(double x, double y);
//累加函数
int shk_adder(int min, int max);
//分数转小数
double shk_frac(SHK_FRACTION x);
/*End of section.*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*Non math function.
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
//获取字符串大小
int shk_strlen(const char* s);
//判断字符串包含的是否是纯数字
SHK_BOOL shk_IsStrNum(const char* num, SHK_BOOL intMode);
//字符串转换为整数
int shk_AsciiToNum(const char* number);
//整数转换为字符串
char* shk_NumToAscii(int number);
//字符串倒置函数
char* shk_StrInvert(const char* str);
//十进制转换为二进制
SHK_BINARY shk_DecToBin(int decNum);
//二进制转换为十进制
int shk_BinToDec(const char* origbin);
/*---------------------------------------------------------------------*/
//二进制逻辑与、或运算(函数组主函数)
SHK_BINARY shk_BitCalc(const SHK_BINARY bin1, const SHK_BINARY bin2, int calcMode);
//二进制与运算(函数组引导函数)
SHK_BINARY shk_BitAnd(const SHK_BINARY bin1, const SHK_BINARY bin2);
//二进制或运算(函数组引导函数)
SHK_BINARY shk_BitOr(const SHK_BINARY bin1, const SHK_BINARY bin2);
/*---------------------------------------------------------------------*/
//二进制取反运算
SHK_BINARY shk_BitNot(const SHK_BINARY bin);
/*End of section.*/
#ifdef __cplusplus
}
#endif     //__cplusplus
#endif     //LIBFORMULA_FUNCTIONS_H