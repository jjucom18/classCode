#include"list.h"
#include"list.h"
#include"queue.h"
#include"queue.c"

void OpenForDay()//初始化操作
{
    int i;
    TotalTime = 0; 
    CustomerNum = 0;
    InitList(&ev);//初始化事件链表
    en.OccurTime = 0;
    en.NType = 0;
    OrderInsert(&ev, en);//将事件en插入到事件链表中
    for (i = 1; i < 5; i++)
        InitQueue(&q[i]);//初始化队列
}

void CustomerArrived() //顾客到达事件
{
    int durtime, intertime, i, t;
    QElem e;
    ++CustomerNum;
    intertime = rand() % 5 + 1;
    durtime = rand() % 30 + 1;
    t = en.OccurTime + intertime;//到达时间=前一个客户到达时间+办理业务时间
    if (t < CloseTime)
    {
        printf("A new customer will arrive at:%d\n", t);
        OrderInsert(&ev, NewEvent(t, 0));
        i = ShortestQueue();//找出最短的队
        e.ArrveTime = en.OccurTime;
        e.Duration = durtime;
        EnQueue(&q[i], e);//入队
        if (QueueLength(q[i]) == 1)
            OrderInsert(&ev, NewEvent(en.OccurTime + durtime, i));
    }
}

void CustomerDeparture() //顾客离开事件
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

void Bank_Simulation()//银行排队模拟
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

void PrintQueue()//打印当前队列
{
    int i;
    for ( i = 1; i < 5; i ++)
    {
        printf("Queue %d have %d customer(s):", i, QueueLength(q[i]));
        QueueTraverse(&q[i]);
    }
    printf("\n");
}

void PrintEventList() //输出事件链表
{
    printf("Current Eventlist is:\n");
    ListTraverse(&ev);//遍历
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

int ShortestQueue()//找出最短队列
{
    int i, a[4];
    for(i = 1; i <= 4; i++)
        a[i-1] = QueueLength(q[i]);
    return Min(a, 4) + 1;
}
