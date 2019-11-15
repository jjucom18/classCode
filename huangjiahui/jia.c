#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct Node{
        int date;
        struct Node * next;
}Note,*p_Node;
vode init_Node（Node &*）;
int Length_LinkList1(LinkList L)；
{LNode*p=L;
int j=0;
while(p->next)
{p=p->next;j++;}
return j;
}
LinkList Creat_LinkList2()
{LinkList L=NULL;
LNode*s,*r=NULL;
int x;
scanf("%d",&x);
while(x!=flag)
{s=(LNote*)malloc(sizeof(LNode));
s->date=x;
if(L==NULL)L=s;
else r->next=s;
r=s;
scanf("%d",&x);
}
if(r!=NULL) R->next=NULL;
