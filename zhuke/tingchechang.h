#ifndef tingche_h
#define tingche_h

#include<stdio.h>
#include<stdlib.h>
#define error 0
#define ok 1
#define maxsize 4
#define stackincrement 10

typedef int selemtype;
typedef int status;
typedef struct
{
	char tag;
	int id;
	int time;
}DataType;

typedef struct
{
	DataType * stack;
	int top;
}SqStack;

status initstack (SqStack *ss)        //栈初始化
{
	ss->stack=(DataType *)malloc(maxsize * sizeof (DataType));
	if(!ss->stack)
		return 0;
	ss->top=0;
	return 1;
}

status push(SqStack *ss,DataType e)        //进栈
{
	if(ss->top==maxsize)
		printf("full\n");
	else
	{
		ss->top++;
		ss->stack[ss->top].id=e.id;
		ss->stack[ss->top].tag=e.tag;
		ss->stack[ss->top].time=e.time;
	}
	return 1;
}

DataType pop(SqStack *ss)        //出栈
{
	DataType e;
	if(ss->top==0)
	{
		printf("error");
		exit(0);
	}

	e.id=ss->stack[ss->top].id;
	e.tag=ss->stack[ss->top].tag;
	e.time=ss->stack[ss->top].time;
	ss->top--;
	return e;
}

typedef struct         //队列结构体定义
{
	DataType * queue;
	int rear;
	int front;
	int count;
}SqQueue;

void QueueInitiate(SqQueue *Q)        //队列初始化
{
	Q->queue=(DataType *)malloc(maxsize * sizeof(DataType));
	Q->rear=0;
	Q->front=0;
	Q->count=0;
}

int QueueAppend(SqQueue *Q,DataType x)       //入队列
{
	if(Q->count>0  && Q->rear-Q->front==maxsize)
	{
		printf("队列已满，无法入队列!\n");
		return 0;
	}
	else
	{
		Q->queue[Q->rear].id=x.id;
		Q->queue[Q->rear].tag=x.tag;
		Q->queue[Q->rear].time=x.time;
		Q->rear=(Q->rear+1)%maxsize;
		Q->count++;
		return 1;
	}
}

int QueueDelete(SqQueue *Q,DataType *d)         //出队列
{
	if(Q->count==0)
	{
		printf("队列已空，无法出队列!\n");
		return 0;
	}
	else
	{
		d->id=Q->queue[Q->front].id;
		d->tag=Q->queue[Q->front].tag;
		d->time=Q->queue[Q->front].time;
		Q->front=(Q->front+1)%maxsize;
		Q->count--;
		return 1;
	}
}

int QueueGet(SqQueue *Q,DataType *d)        //取队头数据元素
{
	if(Q->count==0)
	{
		printf("队列已空，无数据可取!\n");
		return 0;
	}
	else
	{
		d->id=Q->queue[Q->front].id;
		d->tag=Q->queue[Q->front].tag;
		d->time=Q->queue[Q->front].time;
		return 1;
	}
}

void Process(DataType car,SqStack *Park,SqStack * TemPark,SqQueue *Q)
{
	int fee;
	DataType d,tem;

	if(car.tag!='A' && car.tag!='D')
	{
		printf("输入错误，请重新输入：\n");
		getchar();
		return ;
	}
	else
	{
		if(car.tag=='A')
		{
			if(Park->top<maxsize)
			{
				push(Park,car);
				printf("%d号车停在停车场第%d个位置上\n",car.id,Park->top);
			}
			else
			{
				QueueAppend(Q,car);
				printf("停车场已满，%d号车停在便道第%d个位置上\n",car.id,Q->rear);
			}
		}
		else
		{
			if(car.id==Park->stack[Park->top].id)
			{
				tem=pop(Park);
				fee=car.time-tem.time;
				printf("%d号车离开停车场，需缴纳的费用为：%d元\n",tem.id,fee);
			}
			else
			{
				while(car.id!=Park->stack[Park->top].id)
				{
					tem=pop(Park);
					push(TemPark,tem);   //前面的车辆进入临时堆栈
					printf("%d号车暂时离开停车场，进入临时堆栈，停在临时堆栈第%d个位置上\n",tem.id,TemPark->top);
				}
				d=pop(Park);       //目标车辆出栈，车的信息由参数*d带回
				fee=car.time-d.time;
				printf("%d号车离开停车场，需缴纳的费用为：%d元\n",car.id,fee);
				while(TemPark->top>0)
				{
					tem=pop(TemPark);
					push(Park,tem);
					printf("%d号车重新进入停车场，停在停车场第%d个位置上\n",tem.id,Park->top);
				}
			}
			if(Q->front!=Q->rear)       //如果便道上还有车，则便道上的第一辆车进入停车场
			{
				QueueDelete(&Q,&tem);
				tem.time=car.time;      //将即将进入停车场的车的时间修改为刚刚从停车场离去的车的时间
				push(Park,tem);
				printf("%d号车从便道进入停车场，停在停车场第%d个位置上\n",tem.id,Park->top);
			}
		}
	}
}

#endif
