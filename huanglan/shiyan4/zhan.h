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
void Init_SqStack(SqStack *s);
void DispStack(SqStack *s);


#endif
