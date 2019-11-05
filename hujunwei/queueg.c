#include "queue.h"

typedef struct{
	        DataType data[MaxSize];
		        int front;
			        int rear;
}SeqQueue;

SeqQueue *initQueue(){
	        SeqQueue *queue = (SeqQueue *)malloc(sizeof(SeqQueue));
		        queue->front = -1;
			        queue->rear = -1;

				        return;
}

bool emptyQueue(SeqQueue *queue){
	        return queue->front == -1;
}

bool fullQueue(SeqQueue *queue){
	        return queue->rear == MaxSize - 1;
}

void inQueue(SeqQueue *queue, DataType data){
	        queue->rear++;
		        queue->data[queue->rear] = data;

			        return;
}

void deQueue(SeqQueue *queue, DataType *data){
	        queue->front++;
		        *data = queue->data[queue->front];

			        return;
}

void frontQueue(SeqQueue *queue, DataType *data){
	        *data = queue->data[queue->front + 1];

		        return;
}

void rearQueue(SeqQueue *queue, DataType *data){
	        *data = queue->data[queue->rear + 1];

		        return;
}
