#include"queue.h"
Status InitQueue(LinkQueue *Q)//初始化队列
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

Status EmptyQueue(LinkQueue *Q)//判断队列是否为空
{
    if ((Q->head == Q->tail) && (Q->head != NULL))
        return TRUE;
    else
        return FALSE;
}

Status DelQueue(LinkQueue *Q, QElemType e)//删除队首节点用e返回
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

Status EnQueue(LinkQueue *Q, QElem e)//节点e入队
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

int QueueLength(LinkQueue Q)//得到队列长度
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

Status GetHead(LinkQueue *Q, QElemType e)//获取队首节点e
{
    if (EmptyQueue(Q))
        return ERROR;
    e = Q->head->next;
    return OK;
}

Status QueueTraverse(LinkQueue *Q) //队列遍历
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
