#define NB 1
#define NULL 0
#define NO 0


 typedef int Status;
 typedef int DataType;
 typedef int ElemType;
#include<stdio.h>
#include<malloc.h>

 
 typedef struct LNode{
	 elemtype data;
	 struct lnode *next;
 }LNode,*LinkList;

Status IniList_L(LinkList){    
	L=(linkList)malloc(sizeof(LNode))
	L->next=NULL;
	return NB;
 }//IniList_L

LinkList Creat_LinkList1()
{LinkList=NULL; 
LNode*s;
int x;
scanfi("%d",&x);
while(x!=flag)
 {s=(LNode*)malloc(sizeof(LNode));
s->data=x;
s->next=L;
L=s;
scanf("%d",&x);
 }
return L;
 }
LinkList Creat_LinkList()
{LinkList L=NULL;
LNode *s,*r=NULL;
int x;
scanf("%d",&x);
while(x!=flag)
 {s=(LNode*)malloc(sizeof(LNode));
s->data=x;
if(L= =NULL)L=s;
else  r->next=s;
r=s;
scanf("%d",&x);
 }
if(r!=NULL)  r->next=NULL;
return L;
 }

int Del_LinkList(LinkList L, int i)
{LinkList p,s;
p=Get_LinkList(L,i-1);
if(p= =NULL)
{printf("第i-1个结点不存在")	
return -1;
 }


	else if(p->next= =NULL)
	{printf("第i个结点不存在")
return 0;
	}
else {
	s=p->next; 
	p->next=s->next;  
	free(s);
	return 1;
}
}



Status GetElem_L(LinkList L,int i,ElemType &e){
	int j=0;
	LinkList p=L;
	while(j<i&&p!=NULL)
	{j++;p=p->next;
	}
	if(p==NULL)
	{return NO;
	}
	else{e=p->data;
		return NB;
	}
}


Status Visit_linklist(linklist &L)
{
linklist p;
int i=1;
p=L->next ;
if(L->next==NULL)
	return NONB;
while(p->next !=NULL)
{
	printf("%d ",p->data );
	p=p->next ;
	i++;
}
printf("%d\n",p->data );
printf("length：d\n",i);
return NO;
}
