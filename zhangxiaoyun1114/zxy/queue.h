#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define OK 1
#define  ERROR 0
#define TRUE 1
#define FALSE 0

typedef struct QElem{            //队列元素
    int ArrveTime;                //到达时间
    int Duration;                //办理事务所需时间
    struct QElem *next;
}QElem,*QElemType;

typedef struct{        //队列类型
    QElemType head;
    QElemType tail;
}LinkQueue;

Status InitQueue(LinkQueue *Q);        //初始化队列
Status EmptyQueue(LinkQueue *Q);    //判断队列为空
Status DelQueue(LinkQueue *Q, QElemType e);    
Status EnQueue(LinkQueue *Q, QElem e);    //节点e插入队列
int    QueueLength(LinkQueue Q);  //获取队列长度
Status GetHead(LinkQueue *Q, QElemType e);    //取队列首部节点e
Status QueueTraverse(LinkQueue *Q);//遍历

Event NewEvent(int occurTime, int nType);    //创建新事件

LinkQueue q[5];
QElem customer;
int TotalTime, CustomerNum;
int CloseTime = 50;
