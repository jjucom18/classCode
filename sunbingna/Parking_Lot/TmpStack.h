#ifndef TmpStack_h
#define TmpStack_h
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 3
typedef struct _car{
        bool arrive;
        bool leave;
        char number[30];
        time_t atime;
        time_t ltime;
        double price;
}Car;

typedef struct TmpStack
{
    Car data[MaxSize];
    int top;
}TmpStack;

TmpStack *InitTmpStack();
int EmptyTmp(TmpStack *s);
int FullTmp(TmpStack *s);
void PushTmpStack(TmpStack *s, Car data);
void PopTmpStack(TmpStack *s, Car *data);
void TopTmpStack(TmpStack *s, Car *data);
#endif
