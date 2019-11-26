#include "sorts.h"
SqStack *Init_SeqStack()        //置空栈
{
	s=(SqStack*)malloc(sizeof(SqStack));
	s->top=-1;
	s->num=0;
	return s;
}
LinkQueue *Init_LQueue()        //创建空队列
{
	LinkQueue *q;
	QNODE *p;
	q=(LinkQueue*)malloc(sizeof(LinkQueue));
	p=(QNODE*)malloc(sizeof(QNODE));
	p->next=NULL;
	q->front=q->rear=p;
	q->num=0;
	return q;
}

int ISEmpty_SeqStack(SqStack *s)        //判断栈是否为空，栈为空返回1
{
	if(s->top ==-1)
	return 1;
	else
	return 0;
}
int ISEmpty_SeqStack(SqStack *s)     //判断栈是否已满，若栈满返回1
{
	if(s->top==n-1)
	return 1;
	else
	return 0;
}
int ISEmpty_LQueue(LinkQueue *q)        //判断队列是否为空，队列为空返回1
{
	if(q->front==q->rear)
	return 1;
	else
	return 0;
}
void IN_Lqueue(    LinkQueue *q,struct Node s)  //入队
{
	QNODE *p;
	p=(QNODE*)malloc(sizeof(QNODE));
        p->data=s;
	q->num++;
	p->next=NULL;
	q->rear->next =p;
	q->rear =p;
}
void Push_SeqStack(SqStack *p,struct Node s)  //入栈
{
	p->top ++;
	p->data[p->top]=s;
	p->num++;
}
int POP_SeqStack(SqStack *s,struct Node car)//出栈
{
	SqStack *p;
	int t;
	p=Init_SeqStack();
	while(s->data[s->top].NO !=car.NO)//找到车牌号为P.NO的车，
	{
	Push_SeqStack(p,s->data[s->top]);
	s->top--;
	s->num--;
		}
	t=car.time-s->data[s->top].time;
	s->top--;
	s->num--;
	while(ISEmpty_SeqStack(p)==0)
	{
	Push_SeqStack(s,p->data[p->top]);
	p->top--;
	p->num--;
		}
	return t;
}
struct Node Out_LQueue(LinkQueue *q)  //出队
{
	QNODE *p;
	p=q->front->next;
	q->front->next=p->next;
	q->num --;
	if(    q->front->next==NULL)
	q->rear=q->front;
	return p->data;
	free(p);							
}
