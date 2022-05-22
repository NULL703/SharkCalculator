/************************************************************************
十六进制转换。
Copyright (C) 2022 NULL_703. All rights reserved.
Created on 2022.3.17  10:52
Created by NULL_703
Last change time on 2022.4.12  9:45
************************************************************************/
#include "include/functions.h"

typedef struct{
    char bitBin[5];
    int index;    //索引值作保留用
}constString;

//0 ~ F的对应二进制值
constString hex_binTable[0x10] = {
    "0000", 1, "0001", 2, "0010", 3, "0011", 4, "0100", 5,                      /* 0, 1, 2, 3, 4 */
    "0101", 6, "0110", 7, "0111", 8, "1000", 9, "1001", 10,                     /* 5, 6, 7, 8, 9 */
    "1010", 11, "1011", 12, "1100", 13, "1101", 14, "1110", 15, "1111", 16      /* A, B, C, D, E, F */
};

int shk_HexToDec(const char* hexValue)
{
    int results[0xff];
    int result = 0;
    int hexBit = 0;
    for(int i = 0; hexValue[i] != '\0'; ++i, ++hexBit)
    {
        switch(hexValue[i])
        {
            case '0': results[i] = 0; break;
            case '1': results[i] = 1; break;
            case '2': results[i] = 2; break;
            case '3': results[i] = 3; break;
            case '4': results[i] = 4; break;
            case '5': results[i] = 5; break;
            case '6': results[i] = 6; break;
            case '7': results[i] = 7; break;
            case '8': results[i] = 8; break;
            case '9': results[i] = 9; break;
            case 'A':
            case 'a': results[i] = 10; break;
            case 'B':
            case 'b': results[i] = 11; break;
            case 'C':
            case 'c': results[i] = 12; break;
            case 'D':
            case 'd': results[i] = 13; break;
            case 'E':
            case 'e': results[i] = 14; break;
            case 'F':
            case 'f': results[i] = 15; break;
            default: return 0;    //遇到无效的十六进制值直接返回0
        }
    }
    for(int j = 0; hexBit >= 0; ++j, --hexBit)
        result += results[j] * (int)shk_pow(16, hexBit);
    return result;
}

SHK_BINARY shk_silhb(char hex)
{
    switch(hex)
    {
        case '0': return hex_binTable[0].bitBin; break;
        case '1': return hex_binTable[1].bitBin; break;
        case '2': return hex_binTable[2].bitBin; break;
        case '3': return hex_binTable[3].bitBin; break;
        case '4': return hex_binTable[4].bitBin; break;
        case '5': return hex_binTable[5].bitBin; break;
        case '6': return hex_binTable[6].bitBin; break;
        case '7': return hex_binTable[7].bitBin; break;
        case '8': return hex_binTable[8].bitBin; break;
        case '9': return hex_binTable[9].bitBin; break;
        case 'A':
        case 'a': return hex_binTable[10].bitBin; break;
        case 'B':
        case 'b': return hex_binTable[11].bitBin; break;
        case 'C':
        case 'c': return hex_binTable[12].bitBin; break;
        case 'D':
        case 'd': return hex_binTable[13].bitBin; break;
        case 'E':
        case 'e': return hex_binTable[14].bitBin; break;
        case 'F':
        case 'f': return hex_binTable[15].bitBin; break;
        default: return hex_binTable[0].bitBin;
    }
}