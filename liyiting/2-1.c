#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node
{
	int data;
	struct node *next;
}node,*LinkList;

LinkList *init_LinkList
{
	node *p;
	p=(node*)malloc(sizeof(node));
	p->data = data;
	p->next = NULL;
	return p;}

LinkList Creat_LinkListH()
{
	LinkList L = NULL;
	node *s;
	s=(node*)malloc(sizdof(node));
	int pn;
	printf("请输入数据：\n");
	scanf("%d",&pn);
	while(pn != flag)
	{s->data=pn;
	 s->next=L->next;
	 L->next=s
	}
	return L;
}

LinkList Creat_LinkListT()
{
	LinkList L=NULL;
	node *S.*r=NULL;
	S=(node*)malloc(sizdof(node));
	int x;
	printf("请输入数据：\n");
	scanf("%d",x);
	while(x != flag)
	{s->data=x;
	if (L==NULL)L=S;
	else r->next=s;
	 r=s;
	 scanf("%d",&x);
	}
	if (r!=NULL) r->next=NULL;
	return L;
}

LinkList Delete_LinkList(LinkList L,int i)
{
	int j;
	LinkList q=NULL,p=NULL;
	p=L;
	j=0;
	while(p->next&&j<i-1)
	{
		p=p-next;
		j++;
	}
	if (!(p>-next&&j<i-1)
	        printf("输入位置不合法\n");
        
		q=p-next;
	p->next=q->next;
	free(q);
	return L;
	}

LinkList *Get_LinkList(LinkList L,int i)
{
	node *p=L;
	int j = 0;
	while(p-next!=NULL&&j<i)
	  {p=p-next;  j++;}
	if (j==i) return p;
	else return NULL;
	}
LinkList Print_LinkList(LinkList *L)
{
        node *p = L->next;
	while (p){
		printf("%d",p->data);
		p = p->next:
	}
	printf("\n");
}
