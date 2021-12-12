/************************************************************************
公式库附属网络相关的专用函数。
Copyright (C) 2021 NULL_703, All rights reserved.
Created on 2021.11.24  13:17
Created by NULL_703
Last change time on 2021.11.25  16:51
************************************************************************/
#include "include/network.h"

SHK_IPV4CLASS shk_ipv4AddressType(SHK_IPV4ADDR ipv4Address)
{
    if(
        ipv4Address.IPV4_A > 0xff || ipv4Address.IPV4_B > 0xff || ipv4Address.IPV4_C > 0xff || 
        ipv4Address.IPV4_D > 0xff || ipv4Address.IPV4_A < 0x0 || ipv4Address.IPV4_B < 0x0 ||
        ipv4Address.IPV4_C < 0x0 || ipv4Address.IPV4_D < 0x0
    )
        return IPV4CLASS_INVALID;
    else if(ipv4Address.IPV4_A <= 127)
        return IPV4CLASS_A;
    else if(ipv4Address.IPV4_A > 127 && ipv4Address.IPV4_A <= 191)
        return IPV4CLASS_B;
    else if(ipv4Address.IPV4_A > 191 && ipv4Address.IPV4_A <= 223)
        return IPV4CLASS_C;
    else if(ipv4Address.IPV4_A > 223 && ipv4Address.IPV4_A <= 239)
        return IPV4CLASS_D;
    else if(ipv4Address.IPV4_A > 239 && ipv4Address.IPV4_A <= 247)
        return IPV4CLASS_E;
    else
        return IPV4CLASS_INVALID;
}

SHK_IPV4ADDR shk_netAddress(SHK_IPV4ADDR ipv4Address, SHK_IPV4ADDR subnetMask)
{
    SHK_IPV4ADDR result;
    result.IPV4_A = ipv4Address.IPV4_A & subnetMask.IPV4_A;
    result.IPV4_B = ipv4Address.IPV4_B & subnetMask.IPV4_B;
    result.IPV4_C = ipv4Address.IPV4_C & subnetMask.IPV4_C;
    result.IPV4_D = ipv4Address.IPV4_D & subnetMask.IPV4_D;
    return result;
}
