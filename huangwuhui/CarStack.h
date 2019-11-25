#ifndef CarStack_h
#define CarStack_h
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 20
typedef struct
{
	int hour;
	int minute;
}Time;
typedef struct
{
	int num;
	Time arrive;
}CarNode;
typedef struct
{
	CarNode stack[MaxSize];
	int pop;
}SqStackCar;

typedef int datatype;


void InitSeqStack(SqStackCar *s)
int push(SqStackCar *s,CarNode x)
CarNode pop(SqStackCar *s)
void Arrive(SqStackCar *stop,LinkQueueCar *lq,CarNode x)
void Leave(SqStackCar *s1,SqStackCar *s2,LinkQueueCar *p,CarNode x,)

#endif	

