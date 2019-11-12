#include"queue.h"

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

int main (int argc, char **argv)
{
	SeqQueue *initQueue();
	if(emptyQueue(stack))
	{
		printf("empty\n");
	}
	DataType arr[] = {23 45 35 73 18 34 69};
	int size = sizeof(arr)/sizeof(arr[0]);

	for(int i=0;i<size;i++)
	{
		inQueue(queue,arr[i]);
	}
	if(emptyQueue(queue))
	{
		printf("empty\n");
	}
	else printf("not empty\n");
}


SeqQueue *initQueue()
{
	SeqQueue *queue=(SeqQueue *)malloc(sizeof(SeqQueue));
	queue->front=pueue->rear=-1;
	return queue;
}

bool emptyQueue(SeqQueue *queue)
{
	return queue->front=-1;
}

bool fullQueue(SeqQueue *queue)
{
	return queue->rear=MaxSize-1;
}

void inQueue(SeqQueue *queue,DataType data)
{
	if(fullQueue(queue)) return;	
	else 
	{
		queue->rear++;
		queue->data[queue->rear]=x;
	}
}

void deQueue(SeqQueue *queue,DataType *data)
{
	if(emptyQueue(queue))
	{
		return;
	}
	else
	{
		queue->front++;
		x=queue->data[q->front]
	}
}

void frontQueue(SeqQueue *queue,DataType *data)
{
	*data = queue->data[queue->front+1];

	return;
}

void rearQueue(SeqQueue *queue，DataType *data)
{
	*data = queue->data[queue->rear+1];

	return;
}


