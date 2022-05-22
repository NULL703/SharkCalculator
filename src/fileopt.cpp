/************************************************************************
文件操作模块.
Copyright (C) 2021-2022 NULL_703. All rights reserved.
Created on 2021.12.24  13:39
Created by NULL_703
Last change time on 2022.3.16  10:57
************************************************************************/
#include "include/fileopt.h"
#include "include/main.h"

static double foResults[255];
static int foResultsIndex = 0;
static SHK_BOOL foStorageModeSwitch = SHK_FALSE;

void configLog(int flag, int line, const char* fileName, const char* funcName, SHK_BOOL loggerFlag)
{
    if(loggerFlag == SHK_FALSE)
        return;
    ofstream wrfile("ProgramLog.log", ios::app);
    if(!wrfile.fail())
    {
        wrfile << time(NULL) << ": in '" << fileName << "':\n\tfunction '" << funcName << "': Line" << line;
        switch(flag)
        {
            //程序正常退出
            case 0: {
                wrfile << L0001 << endl;
                break;
            }
            //程序正常启动
            case 1: {
                wrfile << L0004 << endl;
                break;
            }
            //结果池数据溢出将重置的警告
            case 2: {
                wrfile << L0003 << endl;
                break;
            }
            //文件未找到
            case 3: {
                wrfile << L0005 << endl;
                break;
            }
            //无法获取结果池中的数据
            case 4: {
                wrfile << L0006 << endl;
                break;
            }
            //文件打开失败
            case 5: {
                wrfile << L0007 << endl;
                break;
            }
            //无效的表达式或命令参数
            case 6: {
                wrfile << L0008 << endl;
                break;
            }
            //存储模式未打开的警告
            case 7: {
                wrfile << L0009 << endl;
                break;
            }
            //无效命令参数(在日志中为警告，但在命令行中是输出错误信息)
            case 8: {
                wrfile << L0010 << endl;
                break;
            }
            //文件已删除
            case 9: {
                wrfile << L0011 << endl;
                break;
            }
            //未指定的未知错误
            default:
                wrfile << L0002 << endl;
        }
    }else{
        printf("%s%s%s", F_RED, w0007, NORMAL);
        exit(1);
    }
    wrfile.close();
}

void getResult(int index)
{
    for(int i = 0; i < index; ++i)
        foResults[i] = getResultsValue(i);
}

void refvar()
{
    foStorageModeSwitch = getStorageStatus();
    foResultsIndex = getResultsIndex();
    getResult(foResultsIndex);
}

SHK_BOOL checkFileStatus(const char* fileName)
{
    if(access(fileName, 0) == -1) return SHK_FALSE;
    return SHK_TRUE;
}

void deleteFile()
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

void saveResult()
{
    char filename[0xff] = defaultFileName;
    ofstream resultFile;
    refvar();
    printf("%s%s%s", F_LIGHT_BLUE, w0043, NORMAL);
    scanf("%s", filename);
    while('\n' != getchar());
    if(checkFileStatus(filename) == SHK_FALSE)
    {
        resultFile.open(filename, ios::app);
    }else{
        if(access(defaultFileName, 0) != -1)
        {
            printf("%s%s%s", F_YELLOW, w0044, NORMAL);
            saveResult();
            return;
        }
        printf("%s%s%s", F_LIGHT_BLUE, w0045, NORMAL);
        resultFile.open(defaultFileName, ios::app);
    }
    if(foStorageModeSwitch == SHK_FALSE)
    {
        printf("%s%s%s", F_RED, w0019, NORMAL);
        configLog(4, __LINE__, __FILE__, __FUNCTION__, getLoggerStatus());
        return;
    }
    resultFile << w0037 << endl;
    resultFile << "Sequence-number\t\tresult" << endl;
    for(int i = 0; i <= foResultsIndex - 1; ++i)
        resultFile << i << "\t\t\t" << foResults[i] << endl;
    printf("%s%s%s", F_BLUE, w0031, NORMAL);
    resultFile.close();
}