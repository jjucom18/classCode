#ifndef TCqueue_h
#define TCqueue_h

#include<stdio.h>


typedef struct time{
	int min;
	int hour;

}Time;

typedef struct node{
	char num[10];
	Time arrive;
	Time leave;

}CarNode;

typedef struct car{
	CarNode *data;
	struct car *next;
}QueueNode;

typedef struct Node{
	QueueNode *head;
	QueueNode *rear;
}LinkQueueCar;

int QueueInit(LinkQueueCar *Q);
int Arrival(LinkQueueCar *W);
void print(CarNode *p ,int room);
void List1(LinkQueueCar *W);
void Leave(LinkQueueCar *W);

#endif
