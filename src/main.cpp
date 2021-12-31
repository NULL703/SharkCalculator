/************************************************************************
Main program.
Copyright (C) 2021 NULL_703. All rights reserved.
Created on 2021.10.7  17:31
Created by NULL_703
Last change time on 2021.12.31  12:48
************************************************************************/
#include "include/main.h"
#include "include/fileopt.h"

static double results[255];
static int resultsIndex = 0;
static SHK_BOOL storageModeSwitch = SHK_FALSE;

class resultLookup{
    public:
    void selectLookupMode()
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
            printf("%s%s%f%s\n", F_LIGHT_GREEN, w0029, getResult(par), NORMAL);
        }else if(mode == 'a'){
            printf("%s%s%s", F_LIGHT_CYAN, w0028, NORMAL);
            scanf("%d", &par);
            while('\n' != getchar());
            showAllResult(par);
        }else{
            printf("%s%s%s", F_RED, w0008, NORMAL);
            configLog(6, __LINE__, __FILE__, __FUNCTION__);
        }
    }

    double getResult(int index)
    {
        if(index >= resultsIndex)
            return showErrorInfo();
        return results[index];
    }

    void showAllResult(int maxResultNumber)
    {
        if(maxResultNumber >= resultsIndex)
        {
            showErrorInfo();
            return;
        }
        for(int i = 0; i <= maxResultNumber; i++)
            printf("%s%d\t%f%s\n", F_LIGHT_GREEN, i, results[i], NORMAL);
    }

    private:
    int showErrorInfo()
    {
        printf("%s%s%s", F_RED, w0020, NORMAL);
        configLog(4, __LINE__, __FILE__, __FUNCTION__);
        return 0;
    }
};

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
        configLog(0, __LINE__, __FILE__, __FUNCTION__);
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
    setbuf(stdin, NULL);
    if(x > resultsIndex || y > resultsIndex)
    {
        printf("%s%s%s", F_RED, w0020, NORMAL);
        configLog(4, __LINE__, __FILE__, __FUNCTION__);
        commandProc();
        return;
    }
    setbuf(stdin, NULL);
    cmt = calcOper(op);
    printf("%s%f\n", w0015, calcTypeProc(cmt, useResult(x), useResult(y)));
}

enum calc calcOper(char oper)
{
    switch(oper)
    {
        case '+':
        {
            return cadd;
            break;
        }
        case '-':
        {
            return csub;
            break;
        }
        case '*':
        {
            return cmul;
            break;
        }
        case '/':
        {
            return cdiv;
            break;
        }
        default:
        {
            printf("%s%s%s", F_RED, w0016, NORMAL);
            return err;
        }
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
    while('\n' != getchar());
    if(expr[0] == 'e')
    {
        configLog(0, __LINE__, __FILE__, __FUNCTION__);
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
        if(resultsIndex >= 0xff)     //超过255个计算结果时将索引值重置为0
        {
            printf("%s%s%s", F_YELLOW, w0021, NORMAL);
            resultsIndex = 0;
            configLog(2, __LINE__, __FILE__, __FUNCTION__);
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
        resultsIndex = 0;
        printf("%s%s%s", F_LIGHT_BLUE, w0031, NORMAL);
    }else{
        printf("%s%s%s", F_LIGHT_BLUE, w0030, NORMAL);
        return;
    }
}

void commandProc()
{
    char command;
    resultLookup lookup;
    printf("%s", w0002);
    scanf("%c", &command);
    while('\n' != getchar());
    if(command == 'n')
    {
        printf("%s%s%s", F_RED, w0014, NORMAL);
        commandProc();
    }else if(command == 'b'){
        basicCalculate();
        commandProc();
    }else if(command == 'h'){
        printf("%s%s%s  %s", w0001, w0022, __DATE__, __TIME__);
        commandProc();
    }else if(command == 'l'){
        printf("%s%s%s", F_RED, w0014, NORMAL);
        commandProc();
    }else if(command == 's'){
        if(storageModeSwitch == SHK_FALSE)
        {
            printf("%s%s%s", F_LIGHT_BLUE, w0023, NORMAL);
            storageModeSwitch = SHK_TRUE;
            commandProc();
        }else{
            printf("%s%s%s", F_LIGHT_BLUE, w0024, NORMAL);
            storageModeSwitch = SHK_FALSE;
            commandProc();
        }
    }else if(command == 'u'){
        if(storageModeSwitch == SHK_TRUE && resultsIndex >= 1)
        {
            storageCalc();
            commandProc();
        }else{
            printf("%s%s%s", F_YELLOW, w0025, NORMAL);
            configLog(4, __LINE__, __FILE__, __FUNCTION__);
            commandProc();
        }
    }else if(command == 'e'){
        configLog(0, __LINE__, __FILE__, __FUNCTION__);
        exit(0);
    }else if(command == 'q'){
        if(storageModeSwitch == SHK_TRUE)
            lookup.selectLookupMode();
        else{
            printf("%s%s%s", F_RED, w0019, NORMAL);
            configLog(4, __LINE__, __FILE__, __FUNCTION__);
        }
        commandProc();
    }else if(command == 'c'){
        if(storageModeSwitch == SHK_TRUE)
        {
            cleanResult();
            commandProc();
        }else{
            printf("%s%s%s", F_RED, w0019, NORMAL);
        }
    }else if(command == 'd'){
        deleteFile("ProgramLog.log");
    }else{
        printf("%s%s%s", F_RED, w0008, NORMAL);
        configLog(6, __LINE__, __FILE__, __FUNCTION__);
        commandProc(); 
    }
    commandProc();
}

int main(int argc, const char** argv)
{
    configLog(1, __LINE__, __FILE__, __FUNCTION__);
    if(argc > 2)
        immediateCalculate(argc, argv);
    #ifdef __WIN32
        system("cls");
    #endif
    if(argv[1] == NULL)
    {
        printf("%s%s%s", F_RED, w0004, NORMAL);
        printf("%s%s%s%s  %s\n", w0017, w0001, w0022, __DATE__, __TIME__);
        configLog(8, __LINE__, __FILE__, __FUNCTION__);
        commandProc();
    }else{
        if(strcmp(argv[1], "-n") == 0){
            printf("%s%s%s", F_RED, w0014, NORMAL);
            return 1;
        }else if(strcmp(argv[1], "-h") == 0){
            printf("%s%s%s", F_RED, w0014, NORMAL);
            return 1;
        }else if(strcmp(argv[1], "--bh") == 0){
            printf("%s%s%s  %s", w0001, w0022, __DATE__, __TIME__);
            return 0;
        }else if(strcmp(argv[1], "--basic") == 0){
            if(basicCalculate() != 0)
                printf("%s%s%s", F_RED, w0013, NORMAL);
            commandProc();
        }else if(strcmp(argv[1], "--storage") == 0){
            storageModeSwitch = SHK_TRUE;
            commandProc();
        }else if(strcmp(argv[1], "--cleanlog") == 0){
            deleteFile("ProgramLog.log");
            return 0;
        }else{
            printf("%s%s%s%s", F_RED, w0004, NORMAL, w0017);
            printf("%s%s%s  %s\n", w0001, w0022, __DATE__, __TIME__);
            configLog(8, __LINE__, __FILE__, __FUNCTION__);
            commandProc();
        }
    }
    printf("%s%s%s", F_RED, w0007, NORMAL);
    configLog(-1, __LINE__, __FILE__, __FUNCTION__);
    return 1;
}