#ifndef CarQueue_h
#define CarQueue_h
#include<stdio.h>
#include<stdbool.h>
#include<time.h>
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

typedef struct  _carQueue{
        Car data;
        struct _carQueue *next;
}CarQueueNode;

typedef struct {
        CarQueueNode *rear,*front;
}ListQueue;

ListQueue *InitQueue();
void InQueue(ListQueue *Queue, Car data);
int EmptyQueue(ListQueue *Queue);
void OutQueue(ListQueue *Queue, Car *data);
void displayQueue(ListQueue *list);  
int PlaceQueue(ListQueue *list);

#endif
