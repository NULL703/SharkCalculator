/************************************************************************
Main program.
Copyright (C) 2021-2022 NULL_703. All rights reserved.
Created on 2021.10.7  17:31
Created by NULL_703
Last change time on 2022.5.21  7:35
************************************************************************/
#include "include/main.h"

#define infcmdCount 14
#define progcmdCount 10
static double results[255];    //存储池最大数据量为255
static int resultsIndex = 0;    //存储池数据写入的指针位置(存储池数据索引最大值)
static SHK_BOOL storageModeSwitch = SHK_FALSE;    //存储模式状态
static SHK_BOOL loggerStatus = SHK_TRUE;    //记录器状态

//内部命令
char infcmds[infcmdCount][0x20] = {
    "n", "b", "l", "h", "s", "u", "e", "q", "c", "v", "d", "insert", "setindex",
    "nolog"
};

//程序选项
char progcmds[progcmdCount][0x20] = {
    "", "-n", "-h", "--bh", "--basic", "--storage", "--cleanlog", "--version",
    "-v", "--nolog"
};

//命令匹配，命令类型为0时为内部命令，类型为1时为程序命令
int commandMarch(const char* command, int cmdtype)
{
    int cmdindex = 0;
    while(cmdindex != 15)
    {
        if(cmdtype == 0)
        {
            if(strcmp(command, infcmds[cmdindex]) == 0) break;
        }else{
            if(strcmp(command, progcmds[cmdindex]) == 0) break;
        }
        cmdindex++;
    }
    return cmdindex;
}

void resultLookup::selectLookupMode()
{
    char mode;
    int par = 0;
    printf("%s%s%s", F_LIGHT_BLUE, w0027, NORMAL);
    scanf("%c", &mode);
    while('\n' != getchar());
    if(mode == 's')
    {
        printf("%s%s%s", F_LIGHT_CYAN, w0028, NORMAL);
        scanf("%d", &par);
        while('\n' != getchar());
        showStorageStatus();
        printf("%s%s%f%s\n", F_LIGHT_GREEN, w0029, getResult(par), NORMAL);
    }else if(mode == 'a'){
        printf("%s%s%s", F_LIGHT_CYAN, w0028, NORMAL);
        scanf("%d", &par);
        while('\n' != getchar());
        showAllResult(par);
    }else{
        printf("%s%s%s", F_RED, w0008, NORMAL);
        configLog(6, __LINE__, __FILE__, __FUNCTION__, loggerStatus);
    }
}

double resultLookup::getResult(int index)
{
    if(index >= resultsIndex)
        return showErrorInfo();
    return results[index];
}

void resultLookup::showAllResult(int maxResultNumber)
{
    showStorageStatus();
    if(maxResultNumber >= resultsIndex)
    {
        showErrorInfo();
        printf("%s", w0035);
        maxResultNumber = resultsIndex - 1;
    }
    for(int i = 0; i <= maxResultNumber; i++)
        printf("%s%d\t%f%s\n", F_LIGHT_GREEN, i, results[i], NORMAL);
    if(resultsIndex - 1 < 0)
        printf("%s<None>\n%s", F_LIGHT_GREEN, NORMAL);
}

int resultLookup::showErrorInfo()
{
    printf("%s%s%s", F_RED, w0020, NORMAL);
    configLog(4, __LINE__, __FILE__, __FUNCTION__, loggerStatus);
    return 0;
}

void resultLookup::showStorageStatus()
{
    int units = (resultsIndex * 100) / 255;
    int diff = 100 - units;
    printf("%s%s[", F_LIGHT_BLUE, w0036);
    for(int i = 0; i < units; i++)
        printf("|");
    for(int j = 0; j < diff; j++)
        printf(".");
    printf("]%.2f%c%s\n", (resultsIndex * 100) / 255.0, '%', NORMAL);
}

SHK_BOOL getStorageStatus()
{
    return storageModeSwitch;
}

int getResultsIndex()
{
    return resultsIndex;
}

double getResultsValue(int index)
{
    return results[index];
}

SHK_BOOL getLoggerStatus()
{
    return loggerStatus;
}

void normalCalc()
{
    //TODO:常规计算将在后续版本开放
    ;
}

double useResult(int resultNumber)
{
    if(resultNumber >= resultsIndex)
    {
        printf("%s%s%s", F_RED, w0020, NORMAL);
        configLog(4, __LINE__, __FILE__, __FUNCTION__, loggerStatus);
        return 0.0;
    }
    return results[resultNumber];
}

void storageCalc()
{
    int x, y;
    char op;
    enum calc cmt = cadd;
    printf("%s", w0026);
    scanf("%d%c%d", &x, &op, &y);
    while('\n' != getchar());
    if(x >= resultsIndex || y >= resultsIndex)
    {
        printf("%s%s%s", F_RED, w0020, NORMAL);
        configLog(4, __LINE__, __FILE__, __FUNCTION__, loggerStatus);
        commandProc();
        return;
    }
    cmt = calcOper(op);
    printf("%s%f\n", w0015, calcTypeProc(cmt, useResult(x), useResult(y)));
}

enum calc calcOper(char oper)
{
    switch(oper)
    {
        case '+': {
            return cadd;
            break;
        }
        case '-': {
            return csub;
            break;
        }
        case '*': {
            return cmul;
            break;
        }
        case '/': {
            return cdiv;
            break;
        }
        default: {
            printf("%s%s%s", F_RED, w0016, NORMAL);
            return err;
        }
    }
}

int basicCalculate()
{
    char expr[0xff] = "";
    char exprElement1[0xff] = {};
    char exprElement2[0xff] = {};
    char oper = 0;
    int flagNumber = 0;
    double result = 0.0, numx = 0.0, numy = 0.0;
    enum calc calculateMethod = cadd;
    printf("%s", w0009);
    scanf("%s", expr);
    while('\n' != getchar());
    if(expr[0] == 'e')
    {
        configLog(0, __LINE__, __FILE__, __FUNCTION__, loggerStatus);
        exit(0);
    }
    for(int i = 0, j = 0; expr[i] != '\0'; i++, j++)
    {
        if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
        {
            //如果在此之前就已设置flagNumber的值为1或数字中存在非法字符，则退出函数
            if(flagNumber == 1 && ((int)expr[i] > 58 || (int)expr[i] < 48))
            {
                printf("%s%s%s", F_RED, w0011, NORMAL);
                return 0;
            }
            flagNumber = 1;
            oper = expr[i];
            j = 0;
            continue;
        }
        if(flagNumber == 0)
            exprElement1[j] = expr[i];
        else
            exprElement2[j - 1] = expr[i];
    }
    numx = atof(exprElement1);
    numy = atof(exprElement2);
    calculateMethod = calcOper(oper);
    if(calculateMethod == err)
        return 1;
    result = calcTypeProc(calculateMethod, numx, numy);
    if(storageModeSwitch == SHK_TRUE)
    {
        if(resultsIndex > 0xff)     //超过255个计算结果时将索引值重置为0
        {
            printf("%s%s%s", F_YELLOW, w0021, NORMAL);
            resultsIndex = 0;
            configLog(2, __LINE__, __FILE__, __FUNCTION__, loggerStatus);
            results[resultsIndex] = result;
        }
        results[resultsIndex] = result;
        resultsIndex += 1;
    }
    printf("%s%f\n", w0015, result);
    return 0;
}

void cleanResult()
{
    char choose;
    printf("%s", w0018);
    scanf("%c", &choose);
    while('\n' != getchar());
    if(choose == 'y' || choose == 'Y')
    {
        resultsIndex = 0;    //清除存储池数据的实际原理是重置存储池索引指针，然后从零开始覆写数据
        printf("%s%s%s", F_LIGHT_BLUE, w0031, NORMAL);
    }else{
        printf("%s%s%s", F_LIGHT_BLUE, w0030, NORMAL);
        return;
    }
}

void resultPoolInsert()
{
    char number[0x20];
    while(strcmp(number, "quit") != 0)
    {
        //存储池溢出检测
        if(resultsIndex + 1 > 0xff)
        {
            printf("%s%s%s", F_BLUE, w0040, NORMAL);
            if(getchar() == 'y' || getchar() == 'Y')
            {
                printf("%s%s%s", F_YELLOW, w0021, NORMAL);
                resultsIndex = 0;    //重置索引指针
                configLog(2, __LINE__, __FILE__, __FUNCTION__, loggerStatus);
            }else{
                printf("%s%s%s", F_LIGHT_BLUE, w0030, NORMAL);
                return;
            }
        }
        printf("%s%sindex:%d -->%s", F_LIGHT_BLUE, w0038, resultsIndex, NORMAL);
        scanf("%s", number);
        while('\n' != getchar());
        if(strcmp(number, "quit") == 0)
            break;
        results[resultsIndex] = atof(number);
        resultsIndex++;
    }
}

void setStorageIndex()
{
#ifdef DEBUG
    int newIndex = 0;
    printf("%s%s%s", F_LIGHT_BLUE, w0028, NORMAL);
    scanf("%d", &newIndex);
    while('\n' != getchar());
    if(newIndex > 0xff || newIndex < 0)
    {
        printf("%s%s%s", F_RED, w0004, NORMAL);
        return;
    }
    resultsIndex = newIndex;
#else
    printf("%s%s%s", F_RED, w0042, NORMAL);
#endif
}

void commandProc()
{
    char command[0xff];
    resultLookup lookup;
    printf("%s", w0002);
    scanf("%s", command);
    while('\n' != getchar());
    switch(commandMarch(command, 0))
    {
        //常规计算模式
        case 0: printf("%s%s%s", F_RED, w0014, NORMAL); break;
        //简单计算模式
        case 1: basicCalculate(); break;
        //保存结果
        case 2: saveResult(); break;
        //显示帮助
        case 3: printf("%s%s%s  %s\n", w0001, w0022, __DATE__, __TIME__); break;
        //打开或关闭存储模式
        case 4: {
            if(storageModeSwitch == SHK_FALSE)
            {
                printf("%s%s%s", F_LIGHT_BLUE, w0023, NORMAL);
                storageModeSwitch = SHK_TRUE;
            }else{
                printf("%s%s%s", F_LIGHT_BLUE, w0024, NORMAL);
                storageModeSwitch = SHK_FALSE;
            }
            break;
        }
        //使用存储池的数据进行计算
        case 5: {
            if(storageModeSwitch == SHK_TRUE && resultsIndex >= 1)
            {
                storageCalc();
            }else{
                printf("%s%s%s", F_YELLOW, w0025, NORMAL);
                configLog(4, __LINE__, __FILE__, __FUNCTION__, loggerStatus);
            }
            break;
        }
        //退出程序
        case 6: {
            configLog(0, __LINE__, __FILE__, __FUNCTION__, loggerStatus);
            exit(0);
            break;
        }
        //查找存储池的数据
        case 7: {
            if(storageModeSwitch == SHK_TRUE)
                lookup.selectLookupMode();
            else{
                printf("%s%s%s", F_RED, w0019, NORMAL);
                configLog(4, __LINE__, __FILE__, __FUNCTION__, loggerStatus);
            }
            break;
        }
        //清除存储池的所有数据
        case 8: {
            if(storageModeSwitch == SHK_TRUE)
            {
                cleanResult();
            }else{
                printf("%s%s%s", F_RED, w0019, NORMAL);
            }
            break;
        }
        //显示版本信息
        case 9: printf("%s", versioninfo); break;
        //删除日志文件
        case 10: deleteFile(); break;
        //插入数据到存储池中
        case 11: {
            if(storageModeSwitch == SHK_TRUE)
            {
                resultPoolInsert();
            }else{
                printf("%s%s%s", F_RED, w0019, NORMAL);
            }
            break;
        }
        //设置存储池索引指针
        case 12: setStorageIndex(); break;
        //开启或关闭日志模式
        case 13: {
            if(loggerStatus == SHK_FALSE)
            {
                loggerStatus = SHK_TRUE;
                printf("%s%s%s", F_BLUE, w0046, NORMAL);
            }else{
                loggerStatus = SHK_FALSE;
                printf("%s%s%s", F_BLUE, w0047, NORMAL);
            }
            break;
        }
        default: {
            printf("%s%s%s", F_RED, w0008, NORMAL);
            configLog(6, __LINE__, __FILE__, __FUNCTION__, loggerStatus);
        }
    }
    commandProc();
}

int argCommandExec(const char** argv)
{
    switch(commandMarch(argv[1], 1))
    {
        case 0: commandProc(); break;
        //常规计算模式
        case 1: {
            printf("%s%s%s", F_RED, w0014, NORMAL);
            return 1;
            break;
        }
        //打开文档
        case 2: {
            printf("%s%s%s", F_RED, w0014, NORMAL);
            return 1;
            break;
        }
        //显示帮助
        case 3: printf("%s%s%s  %s\n", w0001, w0022, __DATE__, __TIME__); break;
        //简单计算模式
        case 4: {
            if(basicCalculate() != 0)
                printf("%s%s%s", F_RED, w0013, NORMAL);
            commandProc();
        }
        //进入程序时开启存储模式
        case 5: {
            storageModeSwitch = SHK_TRUE;
            commandProc();
            break;
        }
        //删除日志文件
        case 6: deleteFile(); break;
        //显示版本信息
        case 7: 
        case 8: {
            printf("%s", versioninfo);
            configLog(0, __LINE__, __FILE__, __FUNCTION__, loggerStatus);
            break;
        }
        //进入程序时不产生日志文件
        case 9: loggerStatus = SHK_FALSE; remove("ProgramLog.log"); commandProc(); break;
        default: {
            printf("%s%s%s%s", F_RED, w0004, NORMAL, w0017);
            printf("%s%s%s  %s\n", w0001, w0022, __DATE__, __TIME__);
            configLog(8, __LINE__, __FILE__, __FUNCTION__, loggerStatus);
            commandProc();
        }
    }
    return 0;
}

int main(int argc, const char** argv)
{
    configLog(1, __LINE__, __FILE__, __FUNCTION__, loggerStatus);
    if(argc > 2)
        immediateCalculate(argc, argv);
    #ifdef __WIN32
        system("cls");
    #endif
    if(argv[1] == NULL)
    {
        printf("%s%s%s", F_RED, w0004, NORMAL);
        printf("%s%s%s%s  %s\n", w0017, w0001, w0022, __DATE__, __TIME__);
        configLog(8, __LINE__, __FILE__, __FUNCTION__, loggerStatus);
        commandProc();
    }else{
        return argCommandExec(argv);
    }
    printf("%s%s%s", F_RED, w0007, NORMAL);
    configLog(-1, __LINE__, __FILE__, __FUNCTION__, loggerStatus);
    return 1;
}