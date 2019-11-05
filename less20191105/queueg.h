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
	int num;
}CSeqQueue;

CSeqQueue *initQueue();
bool emptyQueue(CSeqQueue *queue);
bool fullQueue(CSeqQueue *queue);
void inQueue(CSeqQueue *queue, DataType data);
void deQueue(CSeqQueue *queue, DataType *data);
void frontQueue(CSeqQueue *queue, DataType *data);
void rearQueue(CSeqQueue *queue, DataType *data);

#endif
