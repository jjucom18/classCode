

#include "queue.h"

typedef struct{
	DataType data[MAXSIZE];
	int front;
	int rear;
	int num;
}SeqsQueue;

SeqQueue *initQueue(){
	SeqQueue *queue = (SeqQueue *)malloc(sizeof(SeqQueue));
	queue->front =queue->rear =MAXSIZE -1;
	queue->num=0;

	return queue;
}

bool emptyQueue(SeqQueue *queue){
	if(q->num == 0)
		printf("队空");
	return 1;}

bool fullQueue(SeqQueue *queue){
	if (q->num == MAXSIZE)
		printf("队满");
	return 1;} 

void inQueue(SeqQueue *queue, DataType data){
	if (q->num == MAXSIZE){
		printf("队满")；
			return -1;
	}else {
		q->rear =(q->rear+1)%MAXSIZE;
		q->data[q->rear]=x;
		q->num++;
		return 1;
	}
}
void outQueue(SeqQueue *queue,Datatype *data) 
{
		if(q->num==0){
		printf("队空");
		return -1;
		}
		else{
		q->front=(q->front+1)%MAXSIZE;
		*x=q->data[q->front];
		q->num--;
		return 1;
		     }
		}

