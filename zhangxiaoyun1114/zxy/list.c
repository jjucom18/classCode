#include"list.h"
Event NewEvent(int occurT, int nType)//创建新事件
{
    Event e;
    e.OccurTime = occurT;
    e.NType = nType;
    return e;
}

Status InitList(LinkList *L)//初始化链表
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

Status OrderInsert(LinkList *L, Event e)//将事件e插入事件链表中
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

Status DelFirst(LinkList *L, ElemType e)//删除链表首节点，用e返回
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

Status ListTraverse(LinkList *L)//遍历链表
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
