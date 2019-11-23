#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#ifndef car_h
#define car_h

#define MAXNUM  10

typedef struct time
{
	int hour;
	int min;
}Time;            //时间节点



typedef struct node
{
	char num[10];
	Time reach;
	Time leave;
}CarNode;        //车辆信息节点



typedef struct NODE
{
	CarNode *stack[MAXNUM+1];
	int top;
	int gets;
}SeqStackCar;     //栈    模拟车场



typedef struct car
{
	CarNode *data;
	struct car *next;
}QueueNode;                //队列元素


typedef struct Node
{
	QueueNode *head;
	QueueNode *rear;
}LinkQueueCar;        //队列  模拟便道



void StackInit(SeqStackCar *s);  //初始化车场
int QueueInit(LinkQueueCar *Q);  //初始化便道
void Print(CarNode *p,int room);  //打印出站车的信息
int Arrival(SeqStackCar *Enter,LinkQueueCar *W);  //车辆到达
void Leave(SeqStackCar *Enter,SeqStackCar *Temp,LinkQueueCar *W);  //车辆离开
void List1(SeqStackCar *S);                 //列表显示车场信息
void List2(LinkQueueCar *W);       //列表显示便道信息
void welcom();   //主界面函数


#endif



