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



/*头插法*/



void head_insert(Linklist *phead,int n)

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



/*尾插法*/



void tail_insert(Linklist *phead,int value)

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



/*打印链表*/



void print(Linklist *phead)

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



/*删除结点*/



void delete(Linklist *phead,int value)

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



    head_insert(phead,5);

    print(phead);



    printf("请输入你想插入的数字:\n");

    scanf("%d",&value);

    tail_insert(phead,value);

    print(phead);



    printf("请输入你想删除的数字:\n");

    scanf("%d",&num);

    delete(phead,num);

    print(phead);

}


