#ifndef car_h
#define car_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define maxnumber 1000
#define ok 1
#define error 0


typedef struct time{
	int hours;
	int minte;
}Time;//时间节点
typedef struct node{
	int number;
	Time  in;
	Time  out;
}carNode//车辆信息结点
typedef struct{
	carNode *stack[maxnumber];
	int top;
}carWait;//模拟便道
typedef struct car{
	carNode *data;
	struct car *next;
}queueNode;
typedef struct Node{
	queueNode *head;
	queueNode *rear;
}carStop;//模拟停车场




