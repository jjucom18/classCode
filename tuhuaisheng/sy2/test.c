#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;
typedef struct Node{
       Elemtype data;
	   struct Node *next;

}Node, *LinkedList;

LinkedList LinkedListCreatH(){

	Node *L;
	L=(Node *)malloc(sizeof(Node));
	if (L= =NULL){
		printf("申请内存空间失败/n");
	}
	L->next =NULL;
	return L;
}//单链表的初始化
LinkedList LinkedListCreatH(){
	Node *L;
	L = (Node *)malloc(sizeof(Node));
	L->next = NULL;
	Elemptye x;
	while(scanf("%d",&x)  ! = EOF){
		Node *p;
		p =(Node *)malloc(sizeof(Node));
        p->data = x;
		p->next = L-> next;
		L->next = p;
	}
	return L;
}//头插法
LinkedList LinkedListCreatT(){
	Node *L;
	L = =(Node *)malloc(sizeof(Node));
	L->next = NULL;
	Node *r;
	r = L;
	Elemtype x;
	while(scanf"%d",&x) != EOF {
		Node *p;
		p=(Node *)malloc(sizeof(Node));
		p->data = x;
		r-next = p;
		r = p;
	}
	r->next = NULL;
	return L;
}//尾插法
LinkedList LinkedListInsert(LinkedList L, int i,Elemtype x){
	Node *pre;
	pre = L;
	int tempi = 0;
	for (tempi = 1;tempi < i;tempi++)
		pre = pre->next;
	Node *p;
	p = (Node *)=malloc(sizeof(Node));
	p->data = x;
	p->next = pre-> = next;
	pre->next = p;
	return L;
}//插入
int Del_LinkedList(LinkedList L,int i){
	LinkedList p,s;
	p=Get_LinkedList(L,i-1);
	if(p= =NULL)
	{
		printf("第i-1个节点不存在")；
			return -1;
	}
	else if(p->next= =NULL)
	{
		printf("第i个节点不存在")；
			return 0;
	}
	else
	{
		s=p->next;
		p->next=s->next;
		free(s);
		return 1;
	}
}//节点删除
printf("请输入单链表的数据：")；
list = LinkedListCreatH();
for (start = list->next;start!=NULL;start = start->next)
printf("%d",start->data);
printf("/n");//头插


