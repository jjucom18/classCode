#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int data;
	struct Node *next;
    }LNode,*LinkList;

LinkList L;

LinkList Creat_LinkList1()
{	LinkList L=NULL;
	LNode *s;
	int x;
	scanf("%d",&x);
	while(x!=100){
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		s->next=L;
		L=s;
		scanf("%d",&x);}
	return L;}


LinkList Creat_LinkList2(){
	LNode *s,*r=NULL;
	int x;
	scanf("%d",&x);
	while(x!=100){
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		if(L==NULL)  L=s;
		else r->next=s;r=s;
		scanf("%d",&x);}
	if(r!=NULL)
		r->next=NULL;return L;
}





LNode *Get_LinkList(LinkList L,int i){
	LNode *p=L;
       int j=0;
       while(p->next!=NULL&&j<i)
       {p=p->next;j++;}
      if(j==i) return p;
      else return NULL;

}

LNode *Locate_LinkList(LinkList L,int x){
   LNode *p=L->next;
while(p!=NULL&&p->data!=x)
     p=p->next;
return p;}
  
int Del_LinkList (LinkList L,int i){
	LinkList p,s;
	p=Get_LinkList(L,i-1);
	if(p==NULL){
	printf("i-1 not found");
	return -1;}
    else if(p->next==NULL)
    {printf("i not found");
    	    return 0;}
		else{
			s=p->next;
			p->next=s->next;
			free(s);
			return 1;}}
void displist(){LNode *p=L;
	int i=0;
	while(p!=NULL){
		printf("%d\n",p->data);
		p=p->next;
		i++;}
	return ;}


int main (int argc,char **argv){
	int p,i,x;
	LinkList L;
	printf("输入0使用尾插法，输入1使用头插法\n");
	scanf("%d",&x);
	printf("输入单链表元素\n");
	if(p==0)L=Creat_LinkList2();
	if(p==1)L=Creat_LinkList1();
	displist(L);
	printf("请输入想要查找的值\n");
	scanf("%d",&x);
	Locate_LinkList(L,x);
	printf("删除第几个结点\n");
	scanf("%d",&i);
	Del_LinkList(L,i-1);
	displist(L);
        return 0;
}


