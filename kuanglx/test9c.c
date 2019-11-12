#ifndef queue_h
#define queue_h
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MaxSize 10
typedef int DataType;
typedef struct{
	Data Type data[Maxsize];
	int front;
	int rear;
}SeqQueue;

SeqQueue *initQueue();
bool emptyQueue(SeqQueue *queue);
bool fullQueue(SeqQueue *queue);
void in














