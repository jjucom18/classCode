#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}Node;

Node * creatList()
{
	Node *head = (Node *)malloc(sizeof(Node));
	head->next = NULL;
}

Node * creatnode(int data)
{
	Node *newnode = (Node *)malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

void addHead(Node *head,int data)
{
	Node *newnode = creatnode(data);
	newnode->next = head->next;
	head->next = newnode;
}

void printfnode(Node *head)
{
	Node *pmove = head->next;
	while(pmove)
	{
		printf("%d\t",pmove->data);
		pmove = pmove->next;
	}printf("\n");
}

void deletenode(Node  *head,int data)
{
	Node *p = head->next;
	Node *pfront = head;
	while(p != NULL)//判断链表是非为空
	{
		if(p->data == data){pfront->next = p->next; break;}
		else pfront = p; p = p->next;
	}
	free (p);
}


int main()
{
	Node *list = creatList();
	addHead(list,1);
	addHead(list,5);
	addHead(list,6);
	addHead(list,8);
	printfnode(list);
	deletenode(list,6);
	printfnode(list);
	return 0;


}





