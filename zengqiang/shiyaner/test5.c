#include<stdio.h>
#include<stdlib.h>

typedef struct LNode
{
	int data ;
	struct LNode *next;

}LNode,*LinkList;

LinkList Init_LNode()
{
  LNode *L;
  L =(LinkList)malloc(sizeof(LNode));
  if(L == NULL)
  { 
	  printf("初始化失败！\n");
	  exit(-1);

  }
  L->next = NULL;
  return L;
 }

LinkList Creat_LinkList1()
{
  LinkList L= NULL;
  LNode *s;
  int x;
  scanf("%d",&x);
  while(x!=15)  
  {
	 s=(LNode*)malloc(sizeof(LNode));
	 s->data=x;
	 s->next=L;
	 L=s;
	 scanf("%d",&x);

  }
  return L;
 }
LinkList Creat_LinkList2(){
	LinkList L=NULL;
	LNode *s,*r=NULL;
	int x;
	scanf("%d",&x);
	while(x!=15)
	{
	s=(LNode *)malloc(sizeof(LNode));
	s->data=x;
	if(L==NULL) L=s;
	else r->next=s;
		
	}
  if(r!=NULL)  r->next=NULL;
  return L;
}
int main(){


	return 0;
}
int Del_LinkList(LinkList L,int i)
{
	LinkList p,s
    p=Get_LinkList(L,i-1);
	if(p==NULL)
{
   printf("第i-1个结点不存在")；
   return -1;
}
else if(p->next==NULL)
{
	printf("第i个结点不存在")；
	return 0;
}
else
{ s=p->next;
  p->next=s->next;
  free(s);
  return 1;
 } 
}
}
