#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int num;
	struct node *next;
}Node,* LinkedList;

//void initLink()
//{
//	head = NULL;
//}
//Node *head = (Node *)malloc(sizeof(Node));

Node *Creatlist(LinkedList *list,Node *head)
{	int num;
	Node *pend,*pnew = NULL;
	head->next = NULL;
	pend = head;
	scanf("%d",&num);
	while(num >= 0)
	{
	//	pnew = (Node *)malloc(sizeof(Node));
		pnew->num = num;
		pnew->next = NULL;
		pend->next = pnew;
		pend = pnew;
		scanf("%d",&num);
	}
	if (pend != NULL) pend->next = NULL;
}

Node *getNode(LinkedList *list,Node *head,int i)
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

void display(LinkedList *list,Node *head)
{
	Node *node = head->next;
	int i = 0;
	while(node !=NULL)
	{
		printf("node:%d\n",node->num);
		node=node->next;
		i++;
	}printf("finish!");
}



void main()
{
	LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
	Node *head = (Node *)malloc(sizeof(Node));
//	initliat();
	*Creatlist(list,head);
	display(list,head);
}
