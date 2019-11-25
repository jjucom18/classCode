#ifndef  parking_h
#define  parking_h
#include <stdio.h>
#include <stdlib.h>
#define N 10 //停车场内最多的停车数
#define M 10 //候车场内最多的停车数
#define Price 2 //每单位时间停车费用
typedef struct
{
int CarNo[N]; //车牌号
int CarTime[N];//进场时间
int top; //栈指针
} SqStack; //定义顺序栈类型，用于描述停车场

typedef struct
{
int CarNo[M]; //车牌号
int front,rear; //队首和队尾指针
} SqQueue; //定义循环队类型，用于描述候车场



#endif
