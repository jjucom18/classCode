#ifndef carStop_h
#define carStop_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ok 1
#define error 0
#define maxnumber 10
typedef struct {
	int hours;
	int minte;
}Time;//时间节点
typedef struct {
	char number;
	Time  in;
	Time  out;
}car;//车辆信息结点
typedef car datatype;
typedef struct snode{
	datatype data;
	struct snode *next;
	//计数器
}stackNode, *carStop;//模拟停车场
void init_carStop(carStop top);
int empty_carStop(carStop top);
int push_carStop(carStop top,car *x);//入栈
int pop_carStop(carStop top,car *x);

#endif

