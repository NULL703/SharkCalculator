/************************************************************************
程序文本(English)。
Copyright (C) 2021 NULL_703. All rights reserved.
Created on 2021.10.7  17:37
Created by NULL_703
Last change time on 2021.12.25  9:23
************************************************************************/
#ifndef SHARKCALCULATOR_TEXTS_H
#define SHARKCALCULATOR_TEXTS_H
    #define w0001 "SharkCalculator v1.0.2, Copyright (C) NULL_703. All rights reserved.\n"\
        "Usage: shcalc {options: [<none option>] [-<calculate flag>] [-n] [-h] [--bh] [--basic] [--storage]} {nums} ...\n"\
        "Mainly option:\n"\
        "    [<none option>]: Use internal command.(for no option)\n"\
        "    [-<calculate flag>]: Calculate same formulas or expression.\n"\
        "    [-n]: Use normal calculate mode.\033[0;32;31m <Not open>\033[m\n"\
        "    [-h]: Show help.(open help document)\033[0;32;31m <Not open>\033[m\n"\
        "    [--bh]: Show basic help.\n"\
        "    [--basic]: Basic calculate mode.\n"\
        "    [--storage]: Open storage mode.\n"\
        "    [--cleanlog]: Delete logger file.\n"\
        "Program internal command: [n] [b] [l] [h] [s] [u] [e] [q] [c]\n"\
        "    n: Use normal calculate mode.\033[0;32;31m <Not open>\033[m\n"\
        "    b: Basic calculate mode.\n"\
        "    l: Save calculate result.\033[0;32;31m <Not open>\033[m\n"\
        "    h: Show basic help.\n"\
        "    s: Open or close storage mode.\n"\
        "    u: Use result calculate.\n"\
        "    e: Exit program.\n"\
        "    q: Lookup the data in the result-pool.\n"\
        "    c: Clean the data in the result-pool.\n"\
        "    d: Delete logger file and exit program.\n"
    #define w0002 "Please input command:\n-->"
    #define w0003 "\aError: Cannot be divided by 0![E_1001]\n"
    #define w0004 "\aError: Invalid parameter![E_2001]\n"
    #define w0005 "\aError: Formula nothingness![E_2002]\n"
    #define w0006 "\aError: Formula parameter error![E_1002]\n"
    #define w0007 "\aError: Unknow error![E_-1]\n"
    #define w0008 "\aError: Command not found![E_2101]\n"
    #define w0009 "Please input expression(format: number-operator-number):\n-->"
    #define w0010 "Basic calculate.\n"
    #define w0011 "Unknow number! please try again.[E_2102]\n"
    #define w0012 "Are you open documents on program directory? (y/n)\n"
    #define w0013 "\aError: Expression error![E_1003]\n"
    #define w0014 "\aError: This mode is not open![E_0001]\n"
    #define w0015 "The result is:\n\t->> "
    #define w0016 "\aError: Internal error![E_1101]\n"
    #define w0017 "Please see help in below.\n"
    #define w0018 "Are you sure clean all data? (y/n)\n"
    #define w0019 "\aError: Storage mode not open, you can't clean or read data.[E_3001]\n"
    #define w0020 "\aError: This data-term nothingness![E_3002]\n"
    #define w0021 "Worning: Result-pool data is full, result-pool is reset.[W_3001]\n"
    #define w0022 "Last build time: "
    #define w0023 "The storage mode have been open.[I_3001]\n"
    #define w0024 "The storage mode have been close.[I_3002]\n"
    #define w0025 "The storage mode is not open or result too few.[W_3002]\n"
    #define w0026 "Please input expression(format: resultNumber-operator-resultNumber):\n-->"
    #define w0027 "Please input lookup command:\n-->"
    #define w0028 "Please input parameter:\n-->"
    #define w0029 "This result is:"
    #define w0030 "Opertion cancel or option error.[I_3003]\n"
    #define w0031 "Opertion succeed.\n"
    #define w0032 "The file have been delete.[I_4042]\n"
    #define w0033 "\aError: The file delete failed.[E_4041]\n"
    #define w0034 "Are you delete logger file?(y/n)\n"
#endif     //SHARKCALCULATOR_TEXTS_H