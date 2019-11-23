#ifndef ParkingLink_h
#define ParkingLink.h
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 2
typedef struct node
{
	int num;
	struct node *next;
}QueueNode;

typedef struct
{
	QueueNode *front,*rear;
}LinkQueueCar;

void InitLinkQueue(LinkQueueCar *q)
void EnLinkQueue(LinkQueueCar *q,int x)	
int DeLinkQueue(LinkQueueCar *q)	
void Arrive(SeStackCar *stop,LinkQueueCar *lq,CarNode x)	
void Leave(SqStackCar *s1,SqStacker *s2,LinkQueueCar *p,CarNode y)	

#endif

