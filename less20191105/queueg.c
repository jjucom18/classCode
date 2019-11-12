
#include "queueg.h"

typedef struct{
	DataType data[MaxSize];
	int front;
<<<<<<< HEAD
	int rear;
}CSeqQueue;

CSeqQueue *initQueue(){
	CSeqQueue *queue = (CSeqQueue *)malloc(sizeof(CSeqQueue));
	queue->front = -1;
	queue->rear = -1;
=======
	int rear;int num;
}CSeqQueue;

CSeQueue *initQueue(){
	CSeQueue *queue = (CSeQueue *)malloc(sizeof(CSeQueue));
	queue->front =queue->rear=MAXSIZE-1;
	queue->num = 0;
>>>>>>> e7a153a9433181112d265a68b7c81edd64035a62

return ;
}

<<<<<<< HEAD
bool emptyQueue(CSeqQueue *queue){
	return queue->front == -1;
}

bool fullQueue(CSeqQueue *queue){
	return queue->rear == MaxSize - 1;
}

void inQueue(CSeqQueue *queue, DataType data){
=======
bool emptyQueue(CSeQueue *queue){
	return queue->front == -1;
}

bool fullQueue(CSeQueue *queue){
	return queue->rear == MaxSize - 1;
}

void inQueue(CSeQueue *queue, DataType data){
>>>>>>> e7a153a9433181112d265a68b7c81edd64035a62
	queue->rear++;
	queue->data[queue->rear] = data;

	return;
}

<<<<<<< HEAD
void deQueue(CSeqQueue *queue, DataType *data){
=======
void deQueue(CSeQueue *queue, DataType *data){
>>>>>>> e7a153a9433181112d265a68b7c81edd64035a62
	queue->front++;
	*data = queue->data[queue->front];

	return;
}

<<<<<<< HEAD
void frontQueue(CSeqQueue *queue, DataType *data){
=======
void frontQueue(CSeQueue *queue, DataType *data){
>>>>>>> e7a153a9433181112d265a68b7c81edd64035a62
	*data = queue->data[queue->front + 1];

	return;
}

<<<<<<< HEAD
void rearQueue(CSeqQueue *queue, DataType *data){
=======
void rearQueue(CSeQueue *queue, DataType *data){
>>>>>>> e7a153a9433181112d265a68b7c81edd64035a62
	*data = queue->data[queue->rear + 1];

	return;
}
