/************************************************************************
公式库的向量函数。
Copyright (C) 2022 NULL_703. All rights reserved.
Created on 2022.4.23  11:24
Created by NULL_703
Last change time on 2022.5.21  19:08
************************************************************************/
#include "include/shvector.h"

SHK_PRACSA shk_covecas(SHK_PRACSA cooradd1, SHK_PRACSA cooradd2, int calcMode)
{
    SHK_PRACSA result;
    switch(calcMode)
    {
        case 0: {
            result.x = cooradd1.x + cooradd2.x;
            result.y = cooradd1.y + cooradd2.y;
            break;
        }
        case 1: {
            result.x = cooradd1.x - cooradd2.x;
            result.y = cooradd1.y - cooradd2.y;
            break;
        }
    }
    return result;
}

SHK_PRACSA shk_covecadd(SHK_PRACSA cooradd1, SHK_PRACSA cooradd2)
{
    return shk_covecas(cooradd1, cooradd2, 0);
}

SHK_PRACSA shk_covecsub(SHK_PRACSA cooradd1, SHK_PRACSA cooradd2)
{
    return shk_covecas(cooradd1, cooradd2, 1);
}

SHK_PRACSA shk_covecnmul(SHK_PRACSA cooradd, double mulnum)
{
    SHK_PRACSA result = {
        cooradd.x * mulnum, cooradd.y * mulnum
    };
    return result;
}

SHK_BOOL shk_isparcrvec(SHK_PRACSA coorvec1, SHK_PRACSA coorvec2)
{
    double t = 0.0;
    t = (coorvec1.x * coorvec2.y) - (coorvec1.y * coorvec2.x);
    if(t != 0) return SHK_FALSE;
    return SHK_TRUE;
}

SHK_BOOL shk_ispercrvec(SHK_PRACSA coorvec1, SHK_PRACSA coorvec2)
{
    double t = 0.0;
    t = (coorvec1.x * coorvec2.x) + (coorvec1.y * coorvec2.y);
    if(t != 0) return SHK_FALSE;
    return SHK_TRUE;
}