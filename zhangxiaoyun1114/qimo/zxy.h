#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define OK 1
#define  ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef struct Event{    //事件类型
    int OccurTime;        //事件发生时刻
    int NType;            //事件类型，0表示到达事件，1-4表示4个窗口离开事件
    struct Event *next;
}Event,*ElemType;

typedef struct{            //链表类型
    ElemType head;
    ElemType tail;
    int len;
}LinkList;

typedef LinkList EventList;        //事件链表

typedef struct QElem{            //队列元素
    int ArrveTime;                //到达时间
    int Duration;                //办理事务所需事件
    struct QElem *next;
}QElem,*QElemType;

typedef struct{        //队列类型
    QElemType head;
    QElemType tail;
}LinkQueue;
