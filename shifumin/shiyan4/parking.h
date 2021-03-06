#ifndef parking_h
#define parking_h
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20//停车场最大容量
#define price 0.05
#define pricee 0.5

typedef struct NODE{
 CarNode *stack[MAX+1];
 int top;
}SeqStackCar;//便道的栈顺序存储

typedef struct Car{
	CarNode *data;
	struct car *next;
}QueueNode;//队列的链式存储

typedef struct Node{
	QueueNode *head;
	QueueNode *rear;
}LinkQueueCar;//便道上等候的队列定义

typedef struct time{
	int hour;
	int min;
}Time;//定义时间结构体

typedef struct node{
	char num[10];
	Time reach;
	Time leave;
}CarNode;//定义车辆信息结构体

void InitStack(SeqStackCar *);
int InitQueue(LinkQueueCar *);
int Arrival(SeqStackCar *,LinkQueueCar *);
void Leave(SeqStackCar *,SeqStackCar *,LinkQueueCar *);
void List(SeqStackCar,LinkQueueCar);

#endif
