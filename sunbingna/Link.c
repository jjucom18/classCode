#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int num;
	struct node *next;
}Node;

typedef struct list
{
	Node *head;
}List;

void initLink(List *list)
{
	list->head = NULL;
}

Node *CreatLink()
{	int num;
	Node *pend,*pnew = NULL;
	head->next = NULL;
	pend = head;
	scanf("%d",&num);
	while(num >= 0)
	{
		pnew = (Node *)malloc(sizeof(Node));
		pnew->num = num;
		pnew->next = NULL;
		pend->next = pnew;
		pend = pnew;
		scanf("%d",&num);
	

	}
	if (pend != NULL) pend->next = NULL;
	return L;
}

Node *getNode(LinkedList L,int i)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node = head->next;
	while(node !=NULL)
	{
		if(node->num=i) return node;
		else node=node->next;
	}
	return NULL;
}



void main()
{
	 LinkedList L = CreatLink();

	 printf("")
}
