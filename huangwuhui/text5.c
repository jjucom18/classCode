#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;
LinkList L;
void InitList(LinkList*L){
	L=(LinkList*)malloc(sizeof(LinkList));
	L=NULL;
}
void Creat_LinkList1(){
	LinkList L=NULL;
	LNode *s;
	int x,flag;
	scanf("%d",&x);
	while(x!=flag)
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		s->next=L;
		L=s;
		scanf("%d",&x);

	} 
	return ;

}
void Creat_LinkList2()
{
	LinkList L=NULL;
	LNode *s,*r=NULL;
	int x,flag;
	scanf("%d",&x);
	while(x!=flag)
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		if(L==NULL) L=s;
		else r->next=s;
		r=s;
		scanf("%d",&x);

	}
	if(r!=NULL) r->next=NULL;
	return ;
}
void Delete_LinkList(LinkList L,int i)
{
	LinkList p,s;
	p=Get_LinkList(L,i-1);
	if(p==NULL)
	{
		printf("第i-1个节点不存在");
		return ;
	}
	else if(p->next==NULL)
	{
		printf("第i个节点不存在");
		return ;

	}
	else
	{
		s=p->next;
		p->next=s->next;
		free(s);
		return ;
	}
}
void Get_LinkList(LinkList L,int i){
	LNode *p=L;
	int j=0;
	while(p->next!=NULL&&j<i)
	{
		p=p->next;j++;

	}if(j==i) return p;
	else return NULL;

	}
	void Display(LinkList L,int p){
		LNode *p=L;
		int i=0;
		while(p!=NULL){
			printf("%d\n",p->data);
			p=p->next;
			i++;
		}return;
	}
