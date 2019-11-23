#ifndef ABC_H_INCLUDED
#define ABC_H_INCLUDED

#define MAXSIZE 4
#define SMaxSize 5
#define ElemType int



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


void InitStack(SeqStack *) ;
void InitQueue(SeqQueue *);
int COUNT_TIME();
int COUNT_FEE(SeqStack S, int gar_NUM);
int Push(SeqStack *,ElemType) ;
int EnQueue(SeqQueue *,ElemType ) ;
int Pop(SeqStack *, ElemType *);
int DeQueue(SeqQueue *, ElemType *);
int DriveOut(SeqStack *, ElemType e, SeqStack *);
int Drive_Qc_S(SeqQueue *, SeqStack *);
void printALL(SeqStack , SeqQueue );
#endif
