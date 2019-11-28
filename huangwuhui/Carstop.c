#include<stdio.h>
#include<stdlib.h>
#define MaxSize 20
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
      void InitSeqStack(SqStackCar *s)/*初始化栈*/
{
	s->top=-1;
}
      int push(SqStackCar *s,CarNode x)/*数据元素x入指针s所指的栈*/
{
	if(s->top==MaxSize-1)
		return (0);/*如果栈满，返回0*/
	else
	{
		s->stack[++s->top]=x;/*栈不满，到达车辆入栈*/
		return (1);
	}
}
       CarNode pop(SqStackCar *s)/*栈顶元素出栈*/
{
	CarNode x;
	if(s->top<0)
	{
		x.num=0;
		x.arrtime.hour=0;
		x.arrtime.minute=0;
		return(x);/*如果栈空，返回空值*/
	}
	else
	{
		s->top--;
		return(s->stack[s->top+1]);/*栈不空，返回栈顶元素*/
	}
}
      void InitLinkQueue(LinkQueueCar *q)/*初始化队列*/
{
	q->front=(QueueNode*)malloc(sizeof(QueueNode));/*产生一个新节点，作头节点*/
	if(q->front!=NULL)
	{
		q->rear=q->front;
		q->front->next=NULL;
		q->front->num=0;/*头节点的num保存队列中数据元素的个数*/
	}
}
      void EnLinkQueue(LinkQueueCar *q,int x)/*数据入队列*/
{
	QueueNode *p;
	p=(QueueNode *)malloc(sizeof(QueueNode));/*产生一个新结点*/
	p->num=x;
	p->next=NULL;
	q->rear->next=p;/*新结点入队列*/
	q->rear=p;
	q->front->num++;/*队列元素加1*/
}
      int DeLinkQueue(LinkQueueCar *q )/*数据出队列*/
{
	QueueNode *p;
	int n;
	if(q->front==q->rear)
		return(0);/*如果队列空，返回空值*/
	else
	{
		p=q->front->next;
		q->front->next=p->next;/*返回对头元素值*/
		if(p->next==NULL)
			q->rear=q->front;
		n=p->num;
		free(p);
			q->front->num--;/*队列元素减1*/
		return(n);
	}
}
    void Arrive(SqStackCar *stop,LinkQueueCar *lq,CarNode x)/*处理车辆达到的情况*/
{
	int f;
	f=push(stop,x);/*新到达的车辆入停车场栈*/
	if(f==0)
	{
		EnLinkQueue(lq,x.num);/*如停车场满，就进入便道队列*/
		printf("第%d号车停在便道%d号车位上\n",x.num,lq->front->num);
	}
	else/*新到达的车辆入停车场*/
		printf("第%d号车停在停车场第%d车位上\n",x.num,stop->top+1);
}
    void Leave(SqStackCar *s1,SqStackCar *s2,LinkQueueCar *p,CarNode x,...)/*处理车辆离去的情况*/
{
	int n,f=0;
	CarNode y;
	QueueNode *q;
	while ((s1->top>-1)&&(f!=1))/*在停车场中寻找要离开的车辆*/
	{
		y=pop(s1);
		if(y.num!=x.num)/*如果栈顶元素不是要离开的车辆，就将其放入车辆暂停处*/
			n=push(s2,y);
		else
			f=1;
	}
	if(y.num==x.num)/*在停车场中要找到离开的车辆*/
	{
		printf("\n第%d号车应收费%2.1f元",y.num,(x.arrtime.hour-y.arrtime.hour)*60+
				((x.arrtime.minute-y.arrtime.minute))*PRICE);
		while(s2->top>-1)
		{
			y=pop(s2);
			f=push(s1,y);
		}
		n=DeLinkQueue(p);
		if(n!=0)
		{
			y.num=n;
			y.arrtime=x.arrtime;/*计费时间为刚离开车辆离去时间*/
			f=push(s1,y);
			printf("第%d号车停在停车场第%d号车位上\n",y.num,s1->top+1);
		}
	}
	else/*在停车场没有找到要离开的车辆*/
	{
		while(s2->top>-1)
		{
			y=pop(s2);
			f=push(s1,y);
		}
		q=p->front;
		f=0;
		while(f==0&&q->next!=NULL);/*在便道上寻找要离开的车辆*/
		if(q->next->num!=x.num)
			q=q->next;
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
}
