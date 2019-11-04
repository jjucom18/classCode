#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int data;
	struct LNode *next;
}
LNode,*LinkList;
LinkList L;

LinkList Creat_LinkList(){
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
LinkList reverse（）{
	LNode *p,*q;
	p=L->next;
	L->next=NULL;
	while(p){
		q=p;
		p=p->next;q->next=L->next;
		L->next=q;
	}
}
LinkList dispList(){
	LinkList p=L;
	while(p!=NULL){
		printf("%d",p->data);
		printf("");
		p=p->next;
	}
}
int main(){
	Creat_LinkList();
	reverse();
	dispList();
}
