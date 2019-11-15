#include <stdio.h>
#include <stdlib.h>

struct node 
{
int num;
struct node *next;
} ;
void creat(struct node **head)
{
	  *head = NULL;
}
void insert_node(struct node **node,struct node **newnode)
{
	if(*head ==NULL)
	{
   （*newnode) ->next =NULL;
   *head = *newnode;
	} 
	 else
	 {
		 (*newnode)->next = *head;
		 *head = *newnode;
	 }
} 

void display( struct node **head)
{
	struct node *temp = *head;
	while(temp != NULL)
	{
		printf("%d\t",temp->num);
		temp = temp->next;
	}
}

int insert_tail(struct node **head,struct node **newnode)
{
	struct node *temp = *head;
	if(*head == NULL)
	{
		(*newnode)->next =NULL;
		*head = *newnode;
	}
	else
	{
		while(temp->next !=NULL)
		{
			temp = temp->next;
		}
	temp->next = *newnode;
	(*newnode)->next = NULL;
	return 0;
	}
     
}

int insert_mid( struct node **head , struct nodr **newnode, int num);
{
	struct nodr *temp = *head;
	while(temp !=NULL)
	{
		if(temp->num == num)
		{
			(*newnode)->next = temp->next;
			temp->next = *newnode;
			return 0;
		}
		temp = temp->next;
	}
	printf("not find %d",num);

}

int delete(struct node **head,int num)
{
	if((*head)->num == num)
	{
		*head=(*head)->next;
		return 0;
	}
	else
	{
		struct node *temp = *head;
		struct node *ptr =NULL;
		while(temp !=NULL)
		{
			if(temp->num == num)
			{
				ptr->next = temp->next;
				free(temp);
				return 0;
			}
			ptr = temp;
			temp = temp->next;
		}
		printf("not find %d,delete fail !!!\n",num);
		exit(1);
	}
}
int main() 
		{
		int i=0
			struct node *head;
		creat(&head);
		struct node *newnode;
		for(i =0;i<10;i++)
		{
			newnode = (struct node *) malloc(sizeof(struct node) ) ;
			         newnode->num = i + 1;
			         insert_tail(&head,&newnode) ;
		}
	newnode = (struct node *) malloc(sizeof(struct node) ) ;
 newnode->num = 12;
  //insert_mid(&head,&newnode,10);
   delete(&head,'a') ;
    display(&head) ;
     printf("\n") ;
     return 0;
		}
