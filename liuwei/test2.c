#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define Maxsize 10

typedef struct LinkList
{ 
	int datatype;
	struct LinkLode *next;
}LNode,*LinkList

LinkList Init_LinkList
{
	Node *L;
	L=(Node *)malloc(sizeof(Node));
	if(L=NULL)
	printf("please input over\n");
	L->next=NULL;
	return L;
}


LinkList Great_LinkList1()
{
	struct L=NULL;
	LNode *s;
	int x;
	int flag;
	scanf("%d",&x);
	while(x!=flag)
         {s=(LNode*)malloc(sizeof(LNode));
          s->data=x;
	  s->next=L;
	  L=s;
	  scanf("%d",&x);
	 }
	return L;
}

LinkList Great_LinkList2()
{
	LinkList L=NULL;
	LNode *s,*r=NULL;
	int x;
	int flag;
	scanf("%d",&x);
	while(x!=flag)
         {s=(LNode *)malloc(sizeof(LNode));
          s->datatype=x;
	  if(L==NULL) L=s;
	  else r->next=s;
	  r=s;
	  scanf("%d",&x);
	 }
	if(r!=NULL)  r->next=NULL;
	return L;
}

int  Del_LinkList(LinkList,int i)
{
	LinkList p,s;
	p=Get_LinkList(L,i-1);
	if(p==NULL)
	   {printf("%p",NULL);
            return -1;
	   }
	else if(p->next==NULL)
	{
		printf("%p",NULL);
		return 0;
	}
	else
	{s=p->next;
         p->next=s->next;
	 free(s);
	 return 1;
	}
	 }

LNode *Locate_LinkList( LinkList, datatype x)
{
	LNode *p=L->next;
	while(p!=NULL && p->data!=x)
		p=p->next;
	return p;
}




	

              


	
	


