#include "stdio.h"
#include"stdlib.h"
typedf struct lnode{
	int  data;
	struct lnode *next;
} LNode ,*LinkList;
    LinkList L;
LinkList Creat_LinkList1(){//头插
	LinkList L=NULL;
	LNode *s;
	int x;
	scanf("%d",&x);
	while(x!=100){
		s=(LNode*)malloc(sizeof(LNode));
	s->data=x;
	s->next=L;
	L=s;
	scanf("%d",&x);}
	return L;
	}

LinkList Creat_LinkList2(){//尾插
	LNode *s,*r=NULL;
	int x;
	scanf("%d",&x);
	while(x!=100){
		s=(LNode*)
	malloc(sizeof(LNode));
	s->data=x;
	if(L==NULL) L=s;
	else r->next=s;r=s;
	scanf("%d",&x);}
	if(r!=NULL) 
		r->next=NULL;return L;
}
LinkList reverse(){//倒置
	LNode *p,*q;
	p=L->next;
	L->next=NULL;
	while(p){
		q=p;
		p=p->next;
		q->next=L->next;
		L->next=q;	}
} 

LNode *Get_LinkList(LinkList L,int i){//查找
	LNode *p=L;
	int j=0;
	while (p->next!=NULL&&j<i)
	{p=p->next; j++;}
if(j==i) return p;
else return NULL;
}

LNode *Locate_LinkList(LinkList L,int  x){//按值查找定位
	LNode *p=L->next;
	while (p!=NULL&&p->data!=x)
		p=p->next;
	return p;
}

int  Del_LinkList(LinkList L,int i){//删除
	LinkList p,s;
	p=Get_Link(L,i-1);
	if(p==NULL){
		printf("第i-1个结点不存在")；
			return -1;
	}
	else if (p->next==NULL)
	{printf("第i个结点不存在")；
           return 0;	}
  else {
	  s=p->next;
	  p->next=s->next;
	  free(s);
	  return 1;} 
  }



void displist(){
	LNode *p=L->next;
	int i=0;
	while (p!=NULL){
		printf("%d\n",p->data);
		p=p->next;
		i++;
	}
	printf("finshed\n");
	return ;
}
