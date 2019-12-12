#include<stdio.h>
#include"stdlib.h"
typedef struct LNode {
 int  data;
 struct LNode *next;
 } LNode ,*LinkList;
LinkList L;
void LinkList Creat_LinkList2(){
	LinkList L=NULL;
	LNode *s, *r=NULL;
	int x;  //设数据元素的类型为int
scanf("%d",&x);
	while(x!=fiag)    //flag表示结束标志
	{	s=(LNode *)malloc(sizeof(LNode));
		s->data=x;
if(L==NULL) L=s;    //第一个节点的处理
else r->next=s;    //其他节点的处理
    r=s;            //r指向新的尾节点
scanf("%d",&x);   
	} 
	if(r!=NULL) r->next=NULL;    //对于非空表，最后节点的指针域置空
   return L;
  }

int main(){



	return 0;
}
