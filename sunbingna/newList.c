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
		printf("%d",pmove->data);
		pmove = pmove->next;
	}
}

int main()
{
	Node *list = creatList();
	addHead(list,1);
	addHead(list,2);
	addHead(list,3);
	printfnode(list);
	printf("\n");
}





