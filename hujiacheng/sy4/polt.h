#ifndef polt_h
#define polt_h

#include <stdio.h>
#include <stdlib.h>


#define maxnum 5
typedef struct time
{
	int hour;
        int min;	
}Time;
typedef struct node 
{
	char num[10];
	Time reach;
	Time leave;
}CarNode;
typedef struct NODE
{
	CarNode *stack[maxnum+1];
	int top;
}SeqStackCar;
typedef struct car 
{
	CarNode *data;
	struct car *next;
}QueueNode;
typedef struct Node
{
	QueueNode *head;
	QueueNode *rear;
}LinkQueueCar;

void StackInit(SeqStackCar *s);
int  QueueInit(LinkQueueCar *Q);
void Print(CarNode *p,int room);
void list1(SeqStackCar *S);
void list2(LinkQueueCar *W);
void list(SeqStackCar S,LinkQueueCar W);
int Arrival (SeqStackCar *Enter ,LinkQueueCar *W);
void Leave (SeqStackCar *Enter ,SeqStackCar * Temp ,LinkQueueCar *W);




#endif
