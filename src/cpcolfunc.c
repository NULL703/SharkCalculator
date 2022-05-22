/************************************************************************
公式库附属的颜色值配置和处理的函数。
Copyright (C) 2022 NULL_703. All rights reserved.
Created on 2022.3.11  7:41
Created by NULL_703
Last change time on 2022.4.4  8:14
************************************************************************/
#include "include/imageProcess.h"
#include "include/formulas.h"

//零值变量，在遇到错误或其他意外情况时将返回此值，也可作为初始值使用
const SHK_RGBAVALUE zeroValue = {0, 0, 0, 0};

SHK_BOOL shk_rgbacheck(SHK_RGBAVALUE objValue)
{
    return (
        objValue.red > 0xff || objValue.green > 0xff || objValue.blue > 0xff || objValue.alpha > 0xff
    )
    ? SHK_FALSE : SHK_TRUE;
}

SHK_RGBAVALUE shk_HexcoToStd(SHK_BINARY hexColorValue)
{
    SHK_RGBAVALUE result = zeroValue;
    char temp[3];
    int RGBUnit = 0;
    //参数合法性判断
    if(
        shk_strlen(hexColorValue) > 8 || shk_IsOdd(shk_strlen(hexColorValue)) == SHK_TRUE ||
        shk_strlen(hexColorValue) < 6
    )
        return result;
    for(int i = 0; hexColorValue[i] != '\0'; ++i, RGBUnit++)
    {
        for(int j = 0; j <= 1; ++j) temp[j] = hexColorValue[i + j];
        i++;
        temp[2] = '\0';    //在字符串末尾加上结束字符\0以防止意外情况的发生
        switch(RGBUnit)
        {
            case 0: result.red = shk_HexToDec(temp); break;
            case 1: result.green = shk_HexToDec(temp); break;
            case 2: result.blue = shk_HexToDec(temp); break;
            case 3: result.alpha = shk_HexToDec(temp); break;
            default: return zeroValue;
        }
    }
    if(shk_rgbacheck(result) == SHK_FALSE) return zeroValue;
    return result;
}

int shk_imgsizeof(int imgheight, int imgwidth, int pixdep)
{
    int temp = imgheight * imgwidth * pixdep;
    return (int)temp / 8;
}