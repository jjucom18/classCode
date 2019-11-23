#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>


#define MAXSIZE 4
#define SMaxSize 5
#define ElemType int
#define FALSE 0
#define TRUE 1
#define FEE_per_s 1

typedef struct {
	ElemType Selem[SMaxSize];
	int top;
	int TIME[SMaxSize];
} SeqStack;

typedef struct {
	ElemType Qelem[MAXSIZE];
	int front;
	int rear;
} SeqQueue;


void InitStack(SeqStack *S); 
void InitQueue(SeqQueue *Q);
int COUNT_TIME();
int COUNT_FEE(SeqStack S, int gar_NUM);
int Push(SeqStack *S,ElemType e);
int EnQueue(SeqQueue *Q,ElemType e); 
int Pop(SeqStack *S, ElemType *e);
int DeQueue(SeqQueue *Q, ElemType *e);
int DriveOut(SeqStack *S, ElemType e, SeqStack *St);
int Drive_Qc_S(SeqQueue *Q, SeqStack *S);
void printALL(SeqStack S, SeqQueue Q);
