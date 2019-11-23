#ifndef tests_h
#define tests_h
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MaxStop 3
#define MaxWait 3
#define price 5

typedef struct {
	int CarNum[MaxStop];
	int CarTime[MaxStop];
	int top;
}SeqStack;

typedef struct {
	int CarNum[MaxWait];
	int front,rear;
}SeqQueue;


void InitStack(SeqStack *c1)
{
	c1=(SeqStack *)malloc(sizeof(SeqStack));
	c1->top=-1;
}

bool StackEmpty(SeqStack *c1)
{
	return(c1->top=-1);
}

bool StackFull(SeqStack *c1)
{
	return(c1->top==MaxWait);}

bool push(SeqStack *c1,int i,int j)
{if(c1->top==MaxWait-1)
	return false;
	c1->top++;
	c1->CarNum[c1->top]=i;
	c1->CarTime[c1->top]=j;
	return true;}

bool pop(SeqStack *c1,int i,int j)
{if(c1->top==-1)
	return false;
	else i=c1->CarNum[c1->top];
	j=c1->CarTime[c1->top];
	return true;}
void DispStack(SeqStack *c1)
{int m;
	for(m=c1->top;m>=0;m--)
		printf("%d",c1->CarNum[m]);
		
void InitQueue(SeqQueue *c2)
{c2=(SeqQueue *)malloc(sizeof(SeqQueue));
	c2->front=c2->rear=0;}

bool QueueEmpty(SeqQueue *c2)
{return(c2->front==c2->rear);}

bool QueueFull(SeqQueue *c2)
{return((c2->rear+1)%MaxWait==c2->front);}

bool InQueue(SeqQueue *c2,int i1)
{if((c2->rear+1)%MaxWait==c2->front)
return false;
c2->rear=(c2->rear+1)%MaxWait;
c2->CarNum[c2->rear]=i1;
return true;}

bool OutQueue(SeqQueue *c2,int i1)
{if(c2->front==c2->rear)
	return false;
	c2->front=(c2->front+1)%MaxWait;
	i1=c2->CarNum[c2->front];
	return true;}

void DispQueue(SeqQueue *c2)
{int m;
	m=(c2->front+1)%MaxWait;
	printf("候车的车牌号：%d\n",c2->CarNum[m]);
			while ((c2->rear-m+MaxWait)%MaxWait>0)
			{m=(m+1)%MaxWait;
			printf("%d",c2->CarNum[m]);}

#endif
