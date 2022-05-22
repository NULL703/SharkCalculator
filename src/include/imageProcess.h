/************************************************************************
公式库附属图像处理相关部分的标头文件。
Copyright (C) 2022 NULL_703. All rights reserved.
Created on 2022.3.11  7:47
Created by NULL_703
Last change time on 2022.4.17  9:52
************************************************************************/
#ifndef LIBFORMULA_IMAGEPROCESS_H
#define LIBFORMULA_IMAGEPROCESS_H

#include "defvar.h"

#ifdef __cplusplus
extern "C"{
#endif

//RGBA参数值检查
SHK_BOOL shk_rgbacheck(SHK_RGBAVALUE objValue);
//十六进制颜色值转换为RGBA形式
SHK_RGBAVALUE shk_HexcoToStd(SHK_BINARY hexColorValue);
//图像大小计算
int shk_imgsizeof(int imgheight, int imgwidth, int pixdep);

#ifdef __cplusplus
}
#endif    //__cplusplus
#endif    //LIBFORMULA_IMAGEPROCESS_H