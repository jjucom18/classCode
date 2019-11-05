#ifndef queue_h
#define queue_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 10
typedef int DataType;
typedef struct{
	        DataType data[MaxSize];
		        int front;
			        int rear;
}SeqQueue;

SeqQueue *initQueue();
bool emptyQueue(SeqQueue *queue);
bool fullQueue(SeqQueue *queue);
void inQueue(SeqQueue *queue, DataType data);
void deQueue(SeqQueue *queue, DataType *data);
void frontQueue(SeqQueue *queue, DataType *data);
void rearQueue(SeqQueue *queue, DataType *data);

#endif
~                                         
