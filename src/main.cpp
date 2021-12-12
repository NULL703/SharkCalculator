/************************************************************************
Main program.
Copyright (C) 2021 NULL_703. All rights reserved.
Created on 2021.10.7  17:31
Created by NULL_703
Last change time on 2021.12.11  12:24
************************************************************************/
#include "include/main.h"

void normalCalc()
{
    //TODO:常规计算将在后续版本开放
    ;
}

void configLog(int flag)
{
    //TODO:将在后续版本中补充文件操作的内容
    ;
}

/*-------------------------------------------------------------------
*函数错误码值对应的含义：
*0：正常情况的返回值                1：程序退出命令
*2：表达式或数字错误                3：无效或错误的命令
*4：其他不可预料的错误
*------------------------------------------------------------------*/
void mainFunc(int flag)
{
    int errCode = 0;
    while(errCode == 0)
    {
        if(flag == 0)     //命令行没有参数
        {
            errCode = commandProc();
            if(errCode != 0)
                break;
        }else if(flag == 1){     //简单计算模式
            errCode = basicCalculate();
            if(errCode != 0)
                break;
        }
        mainFunc(flag);
    }
    if(errCode == 1)
        exit(0);
    else if(errCode == 2)
        exit(1);
}

void arrayInit()
{
    for(int i = 0; i <= 0xff; i++)
    {
        results[i] = 0;
    }
}

enum calc calcOper(char oper)
{
    switch(oper)
    {
        case '+':
            return cadd;
            break;
        case '-':
            return csub;
            break;
        case '*':
            return cmul;
            break;
        case '/':
            return cdiv;
            break;
        default:
            printf("%s%s%s", F_RED, w0016, NORMAL);
            return err;
    }
}

int basicCalculate()
{
    char expr[1024] = "";
    char exprElement1[1024] = {};
    char exprElement2[1024] = {};
    char oper = 0;
    int flagNumber = 0;
    double result = 0.0, numx = 0.0, numy = 0.0;
    enum calc calculateMethod = cadd;
    printf("%s", w0009);
    scanf("%s", expr);
    setbuf(stdin, NULL);
    for(int i = 0, j = 0; expr[i] != '\0'; i++, j++)
    {
        if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
        {
            //如果在此之前就已设置flagNumber的值为1或数字中存在非法字符，则退出函数
            if(flagNumber == 1 && ((int)expr[i] > 58 || (int)expr[i] < 48))
            {
                printf("%s%s%s", F_RED, w0011, NORMAL);
                return 2;
            }
            flagNumber = 1;
            oper = expr[i];
            j = 0;
            continue;
        }
        if(flagNumber == 0)
            exprElement1[j] = expr[i];
        else
            exprElement2[j - 1] = expr[i];     //This code is VERY powerful!!!
    }
    numx = atof(exprElement1);
    numy = atof(exprElement2);
    calculateMethod = calcOper(oper);
    if(calculateMethod == err)
        return 2;
    result = calcTypeProc(calculateMethod, numx, numy);
    if(storageModeSwitch == SHK_TRUE)
    {
        if(resultsIndex >= 0xff)     //超过255个计算结果时将索引值重置为0
        {
            printf("%s%s%s", F_YELLOW, w0021, NORMAL);
            resultsIndex = 0;
        }
        results[resultsIndex] = result;
        resultsIndex += 1;
    }
    printf("%s%f\n", w0015, result);
    return 0;
}

int commandProc()
{
    char command;
    printf("%s", w0002);
    //cin.ignore(0x1000, '\n');
    scanf("%c", &command);
    setbuf(stdin, NULL);
    if(command == 'n')
    {
        printf("%s%s%s", F_RED, w0014, NORMAL);
        return 2;
    }else if(command == 'f'){
        printf("%s%s%s", F_RED, w0014, NORMAL);
        return 2;
    }else if(command == 'b'){
        basicCalculate();
        return 0;
    }else if(command == 'h'){
        printf("%s", w0001);
        return 0;
    }else if(command == 'l'){
        printf("%s%s%s", F_RED, w0014, NORMAL);
        return 2;
    }else if(command == 's'){
        if(storageModeSwitch == SHK_FALSE)
        {
            storageModeSwitch = SHK_TRUE;
            return 0;
        }else{
            storageModeSwitch = SHK_FALSE;
            return 0;
        }
    }else if(command == 'e'){
        return 1;
    }else{
        printf("%s%s%s", F_RED, w0008, NORMAL);
        return 3; 
    }
    return 0;
}

int main(int argc, const char** argv)
{
    #ifdef __WIN32
        system("cls");
    #endif
    if(argv[1] == NULL)
    {
        printf("%s%s%s", F_RED, w0004, NORMAL);
        mainFunc(0);
    }
    arrayInit();
    if(argc > 1 && (strcmp(argv[1], "-abs") == 0))
    {
        printf("%s%f", w0015, shk_abs(atof(argv[2])));
        return 0;
    }else{
        if(strcmp(argv[1], "-n") == 0){
            printf("%s%s%s", F_RED, w0014, NORMAL);
            return 1;
        }
        else if(strcmp(argv[1], "-f") == 0){
            printf("%s%s%s", F_RED, w0014, NORMAL);
            return 1;
        }
        else if(strcmp(argv[1], "-h") == 0){
            printf("%s%s%s", F_RED, w0014, NORMAL);
            return 1;
        }
        else if(strcmp(argv[1], "--bh") == 0)
        {
            printf("%s", w0001);
            return 0;
        }
        else if(strcmp(argv[1], "--basic") == 0)
            mainFunc(1);
        else if(strcmp(argv[1], "--storage") == 0){
            printf("%s%s%s", F_RED, w0014, NORMAL);
            return 1;
            // storageModeSwitch = SHK_TRUE;
            // mainFunc(0);
        }else{
            printf("%s%s%s%s", F_RED, w0004, NORMAL, w0017);
            printf("%s", w0001);
            mainFunc(0);
        }
    }
    return 0;
}