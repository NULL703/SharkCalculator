/************************************************************************
公式库附属网络相关的专用函数的声明。
Copyright (C) 2021 NULL_703. All rights reserved.
Created on 2021.11.24  13:18
Created by NULL_703
Last change time on 2021.12.29  14:49
************************************************************************/
#ifndef LIBFORMULA_NETWORK_H
#define LIBFORMULA_NETWORK_H

#include "defvar.h"

#ifdef __cplusplus
extern "C"{
#endif

SHK_IPV4CLASS shk_ipv4AddressType(SHK_IPV4ADDR ipv4Address);
SHK_IPV4ADDR shk_netAddress(SHK_IPV4ADDR ipv4Address, SHK_IPV4ADDR subnetMask);

#ifdef __cplusplus
}
#endif     //__cplusplus
#endif     //LIBFORMULA_NETWORK_H