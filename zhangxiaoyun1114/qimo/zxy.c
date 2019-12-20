#include"zxy.h"
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
