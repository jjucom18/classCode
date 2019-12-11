#ifndef main_h
#define main_h
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<unistd.h>
#include<string.h>
#include"CarStack.h"
#include"TmpStack.h"
#include"CarQueue.h"

#define MaxSize 3
typedef struct tm timefrom;


typedef struct _car{
        bool arrive;
        bool leave;
        char number[30];
        time_t atime;
        time_t ltime;
        double price;
}Car;

typedef struct  _carStack{
	Car data[MaxSize];
	int top;
}CarStack;



typedef struct  _tmpStack{
	Car data[MaxSize];
	int top;
}TmpStack;



typedef struct  _carQueue{
	Car data;
	struct _carQueue *next;
}CarQueueNode;



typedef struct {
	CarQueueNode *rear,*front;
}ListQueue;

void ViewStack(CarStack *stack,ListQueue *list);        //查看栈状态
int PlaceQueue(ListQueue *list);                                        //队列的大小
int PlaceStack(CarStack *stack,char number[]);          //查找车在栈中的位置
int PromptInput(CarStack *stack,ListQueue *list);       //提示用户选择
void Inparking(CarStack *stack,ListQueue *list);        //进入停车场
void Outparking(CarStack *stack,ListQueue *list);       //离开停车场
void QueueToStack(ListQueue *list,CarStack *stack);     //便道到栈
void ChangePrice();

#endif
