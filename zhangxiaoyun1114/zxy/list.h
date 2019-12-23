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
Status InitList(LinkList *L);    //初始化事件链表
Status OrderInsert(LinkList *L, Event e);    //将事件e按时间顺序插入有序链表L中
Status ListEmpty(LinkList *L);    //判断链表为空，为空返回TRUE
Status DelFirst(LinkList *L,ElemType e);    //删除链表首结点，用e返回
Status ListTraverse(LinkList *L);    //遍历链表

EventList ev;
Event en;
LinkQueue q[5];
QElem customer;
int TotalTime, CustomerNum;
int CloseTime = 50;
