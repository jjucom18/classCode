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
<<<<<<< HEAD
	int rear;
	int num;
}CSeqQueue;
=======
	int rear;int num;
}CSeQueue;
>>>>>>> e7a153a9433181112d265a68b7c81edd64035a62

CSeqQueue *initQueue();
bool emptyQueue(CSeqQueue *queue);
bool fullQueue(CSeqQueue *queue);
void inQueue(CSeqQueue *queue, DataType data);
void deQueue(CSeqQueue *queue, DataType *data);
void frontQueue(CSeqQueue *queue, DataType *data);
void rearQueue(CSeqQueue *queue, DataType *data);

#endif
