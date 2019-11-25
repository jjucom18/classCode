#ifndef ParkingSeq_h
#define ParkingSeq_h
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 2

typedef struct
{
	int hour;
	int minute;

}Time;

typedef struct
{
	int num;
	Time arrtime;
}CarNode;

typedef struct
{
	CarNode stack[MaxSize];
	int top;
}SqStackCar;

void InitSeqStack(SqStackCar *s) ;
int push(SqStackCar *s,CarNode x);	
CarNode pop(SqStackCar *s)	;
void Arrive(SqStackCar *stop,CarNode x);	
void Leave (SqStackCar *s1,SqStackCar *s2, CarNode y);

#endif
