#ifndef tingchechang_h
#define tingchechang_h
#define F 0
#define T 1
#define Max 3
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>




typedef struct Node {  
	int number;
	int time;

}Node;

typedef struct QueueNode{
    struct Node inform;
	struct QueueNode * next;
}*QueueNode;

typedef struct LinkQueue{
 struct	QueueNode * front ;
 struct	QueueNode * rear  ;
}LinkQueue;

typedef struct stack{
	struct Node data;
	struct stack * next;
}*stackNode;

typedef struct Linkstack{
	stackNode top;
	int count ;
}Linkstack;
      

void menu(LinkQueue *wait,LinkQueue *par,Linkstack *giveway,int num ,int t);
int  init(LinkQueue *wait,LinkQueue *park,Linkstack *giveway);
int  linklength(LinkQueue q);
int  inqueue(LinkQueue *q,int num,int t);
int  outqueue(LinkQueue *q,int *num ,int *t);
void park1(LinkQueue *wait,LinkQueue *park);
int  push(Linkstack *s,int num,int t);
int  pop (Linkstack *s,int *num,int *t);
void leave2(LinkQueue *wait,LinkQueue *park,Linkstack *giveway,int num,int t);
void view3(LinkQueue wait,LinkQueue park);



#endif









