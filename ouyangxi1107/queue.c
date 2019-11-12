#include "queue.h"

#define MAXSIZE 10
typedef int datatype;
typedef struct{
    datatype data[MAXSIZE];
    int front;
    int rear;
    int num;
}CSeqQueue;

CSeqQueue *initQueue(){
CSeqQueue *queue =(CSeqQueue*)malloc(sizeof(CSeQueue));
q->front=q->rear=MAXSIZE-1;
q->num=0;
return q;
}
bool emptyQueue(CSeqQueue *queue){
if(q=->num==0)
   {printf("队空");
   return 1;}
else return 0;
};
bool fullQueue(CSeqQueue *queue)
{if(q=->num==MAXSIZE)
	{printf("队满");
  return -1; }
 else   return 0;
};	
void inQueue(CSeqQueue *queue,datatype data){
   if(q->num==MAXSIZE)
   {printf("队满");
  return -1; }
   else{
	q>rear=(q=->rear+1)%MAXSIZE;
   q->data[q->rear]=x;
   q->num++;
return 1;}
}

void deQueue(CSequeue *queue,datatype * data){
if(q->num==0)
   {printf("队空")；
	 return -1;
   }	 

else{  q->front=(q->front+1)%MAXSIZE;
   *x=q->data[q->front];
   q->num--;
   return 1;}
}
void frontQueue(CSeqQueue *queue,datatype *data);
{*data=queue->data[queue->front+1];
return;
}
void rearQueue(CSeqQueue *queue,datatype *data){
*data=queue->data[queue->rear+1];
return;  
}
