/************************************************************************
变量类型及一些属性值的定义。
Copyright (C) 2021-2022 NULL_703. All rights reserved.
Created on 2021.11.22  13:18
Created by NULL_703
Last change time on 2022.3.11  8:01
************************************************************************/
#ifndef LIBFORMULA_DEFVAR_H
#define LIBFORMULA_DEFVAR_H

#ifndef SHK_DEFINE
    //Formula library error flag.
    #define OPTIONERR "!OPE"    //参数选项错误
    #define STRTOOLONG "!SLE"    //字符串太长
    #define BITTOOLONG "!BLE"    //位数过长
    #define NOTEQUAL "!NEQ"    //不等于
    //Boolean value
    #define SHK_DEFINE
    #ifndef SHK_BOOLVALUE
        #define SHK_BOOLVALUE
        typedef int SHK_BOOL;
        #define SHK_TRUE 1
        #define SHK_FALSE 0
    #endif
    //Ipaddress value
    #ifndef SHK_IPVALUE
        #define SHK_IPVALUE
        typedef struct ipv4addr{
            unsigned int IPV4_A;
            unsigned int IPV4_B;
            unsigned int IPV4_C;
            unsigned int IPV4_D;
        }SHK_IPV4ADDR;
        #define IPV4VALUE_LIMIT_MAX 0xff
        typedef int SHK_IPV4CLASS;
        #define IPV4CLASS_INVALID 0
        #define IPV4CLASS_A 1
        #define IPV4CLASS_B 2
        #define IPV4CLASS_C 3
        #define IPV4CLASS_D 4
        #define IPV4CLASS_E 5
    #endif
    //Coordinate system
    #ifndef COORSYS
        #define COORSYS
        typedef struct pracsa{
            double x;
            double y;
        }SHK_PRACSA;
        typedef struct sopca{
            double rho;
            double theta;
        }SHK_SOPCA;
    #endif
    //Rgb&rgba value
    #ifndef RGBCOLOR
        #define RGBCOLOR
        typedef struct rgbavalue{
            unsigned int red;
            unsigned int green;
            unsigned int blue;
            unsigned int alpha;
        }SHK_RGBAVALUE;
        #define COLORUNIT_LIMIT_MAX 0xff
    #endif
    //Binary type.
    #ifndef BINARYTYPE
        #define BINARYTYPE
        typedef char* SHK_BINARY;
    #endif
    //Date and time.
    #ifndef TIMETYPE
        #define TIMETYPE
        typedef struct time{
            unsigned int hour;
            unsigned int mim;
            unsigned int sec;
        }SHK_TIME;
        #define TIMEMS_LIMIT 60
        typedef struct date{
            unsigned int year;
            unsigned int mon;
            unsigned int day;
        }SHK_DATE;
        typedef unsigned int SHK_WEEK;
        #define WEEK_LIMIT 7
    #endif
    //Fraction type.
    #ifndef FRACTION
        #define FRACTION
        typedef struct fraction{
            double numerator;
            double denominator;
        }SHK_FRACTION;
    #endif
#endif     //SHK_DEFINE
#endif     //LIBFORMULA_DEFVAR_H