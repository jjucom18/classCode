#include<stdio.h>
#include"stdlib.h"
typedef struct LNode {
 int  data;
 struct LNode *next;
 } LNode ,*LinkList;
LinkList L;
LinkList Creat_LinkList2(){
	LinkList L=NULL;
	LNode *s, *r=NULL;
	int x;
scanf("%d",&x);
	while(x!=100)
	{	s=(LNode *)malloc(sizeof(LNode));
		s->data=x;
if(L==NULL) L=s;
r=s; scanf("%d",&x);
	} 
	if(r!=NULL) r->next=NULL;
   return L;
  }

int main(){



	ireturn 0;
}
