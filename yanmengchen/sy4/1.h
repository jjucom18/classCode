#ifndef 1_h
#define 1_h

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Time
{
	int hour;
	int min;
}Time;
typedef struct CarNode
{
	char num[10];
	Time reach;
	Time leave;
}CarNode;
{
	CarNode *stack[MAX+1];
	int top;
}StackCar;
typedef struct QueueCarNode
{
	CarNode *data;
	struct QueueCarNode *next;
}QueueCarNode;
typedef struct LinkQueueCar
{
	QueueCarNode *head;
	QueueCarNode *rear;
}LinkQueueCar;

#endif
