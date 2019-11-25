#include <stdio.h>
#include <malloc.h>
#define N 10//停车场最多的停车数
#define M 10//候车处最大停车数
#define Price 1//单位时间内所需费用
typedef struct{
	int CarNum[N];//车牌号
	int Time[N];//进场时间
    int top;
}SqStack;
typedef struct{
	int CarNum[M];
	int front,rear;
}SqQueue;
void Init_SqStack(SqStack *s){
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
}
int StackEmpty(SqStack *s){
	return(s->top==-1);
} 
int StackFull(SqStack *s){
	return(s->top==N-1);
}
int Push(SqStack *s,int e1,int e2){
	if (s->top==N-1)
		return 0;
	s->top++;
	s->CarNum[s->top]=e1;
	s->Time[s->top]=e2;
    return 1;
}
int Pop(SqStack *s,int e1,int e2){
	if(s->top==-1)
		return 0;
	e1=s->CarNum[s->top];
	e2=s->Time[s->top];
	s->top--;
    return 1;
}
void DispStack(SqStack *s){
	int i;
	for(i=s->top;i>=0;i--)
		printf("%d",s->CarNum[i]);
	printf("\n");
}

//循环队列
void InitQueue(SqQueue *q) {
	q=(SqQueue *)malloc(sizeof(SqQueue));
	q->front=q->rear=0;
}
int QueueEmpty(SqQueue *q){
	return(q->front==q->rear);
}
int QueueFull(SqQueue *q){
	return(q->rear+1%M==q->front);
}
int enQueue(SqQueue *q,int e){
	if (q->rear+1%M==q->front) ;
	return 0;
	q->rear=(q->rear+1)%M;
	q->CarNum[q->rear]=e;
	return 1;
}
int deQueue(SqQueue *q,int e){
	if(q->front==q->rear)
		return 0;
	q->front=(q->front+1)%M;
	e=q->CarNum[q->front];
	return 1;
}
void DispQueue (SqQueue *q)
{
	int i;
	i=(q->front+1)%M;
	printf("%d",q->CarNum[i]);
	while((q->rear-i+M)%M>0){
		i=(i+1)%M;
        printf("%d",q->CarNum[i]);
	}
	printf("\n");
}
