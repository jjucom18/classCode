#include<stdio.h>
#include<stdlib.h>

typedef int Elemtype;
        typedef struct Node
{
	Elemtype data;
	struct Node *next;

}Node,*LinkedList;
LinkedList LinkedList()
{
	Node *L;
	L = (Node*)malloc(sizeof(Node));
	if(L==NULL)
	{
		printf("申请内存空间失败\n");

	}
	L->next = NULL;
	return L;
}//创建单链表
LinkedList LinkedListCreatH()
{
	Node *L
		L=(Node*)malloc(sizeof(Node));
	L->next = NULL;

	Elemtype x;
	while(scanf("%d",&x)!=EOF) 
	{
		Node *p;
		p = (Node*)  malloc(sizeof(Node));
		p->data = x;
		p->next = L->next;
		L->next = p;
	}
	return L;
}
