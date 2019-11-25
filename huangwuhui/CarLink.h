#ifndef CarLink_h
#define CarLink_h
#include<stdio.h>
#include<stdlib.h>

#define PRICE 0.05
typedef int datatype;
typedef struct node
{
	int num;
	struct node *next;
}QueueNode;
typedef struct
{
	QueueNode *front,*rear;
}LinkQueueCar;

void InitLinkQueue(LinkQueueCar *q);
void EnLinkQueue(LinkQueueCar *q,int x);
int DeLinkQueue(LinkQueueCar *q);
void Arrive(LinkQueueCar *lq);
void Leave(LinkQueueCar *p);

#endif	
