#include <stdio.h>
#include <malloc.h>
#define N 10//停车场最多的停车数
#define M 10//候车处最大停车数
#define Price 1//单位时间内所需费用
typedef struct{
	int CarNum[M];
	int front,rear;
}SqQueue;
void InitQueue(SqQueue *q);
void DispQueue (SqQueue *q);
