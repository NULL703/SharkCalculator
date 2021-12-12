/************************************************************************
变量类型及一些属性值的定义。
Copyright (C) 2021 NULL_703. All rights reserved.
Created on 2021.11.22  13:18
Created by NULL_703
Last change time on 2021.11.26  9:23
************************************************************************/
#ifndef LIBFORMULA_DEFVAR_H
#define LIBFORMULA_DEFVAR_H

#ifndef SHK_DEFINE
    //Boolean value
    #define SHK_DEFINE
    #ifndef SHK_BOOLVALUE
        #define SHK_BOOLVALUE
        typedef int SHK_BOOL;
        #define SHK_TRUE 0
        #define SHK_FALSE 1
    #endif
    //Ipaddress value
    #ifndef SHK_IPVALUE
        #define SHK_IPVALUE
        typedef struct ipv4addr{
            int IPV4_A;
            int IPV4_B;
            int IPV4_C;
            int IPV4_D;
        }SHK_IPV4ADDR;
        #define IPV4VALUE_LIMIT_MAX 0xff
        #define IPV4VALUE_LIMIT_MIN 0x0
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
            int red;
            int green;
            int blue;
            int alpha;
        }SHK_RGBAVALUE;
        #define COLORUNIT_LIMIT_MAX 0xff
        #define COLORUNIT_LIMIT_MIN 0x0
    #endif
    //Binary type.
    #ifndef BINARYTYPE
        #define BINARYTYPE
        typedef char* SHK_BINARY;
    #endif
#endif     //SHK_DEFINE
#endif     //LIBFORMULA_DEFVAR_H