#ifndef qimo2_h
#define qimo2_h

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 4
#define MAXSIZE1 10
#define Date int
#define FEE 1
#define MaxSize 100
#define MaxRoad 1000
#define N 11

typedef struct {
    Date Selem[MAXSIZE1];
    int top;
    int TIME[MAXSIZE1];
} SeqStack;

typedef struct {
    Date Qelem[MAXSIZE];
    int front;
    int rear;
} SeqQueue;
 
typedef struct{
    int length[N][N];
    int m,n;
}MGraph; 

void InitStack(SeqStack *S);
int Push(SeqStack *S,Date e);
int Pop(SeqStack *S, Date *e);

void InitQueue(SeqQueue *Q);
int EnQueue(SeqQueue *Q,Date e);
int DeQueue(SeqQueue *Q, Date *e);

void Init();
void floyd();
int shortdistance();

int COUNT_TIME();
int COUNT_FEE(SeqStack S, int gar_NUM);
int InternetOut(SeqStack *S, Date e, SeqStack *St);
int Internet(SeqQueue *Q, SeqStack *S);

void printALL(SeqStack S, SeqQueue Q);
void Enter();

#endif
