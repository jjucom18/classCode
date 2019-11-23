#ifndef LINKQUEUE_H_INCLUDED
#define LINKQUEUE_H_INCLUDED
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#include "Car.h"
typedef   int Status;
typedef  Car QElemType;
typedef struct QNode{
     QElemType data;
     struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
     QueuePtr front;
     QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue *Q){
     Q->front=(QueuePtr)malloc(sizeof(QNode));
     if(!Q->front)
          exit(-1);
     Q->rear=Q->front;
     Q->front->next=NULL;
     return OK;
}

Status EnQueue(LinkQueue *Q,QElemType e){
      QueuePtr P=(QueuePtr)malloc(sizeof(QNode));
      if(!P)
         exit(-1);
      P->data=e;
      P->next=NULL;
      Q->rear->next=P;
      Q->rear=P;
      return OK;
}

Status DeQueue(LinkQueue*Q,QElemType *e){
      if(Q->front==Q->rear)
            return ERROR;
      QueuePtr P=Q->front->next;
      *e=P->data;
       Q->front->next=P->next;
       if(Q->rear==P)
           Q->rear=Q->front;
       free(P);
       return OK;
}

Status QueueLength(LinkQueue *Q){
       QueuePtr P=Q->front->next;
       int num=1;
       while(P->next!=NULL)
       {
           num++;
           P=P->next;
       }
       return num;
}
Status QueueEmpty(LinkQueue *Q){
      if(Q->front==Q->rear)
          return TRUE;
      else
          return  FALSE;
}

#endif // LINKQUEUE_H_INCLUDED
