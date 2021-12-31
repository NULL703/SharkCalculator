/************************************************************************
文件操作模块.
Copyright (C) 2021 NULL_703. All rights reserved.
Created on 2021.12.24  13:39
Created by NULL_703
Last change time on 2021.12.31  12:50
************************************************************************/
#include "include/fileopt.h"
#include "include/main.h"

void configLog(int flag, int line, const char* fileName, const char* funcName)
{
    ofstream wrfile("ProgramLog.log", ios::app);
    if(!wrfile.fail())
    {
        if(flag == 0)     //程序正常退出
            wrfile << time(NULL) << ": in '" << fileName << "':\n\tfunction '" << funcName << "': Line" << line << L0001 << endl;
        else if(flag == 1)     //程序正常启动
            wrfile << time(NULL) << ": in '" << fileName << "':\n\tfunction '" << funcName << "': Line" << line << L0004 << endl;
        else if(flag == 2)     //结果池数据溢出将重置的警告
            wrfile << time(NULL) << ": in '" << fileName << "':\n\tfunction '" << funcName << "': Line" << line << L0003 << endl;
        else if(flag == 3)     //文件未找到
            wrfile << time(NULL) << ": in '" << fileName << "':\n\tfunction '" << funcName << "': Line" << line << L0005 << endl;
        else if(flag == 4)     //无法获取结果池中的数据
            wrfile << time(NULL) << ": in '" << fileName << "':\n\tfunction '" << funcName << "': Line" << line << L0006 << endl;
        else if(flag == 5)     //文件打开失败
            wrfile << time(NULL) << ": in '" << fileName << "':\n\tfunction '" << funcName << "': Line" << line << L0007 << endl;
        else if(flag == 6)     //无效的表达式或命令参数
            wrfile << time(NULL) << ": in '" << fileName << "':\n\tfunction '" << funcName << "': Line" << line << L0008 << endl;
        else if(flag == 7)     //存储模式未打开的警告
            wrfile << time(NULL) << ": in '" << fileName << "':\n\tfunction '" << funcName << "': Line" << line << L0009 << endl;
        else if(flag == 8)     //无效命令参数(在日志中为警告，但在命令行中是输出错误信息)
            wrfile << time(NULL) << ": in '" << fileName << "':\n\tfunction '" << funcName << "': Line" << line << L0010 << endl;
        else if(flag == 9)     //文件已删除
            wrfile << time(NULL) << ": in '" << fileName << "':\n\tfunction '" << funcName << "': Line" << line << L0011 << endl;
        else     //未指定的未知错误
            wrfile << time(NULL) << ": in '" << fileName << "':\n\tfunction '" << funcName << "': Line" << line << L0002 << endl;
    }else{
        printf("%s%s%s", F_RED, w0007, NORMAL);
        exit(1);
    }
}

void deleteFile(const char* filename)
{
    char opn;
    printf("%s", w0034);
    scanf("%c", &opn);
    while('\n' != getchar());
    if(opn == 'y' || opn == 'Y')
    {
        if(!remove("ProgramLog.log"))
        {
            printf("%s", w0032);
            exit(0);
        }else{
            printf("%s%s%s", F_RED, w0033, NORMAL);
            exit(1);
        }
    }else{
        printf("%s%s%s", F_LIGHT_BLUE, w0030, NORMAL);
        commandProc();
    }
}