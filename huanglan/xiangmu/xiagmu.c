#include <string.h>
#include<stdio.h>
#include<time.h>
#include<malloc.h>
#define TRUE 1
#define FALSE 0
#define OK1
#define ERROR 0
#define Overfloe -1
typedef int system;
typedef struct QNode{
	int num;
	struct QNode*next;
}QNode,*QueuePtr;
typedef struct{
QueuePtr front;
QueuePtr rear;
}LinkQueue;
void sleep(clock_t wait)//延迟函数
{
	clock_t goal;
	goal = wait +clock();
	while(goal>clock());
}
void InitQ(LinkQueue &Q)//建立空队列,初始化队列
{
QueuePtr p;
p=(QueuePtr)malloc(sizeof(QNode));
Q.front=p;
Q.rear=p;
Q.front->next=NULL;
}
void EnQueue(LinkQueue&Q.int num)//入队函数
{
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	p->num=num;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
}
void DeQueue(LinkQueue &Q,int &num)//出队函数
{
QueuePtr p,q;
if (Q.front==Q.rear)
printf("队列为空");
p=Q.front->next;
num=p->num;
Q.front->next=p->next;
q=p->next;
if (Q.rear==q)
	Q.rear=Q.front;
free(p);
}
void printF(LinkQueue &F,int i)//打印第i首曲子时女队的情况
{
	QueuePtr p;
	int n=1;
	while (n<i){
		printf("_");
		n++;
	}
	p=F.front->next;
	while(F.rear!=p){
		printf("%d",p->num);
		p->next;}
	printf("%d\n",p->num);
}
void printM(LinkQueue &M,int i)//打印第i首曲子时女队的情况
{
	QueuePtr p;
	int n=1;
	while (n<i){
		printf("_");
		n++;
	}
	p=M.front->next;
	while(M.rear!=p){
		printf("%d",p->num);
		p->next;}
	printf("%d\n",p->num);} 
