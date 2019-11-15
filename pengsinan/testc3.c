#include<stdio.h>
#include<stdio.h>
#include<string.h>

typedef struct_LinkList
{
	Node *head;
	Node *tail;
	Node *nowdata;
}LinktList;

typedef struct_node
{
	void *data;
	struct_node *next;
}Node;

Node *node = (Node *)malloc(sizeof(Node));
*stastic = (stastic *)malloc(sizeof(stastic));
int tmp = NULL;
int *stastic

void initLinkList(LinkList *list){
	list -> head = NULL;
	list -> tail = NULL;
	list -> nowdata = NULL;

	return;
}

void addHead(LinkList *, void *data){
	node -> data = data;
	node -> next = NULL;

	if (list -> tail == NULL){
		list -> tail = node;
		list -> next =NULL;
	}else{
		node -> next = list ->head;
	}
	list -> head = node;
}	
void addTail(LinkList *, void *data){
	node -> data = data;
	node -> next = NULL;

	if (list -> head == NULL){
		list -> head = node;
	}else{
		list ->tail -> next = node;
	}
	list ->tail = node;
}
void delNode(LinkList *list , Node * node){
	if(node == list ->head){
		list -> head = list -> tail = NULL;
	}else{
		list -> head = list -> head -> next
	}
}else{
	Node *tmp = list -> head;
	while (temp != NULL && tmp -> != node){
		tmp = tmp -> next;
	}
	if (tmp != NULL){
		tmp -> next = node -> next;
	}
	free(node);
	return;
}

void returnnode(LinkList * list , Node * node){

	if (strcmp(node,stastic) = 0){
	printf("The special node is : %2d",node);
	}else{
		printf("Error!");
	}
}

void printnode(LinkList * list , Node * node){
	int n = 0;
	int listlong = 0;
	if(list -> next != NULL){
		n++;
	} 
		listlong = n;

	if(list -> head == NULL)
		printf("Empty!");
else{
	for(node = 0 ,node <= listlong ,node ++);
	printf("The vaule of this list are : %2d", list);

}
	return ;
} 








