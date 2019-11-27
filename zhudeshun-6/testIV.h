#ifndef sorts_h
#define sorts_h
#include <stdio.h>     
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
#define MaxSize 100
#define QNODE struct QNode
typedef struct Node        //车辆信息
{
		char AL;
			int NO;
				int time;
}Node;
typedef struct Stack        //栈定义
{
		struct Node    data[MaxSize];
			int top;
				int num;
}SqStack;
QNODE              //队列节点
{
		struct Node data;
			QNODE *next;
};
typedef struct linkqueue      //队列结构体定义
{
		QNODE *front,*rear;
			int num;
}LinkQueue;
SqStack *Init_SeqStack();        //置空栈
LinkQueue *Init_LQueue();       //创建空队列
int ISEmpty_SeqStack(SqStack *s); 
int ISEmpty_SeqStack(SqStack *s); 
int ISEmpty_LQueue(LinkQueue *q);
void IN_Lqueue( LinkQueue *q,struct Node s);
void Push_SeqStack(SqStack *p,struct Node s);
int POP_SeqStack(SqStack *s,struct Node car);
struct Node Out_LQueue(LinkQueue *q);
#endif
