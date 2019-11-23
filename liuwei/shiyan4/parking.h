#ifndef parking_h
#define parking_h

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<unistd.h>
#include<string.h>


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

CarStack *InitCarStack();
TmpStack *InitTmpStack();

int EmptyCar(CarStack *s);
int EmptyTmp(TmpStack *s);

int FullCar(CarStack *s);
int FullTmp(TmpStack *s);

void PushCarStack(CarStack *s, Car data);
void PushTmpStack(TmpStack *s, Car data);

void PopCarStack(CarStack *s, Car *data);
void PopTmpStack(TmpStack *s, Car *data);

void TopCarStack(CarStack *s, Car *data,int tmp);
void TopTmpStack(TmpStack *s, Car *data);


ListQueue *InitQueue();

void InQueue(ListQueue *Queue, Car data);

int EmptyQueue(ListQueue *Queue);

void OutQueue(ListQueue *Queue, Car *data);

void display(timefrom *from,Car *car);				//输出车的进入时间和车牌号

void displayLeave(Car *leaveCar);					//输出离开车的信息

void displayStack(CarStack *stack);					//显示栈状态

void displayQueue(ListQueue *list);					//显示队列状态

int PlaceQueue(ListQueue *list);					//队列的大小

int PlaceStack(CarStack *stack,char number[]);		//查找车在栈中的位置

int PromptInput(CarStack *stack,ListQueue *list);	//提示用户选择

void Inparking(CarStack *stack,ListQueue *list);	//进入停车场

void Outparking(CarStack *stack,ListQueue *list);	//离开停车场

void QueueToStack(ListQueue *list,CarStack *stack);	//便道到栈




#endif
