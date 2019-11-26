#ifndef park_h
#define park_h

#include<stdio.h>
#include<malloc.h>

#define N 3 //最大停车数
#define M 3 //最大候车数
#define Price 1 //停车费/每小时
typedef struct{
	int num[N];//车牌号
	int time[N];//进场时间
	int top;
}SqStack;
typedef struct{
	int num[M];//车牌号
	int front,rear;	
}SqQueue;
void InitStack(SqStack *s) ;
int StackEmpty(SqStack *s)  ;
int StackFull(SqStack *s)  ;
int Push(SqStack *s,int i,int j) ;       
int Pop(SqStack *s,int i,int j) ;
void DispStack(SqStack *s)  ;


void InitQueue(SqQueue *q) ;   
int QueueEmpty(SqQueue *q)  ; 
int QueueFull(SqQueue *q)  ;    
int InQueue(SqQueue *q,int e) ; 
int OutQueue(SqQueue *q,int e) ;
void DispQueue(SqQueue *q) ;
#endif
