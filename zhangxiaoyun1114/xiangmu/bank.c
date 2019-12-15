//模拟银行营业排队情况
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

//----------------------main()--------------------//
int main()
{
    Bank_Simulation();
    return 0;
}

//-----------------------模拟排队----------------//
void OpenForDay()
{
    int i;
    TotalTime = 0; 
    CustomerNum = 0;
    InitList(&ev);
    en.OccurTime = 0;
    en.NType = 0;
    OrderInsert(&ev, en);
    for (i = 1; i < 5; i++)
        InitQueue(&q[i]);
}

void CustomerArrived() 
{
    int durtime, intertime, i, t;
    QElem e;
    ++CustomerNum;
    intertime = rand() % 5 + 1;
    durtime = rand() % 30 + 1;
    t = en.OccurTime + intertime;
    if (t < CloseTime)
    {
        printf("A new customer will arrive at:%d\n", t);
        OrderInsert(&ev, NewEvent(t, 0));
        i = ShortestQueue();
        e.ArrveTime = en.OccurTime;
        e.Duration = durtime;
        EnQueue(&q[i], e);
        if (QueueLength(q[i]) == 1)
            OrderInsert(&ev, NewEvent(en.OccurTime + durtime, i));
    }
}

void CustomerDeparture() 
{    
    int i = en.NType;
    DelQueue(&q[i], &customer);
    printf("A customer leaves at:%d\n", en.OccurTime);
    TotalTime += en.OccurTime - customer.ArrveTime;
    if (!EmptyQueue(&q[i]))
    {
        GetHead(&q[i], &customer);
        OrderInsert(&ev, NewEvent(en.OccurTime + customer.Duration, i));
    }
}

void Bank_Simulation()
{
    OpenForDay();
    srand((unsigned)time(NULL));
    while(!ListEmpty(&ev)) {
        DelFirst(&ev, &en);
        if (en.NType == 0)
            CustomerArrived();
        else
            CustomerDeparture();
        PrintQueue();
    }
    printf("\nTotal time is:%d min,average time is: %g min.\n",TotalTime,
        (float)TotalTime/CustomerNum);
}

void PrintQueue()
{
    int i;
    for ( i = 1; i < 5; i ++)
    {
        printf("Queue %d have %d customer(s):", i, QueueLength(q[i]));
        QueueTraverse(&q[i]);
    }
    printf("\n");
}

void PrintEventList() 
{
    printf("Current Eventlist is:\n");
    ListTraverse(&ev);
}

int Min(int a[], int n)
{
    int i, tmp, ind = 0;
    tmp = a[0];
    for (i = 1; i < n; i ++)
        if (a[i] < tmp)
        {
            tmp = a[i];
            ind = i;
        }
    return ind;
}

int ShortestQueue()
{
    int i, a[4];
    for(i = 1; i <= 4; i++)
        a[i-1] = QueueLength(q[i]);
    return Min(a, 4) + 1;
}

//------------------------队和栈表操作-------------------//
Event NewEvent(int occurT, int nType)
{
    Event e;
    e.OccurTime = occurT;
    e.NType = nType;
    return e;
}

Status InitList(LinkList *L)
{
    L->head = L->tail = (ElemType)malloc(sizeof(Event));
    if (!L->head) 
    {
        printf("Apply for memory error.LinkList initializefailed.\n");
        exit(0);
    }

    L->head->next = NULL;
    return OK;
}

Status OrderInsert(LinkList *L, Event e)
{
    ElemType p, q, newptr;
    newptr = (ElemType)malloc(sizeof(Event));
    if(!newptr)
    {
        printf("Apply for memory error.\n");
        exit(0);
    }
    *newptr = e;
    if (TRUE == ListEmpty(L))
    {
        L->head->next = newptr;
        L->tail = newptr;
        L->tail->next = NULL;
        return OK;
    }
    q = L->head;
    p = L->head->next;
    while(p)
    {
        if (p->OccurTime >= newptr->OccurTime)
            break;
        q = p;
        p = p->next;
    }
    q->next = newptr;
    newptr->next = p;
    if (!p)
        L->tail = newptr;
    return OK;
}

Status ListEmpty(LinkList *L)
{
    if((L->head == L->tail) && (L->head != NULL))
        return TRUE;
    else
        return FALSE;
}

Status DelFirst(LinkList *L, ElemType e)
{
    ElemType p = L->head->next;
    if (!p)
        return ERROR;
    L->head->next = p->next;
    *e = *p;
    free(p);
    if (L->head->next == NULL)
        L->tail = L->head;
    return OK;
}

Status ListTraverse(LinkList *L)
{
    ElemType p = L->head->next;
    if (!p)
    {
        printf("List is empty.\n");
        return ERROR;
    }
    while (p)
    {
        printf("OccurTime:%d, Event Type:%d\n", p->OccurTime, p->NType);
        p = p->next;
    }
    printf("\n");
    return OK;
}

Status InitQueue(LinkQueue *Q)
{
    Q->head = Q->tail = (QElemType)malloc(sizeof(QElem));
    if (!Q->head)
    {
        printf("Apply for memory error.LinkQueue initialize failed.\n");
        exit(0);
    }
    Q->head->next = NULL;
    return OK;
}

Status EmptyQueue(LinkQueue *Q)
{
    if ((Q->head == Q->tail) && (Q->head != NULL))
        return TRUE;
    else
        return FALSE;
}

Status DelQueue(LinkQueue *Q, QElemType e)
{
    QElemType p = Q->head->next;
    if (!p)
        return    ERROR;
    *e = *p;
    Q->head->next = p->next;
    free(p);
    if (!Q->head->next)
        Q->tail = Q->head;
    return OK;
}

Status EnQueue(LinkQueue *Q, QElem e)
{
    QElemType p = (QElemType)malloc(sizeof(QElem));
    if (!p)
    {
        printf("Apply for memory error, new element can't enqueue.\n");
        exit(0);
    }
    *p = e;
    p->next = NULL;
    Q->tail->next = p;
    Q->tail = p;
    return OK;
}

int QueueLength(LinkQueue Q)
{
    int count = 0;
    QElemType p = Q.head->next;
    while(p)
    {
        count ++;
        p = p->next;
    }
    return count;
}

Status GetHead(LinkQueue *Q, QElemType e)
{
    if (EmptyQueue(Q))
        return ERROR;
    e = Q->head->next;
    return OK;
}

Status QueueTraverse(LinkQueue *Q)
{
    QElemType p = Q->head->next;  
    if(!p){  
        printf("--Is empty.\n");  
        return ERROR;  
    }  
    while(p){  
        printf("(%d,%d) ",p->ArrveTime,p->Duration);  
        p = p->next;  
    }  
    printf("\n");  
    return OK;  
}
