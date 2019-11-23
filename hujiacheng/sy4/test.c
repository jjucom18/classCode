#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>

using namespace std;

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


void InitStack(SeqStack *S) {
	S->top = -1;
}
void InitQueue(SeqQueue *Q) {
	Q->front = Q->rear = 0;
	for (int i = 0; i < MAXSIZE; i++)
	{
		Q->Qelem[i] = NULL;
	}
}


int COUNT_TIME() {
	time_t tmpcal_ptr;
	struct tm *tmp_ptr = NULL;
	time(&tmpcal_ptr);
	return tmpcal_ptr;
}

int COUNT_FEE(SeqStack S, int gar_NUM) {
	int fee;
	time_t tmpcal_ptr;
	struct tm *tmp_ptr = NULL;
	time(&tmpcal_ptr);
	fee = (tmpcal_ptr - S.TIME[gar_NUM])*FEE_per_s;
	return fee;
}

int Push(SeqStack *S,ElemType e) {
	if (S->top == SMaxSize -1 ) return FALSE;
	S->Selem[++S->top] = e;
	return TRUE;
}
int EnQueue(SeqQueue *Q,ElemType e) {
	if ((Q->rear + 1) % MAXSIZE == Q->front) return FALSE;
	Q->Qelem[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return TRUE;
}

int Pop(SeqStack *S, ElemType *e) {
	if (S->top == -1) return FALSE;
	*e = S->Selem[S->top];
	S->top--;
	return TRUE;
}
int DeQueue(SeqQueue *Q, ElemType *e) {
	if (Q->front == Q->rear) return FALSE;
	*e = Q->Qelem[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return TRUE;
}


int DriveOut(SeqStack *S, ElemType e, SeqStack *St) {
	ElemType S2S;
	while ( S->Selem[S->top] != e ){
		if (Pop(S, &S2S) == FALSE) {
			while (St->top != -1) {
				Push(S, St->Selem[St->top]);
				St->top--;
			}
			printf("车库内无此车，驶出失败\n");
			return FALSE;
		}
		Push(St, S2S);
	}
	if (S->Selem[S->top] == e) {
		printf("\n		%d车驶出成功\n", S->Selem[S->top]);
		printf("		应收停车费为	%d\n", COUNT_FEE(*S, S->top));
		for (int i = S->top; i < SMaxSize -1; i++){
			S->TIME[i] = S->TIME[i+1];
		}
		S->top--;
	}
	while (St->top != -1) {
		Push(S, St->Selem[St->top]);
		St->top--;
	}
	return TRUE;
}

int Drive_Qc_S(SeqQueue *Q, SeqStack *S) {
	ElemType e;
	if (DeQueue(Q, &e) == FALSE) return FALSE;
	else {
		Push(S, e);
		S->TIME[S->top] = COUNT_TIME();
		return TRUE;
	}
}

void printALL(SeqStack S, SeqQueue Q) {
	printf("\n");
	printf("当前车库为\n");
	for (int i = S.top; i > -1; i--)
	{
		printf("	| %d |	费用:%d\n",S.Selem[i], COUNT_FEE(S, i));
	}
	printf("当前便道为\n");
	for (int i = Q.front, m = 0; m < MAXSIZE -1; m++)
	{

	}
	int i = Q.front;
	while (1){
		if (i == Q.rear) break;
		printf("	| %d |\n", Q.Qelem[i]);
		i = (i + 1) % MAXSIZE;
	}
	printf("\n");
}

int main() {
	SeqStack S;
	SeqQueue Qc;
	SeqStack St;
	InitStack(&S);
	InitQueue(&Qc);
	InitStack(&St);
	char con;
	int num;
	int count = 1;
	printf("请输入:\n");
	printf("j:进入车辆\n");
	printf("c:驶出车辆\n");
	printf("e:退出系统\n");
	printf("每秒收费%d元\n", FEE_per_s);
	while (1) {
		scanf("%c", &con);
		if (con == 'c') {
			printf("请输入驶出的车辆序号\n");
			scanf("%d", &num);
		}

		if (con == 'e') {
			return 0;
		}
		if (con == 'j') {
			if (Push(&S,count) == FALSE) {
				if(EnQueue(&Qc, count) == FALSE ) printf("车库便道均已满，进入失败\n");
				else {
					printf("%d进入便道成功\n", count);
					count++;
				}
			}
			else {
				printf("%d进入车库成功\n", count);
				S.TIME[S.top] = COUNT_TIME();
				count++;
			}
		}
		if (con == 'c') {
			if (DriveOut(&S, num, &St) == TRUE) Drive_Qc_S(&Qc, &S);
		}
		printALL(S, Qc);
		getchar();
	}
}
