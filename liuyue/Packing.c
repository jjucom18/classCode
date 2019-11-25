#include<stdio.h>
#include<stdlib.h>
#define MaxSize 2
#define PRICE 0.05
typedef struct
{
	int hour;
	int minute;

}Time;

typedef struct
{
	int num;
	Time arrtime;
}CarNode;

typedef struct
{
	CarNode stack[MaxSize];
	int top;
}SqStackCar;

typedef struct node
{
	int num;
	struct node *next;

}QueueNode;

typedef struct
{
	QueueNode *front,*rear;

}LinkQueueCar;

void InitSeqStack(SqStackCar *s)
{
	s->top==-1;
}
int push(SqStackCar *s,CarNode x)
{
	if(s->top==MaxSize-1)
		return(0);
	else
	{
		s->stack[++s->top]=x;
		return(1);
	}
}
CarNode pop(SqStackCar *s)
{
	CarNode x;
	if(s->top<0)
	{
		x.num=0;
		x.arrtime.hour=0;
		x.arrtime.minute=0;
		return(x);
	}
	else
	{
		s->top--;
		return(s->stack[s->top+1]);
	}
}/*pop*/

void InitLinkQueue(LinkQueueCar*q)
{
	q->front=(QueueNode*)malloc(sizeof(QueueNode));
	if(q->front!=NULL)
	{
		q->rear=q->front;
		q->front->next=NULL;
		q->front->num=0;
	}
}/*InitQueue*/

void EnLinkQueue(LinkQueueCar *q,int x)
{
	QueueNode *p;
	p=(QueueNode*)malloc(sizeof(QueueNode));
	p->num=x;
	p->next=NULL;
	q->rear->next= p;
	q->rear=p;
	q->front->num++;
}/*EnLinkQueue*/

int DeLinkQueue(LinkQueueCar *q)
{
	QueueNode *p;
	int n;
	if(q->front==q->rear)
		return(0);
	else
	{
		p= q->front->next;
		q->front->next=p->next;
		if(p->next=NULL)
			q->rear=q->front;
		n=p->num;
		free(p);
			q->front->num--;
		return(n);
	}
}/*DeLinkQueue*/

void Arrive(SqStackCar *stop,LinkQueueCar *lq,CarNode x)
{
	int f;
	f=push(stop,x);
	if(f==0)
	{
		EnLinkQueue(lq,x.num);
		printf("\n第%d号车停在便道第%d号车位上",x.num,lq->front->num);
	}
	else
		printf("\n第%d号车停在停车场第%d车位上",x.num,stop->top+1);
}/*Arrive*/

void leave(SqStackCar *s1,SqStackCar *s2,LinkQueueCar *p,CarNode x)
{
	int n,f=0;
	CarNode y;
	QueueNode *q;
	while((s1->top>-1)&&(f!=1))
	{
		y=pop(s1);
		if(y.num!=x.num)
			n=push(s2,y);
		else
			f=1;
	}
	if(y.num=x.num)

	{
		
        printf("第%d号车应收费%2.1f元\n",y.num,(x.arrtime.hour-y.arrtime.hour)*60+((x.arrtime.minute)-(y.
 						arrtime.minute))*PRICE) ;
		while(s2->top>-1)
		{
			y=pop(s2);
			f=push(s1,y);
		}
		n=DeLinkQueue(p);
		if(n!=0)
		{
			y.num=n;
			y.arrtime=x.arrtime;
			f=push(s1,y);
			printf("第%d号车停在停车场第%d号车位上\n",y.num,s1->top+1);
		}
		else
		{
			while(s2->top>-1)
			{
				y=pop(s2);
				f=push(s1,y);
			}
			q=p->front;
			f=0;
			while(f==0&&q->next!=NULL)
				if(q->next->num!=x.num)
					q= q->next;
				else
				{
					q->next=q->next->next;
					p->front->num--;
					if(q->next==NULL)
						p->rear=p->front;
					printf("第%d号车离开便道\n",x.num);
					f=1;
				}
			if(f==0)
				printf("输入数据错误，停车场和便道上均无第%d号车\n",x.num);
		}
	}/*leave*/
}

