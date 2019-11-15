#include"stdio.h"
#include"stdlib.h"
typedef struct LNode{
	int  data;
	struct LNode *next;
} 
LNode ,*LinkList;  
  LinkList L;
  LinkList Creat_LinkList1(){
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

LinkList Creat_LinkList2(){
	LNode *s,*r=NULL;
	int x;
	scanf("%d",&x);
	while(x!=100){
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		if(L==NULL) L=s;
		else r->next=s;r=s;
		scanf("%d",&x);}
	if(r!=NULL) 
		r->next=NULL;return L;
}

LinkList reverse(){
	LNode *p,*q;
	p=L->next;
	L->next=NULL;
	while(p){
		q=p;
		p=p->next;
		q->next=L->next;			
		L->next=q;	}
} 

int main(){
	return 0;
}
