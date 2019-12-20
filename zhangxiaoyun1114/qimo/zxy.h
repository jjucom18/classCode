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

Status InitList(LinkList *L);    //初始化事件链表
Status OrderInsert(LinkList *L, Event e);    //将事件e按时间顺序插入有序链表L中
Status ListEmpty(LinkList *L);    //判断链表为空，为空返回TRUE
Status DelFirst(LinkList *L,ElemType e);    //删除链表首结点，用e返回
Status ListTraverse(LinkList *L);    //遍历链表

Status InitQueue(LinkQueue *Q);        //初始化队列
Status EmptyQueue(LinkQueue *Q);    //判断队列为空
Status DelQueue(LinkQueue *Q, QElemType e);    
Status EnQueue(LinkQueue *Q, QElem e);    //接点e插入队列
int       QueueLength(LinkQueue Q);
Status GetHead(LinkQueue *Q, QElemType e);    //取队列首部结点e
Status QueueTraverse(LinkQueue *Q);

Event NewEvent(int occurTime, int nType);    //创建新事件

int Min(int a[], int n);    //返回长度为n的数组a[]第一个最小下标，从1开始
int ShortestQueue();        //获取最短队列编号
void OpenForDay();            //初始化操作
void CustomerArriver();        //顾客到达事件
void CustomerDeparture();    //顾客离开事件
void Bank_Simulation();        //银行排队模拟
void PrintEventList();        //输出事件列表
void PrintQueue();            //打印当前队列

EventList ev;
Event en;
LinkQueue q[5];
QElem customer;
int TotalTime, CustomerNum;
int CloseTime = 50;
