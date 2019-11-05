
#include "queue.h"

typedef struct{
	DataType data[MaxSize];
	int front;
	int rear;int num;
}CSeqQueue;

CSeQueue *initQueue(){
	CSeQueue *queue = (CSeQueue *)malloc(sizeof(CSeQueue));
	queue->front =queue->rear=MAXSIZE-1;
	queue->num = 0;

return ;
}

bool emptyQueue(CSeQueue *queue){
	return queue->front == -1;
}

bool fullQueue(CSeQueue *queue){
	return queue->rear == MaxSize - 1;
}

void inQueue(CSeQueue *queue, DataType data){
	queue->rear++;
	queue->data[queue->rear] = data;

	return;
}

void deQueue(CSeQueue *queue, DataType *data){
	queue->front++;
	*data = queue->data[queue->front];

	return;
}

void frontQueue(CSeQueue *queue, DataType *data){
	*data = queue->data[queue->front + 1];

	return;
}

void rearQueue(CSeQueue *queue, DataType *data){
	*data = queue->data[queue->rear + 1];

	return;
}
