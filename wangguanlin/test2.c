#include <stdio.h>
#include <stdlib.h>

#define OK            0
#define ERROR        -1
#define MALLOC_ERROR -2 

typedef int ElementType;
typedef struct node
{
	ElementType data;    
	struct node *next;   
}Node;
typedef Node *PNode;    

int Create_List_Head(PNode *h, ElementType data)
{
	
	PNode p = (PNode)malloc(sizeof(Node)/sizeof(char));
	if (p == NULL)
	{
		return MALLOC_ERROR;
	}
	
	p->data = data;
	p->next = *h;
	*h = p;
}

int Create_List_Tail(PNode *h, ElementType data)
{
	PNode node = (PNode)malloc(sizeof(Node)/sizeof(char));
	if (node == NULL)
	{
		return MALLOC_ERROR;
	}
	node->data = data;
	node->next = NULL;
	
  	if (*h == NULL)   
	{
		*h = node;
	} 
	else              
	{
		PNode temp = *h;
		
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = node;
	}
	
	return OK;
}
int Insert_Node(PNode *h, int x, ElementType data)
{
	PNode temp = *h;
	int k=1;
	
	while (temp && k < x-1)
	{
		temp=temp->next;
		k++;
	}
	
	if (temp == NULL && *h != NULL)
	{
		printf ("给的位置无效\n");
		return ERROR;
	}
	
	PNode node = (PNode)malloc(sizeof(Node)/sizeof(char));
	if (node == NULL)
	{
		return MALLOC_ERROR;
	}
	node->data = data;
	
	if (*h == NULL || x == 1)     	
	{
		node->next = *h;
		*h = node;
	} 
	else                        
 	{
		node->next = temp->next;
		temp->next = node;
	}
	
	return OK;
}
	

int Delete_Node(PNode *h, int i)
{
	if (*h == NULL)
	{
		printf ("空表，无法删除数据\n");
		return ERROR;
	}
	
	PNode p = *h;
	int k = 1;
	while (p && k < pos-1)
	{
		p = p->next;
		k++;
	}
	
	if (p == NULL || k >= pos-1)
	{
		printf ("无效的结点\n");
		return ERROR;
	}
	
	PNode temp = p;	
	if (pos == 1)
	{
		*h = p->next;
	}
	else
	{
	    temp = p->next;
		p->next = temp->next;
	}

	free(temp);
	temp = NULL;
	
	return OK;
}


void DisPlay(PNode head)
{
	if (head == NULL)
	{
		printf ("该链表是空表!\n");
		return;
	}
	PNode temp = head;
	while (temp)
	{
		printf ("%4d", temp->data);
		temp = temp->next;
	}
	
	printf ("\n");
}

int main()
{
	PNode head = NULL;
	
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (Create_List_Head(&head, i) != OK)
		{
			return ERROR;
		} 
 		if (Create_List_Tail(&head, i) != OK)
		{
			return ERROR;
		} 
		
	}
	DisPlay(head);
	if(Insert_Node(&head, 1, 11) != OK)
	{
		return ERROR;
	}
	DisPlay(head);
	if(Delete_Node(&head, 19) != OK)
	{
		return ERROR;
	}
	DisPlay(head);
	
	return 0;
}
