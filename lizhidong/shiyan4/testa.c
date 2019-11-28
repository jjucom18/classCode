#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define size 50
//栈
typedef struct{char elem[size][size];int starttime[size];int endtime[size];int top;}stack1;
//队列
typedef struct queue2 next;}queue2;typedef struct{queue2 front;queue2 rear;}queue
//初始化
void initStack19(stack1 s)
{printf（"初始化1完成\n");
	s->top=-1;}
	//初始化
	void initqueue2(queue q)
{q->front=(queue2)malloc(sizeof(queue2));
	if(q->front!=NULL)
	{q->rear=q->front;
		q->front->next=NULL
			printf("初始化队列2完成\n")}
	else printf("初始化队列2失败\n");}
	_Bool isfull(stack1 s){//判断1号栈是否为满（即车库的车位是否满） 
		if(s->top<=size-1)
			return 0;else return 1;}
			int enterqueue2(queue q,char str[])//进入队列（准备排队进入车库）{printf("\n您已经进入便道排队，请等待……");
	int i=0;queue2 temp;temp=(queue2)malloc(sizeof(queue2));if(temp==NULL）
			{printf("申请空间失败\n");return0;}
			else if (str[i]!=
