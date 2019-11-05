
#include "queueg.h"

typedef struct{
	DataType data[MaxSize];
	int front;
	int rear;
}CSeqQueue;

CSeqQueue *initQueue(){
	CSeqQueue *queue = (CSeqQueue *)malloc(sizeof(CSeqQueue));
	queue->front = -1;
	queue->rear = -1;

	return;
}

bool emptyQueue(CSeqQueue *queue){
	return queue->front == -1;
}

bool fullQueue(CSeqQueue *queue){
	return queue->rear == MaxSize - 1;
}

void inQueue(CSeqQueue *queue, DataType data){
	queue->rear++;
	queue->data[queue->rear] = data;

	return;
}

void deQueue(CSeqQueue *queue, DataType *data){
	queue->front++;
	*data = queue->data[queue->front];

	return;
}

void frontQueue(CSeqQueue *queue, DataType *data){
	*data = queue->data[queue->front + 1];

	return;
}

void rearQueue(CSeqQueue *queue, DataType *data){
	*data = queue->data[queue->rear + 1];

	return;
}
