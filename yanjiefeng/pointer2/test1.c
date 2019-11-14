#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node *next;
}Linklist;

Linklist *creat()
{
    Linklist *phead;
    phead=(Linklist *)malloc(sizeof(Linklist));
    phead->next=NULL;
    return phead;
}
void head_insert(Linklist *phead,int n)

//头插法
{
    Linklist *p;
    int i;

    for(i=0;i<n;i++)
    {
        p=(Linklist *)malloc(sizeof(Linklist));
        scanf("%d",&p->data);

        p->next=phead->next;
        phead->next=p;
    }
}

void tail_insert(Linklist *phead,int value)

//尾插法
{
    Linklist *p,*t;
    int i;
    t=phead;

    p=(Linklist *)malloc(sizeof(Linklist));
    p->data=value;
    while(t->next!=NULL)
        t=t->next;

    t->next=p;
    p->next=NULL; 
}

void print(Linklist *phead)//打印链表
{
    Linklist *p;
    p=phead->next;
    if(p==NULL)
        printf("此链表为空.\n");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void delete(Linklist *phead,int value)

//删除
{
    Linklist *p,*t;
    t=phead;
    while(t->next!=NULL)
    {
        if(t->next->data==value)
        {
            p=t->next;
            t->next=p->next;
            free(p);
        }
        else
            t=t->next;
    }
}
int main(void)
{
    Linklist *phead;
    int value,num;
    phead=creat();

    head_insert(phead,8);
    print(phead);

    printf("请输入你要插入的数字:\n");
    scanf("%d",&value);
    tail_insert(phead,value);
    print(phead);

    printf("请输入你要删除的数字:\n");
    scanf("%d",&num);
    delete(phead,num);
    rint(phead);
}












