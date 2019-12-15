#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct node
{
        int data;
        struct node *next;
}Linklist;

Linklist *creat(){
        Linklist *phead;
        phead=(Linklist *)malloc(sizeof(Linklist));
        phead->next=NULL;
        return phead;
}
void head_insert(Linklist *phead,int n) //头插法
{
        Linklist *p;
        int i;
        for(i=0;i<n;i++){
                p=(Linklist *)malloc(sizeof(Linklist));
                scanf("%d",&p->data);
                p->next=phead->next;
                phead->next=p;
        }
}

void tail_insert(Linklist *phead,int value) //尾插法
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


void print(Linklist *phead) //打印链表
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

void delete(Linklist *phead,int value) //删除操作
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

int main()
{
        Linklist *phead;
        int value,num;
        printf("请输入5个数字，系统将以头插法记录.\n");
        phead=creat();
        head_insert(phead,5);
        printf("头插法输入5个数后的链表为：");
        print(phead);
        printf("请输入要用尾插法插入的数字:\n");
        scanf("%d",&value);
        tail_insert(phead,value);
        printf("插入后的链表为：\n");
        print(phead);
        printf("输入删除的数字:\n");
        scanf("%d",&num);
        delete(phead,num);
        printf("删除后的链表为：\n");
        print(phead);
}
