#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
	void *data;
	struct _node *next;

}Node;

typedef struct _linkedList{
	Node *head
	Node *tail
	Node *current
}LinksdList;

void initializelist(LinkedList *list){
	list->head = NULL;
	list->tail = NULL;
	list->current = NULL;
}

void addHead(LinkedList *list, void *data){
	Node *node = (Node*) malloc (sizeof(Node));
	node->data = data;
if (list->head == NULL){
	list->tail = node;
	node->next =NULL;
}else{
	node->next = list->head;
}
list->head = node;
}

void deleNode(List *list, DataType iData) {

if(list->head->data == iData) {

	list->head = list->head->next;
} 
	Node *prev = list->head;
	Node *node = prev->next;
while(node != NULL) {

if(node->data == iData) {
	prev->next = prev->next->next;
		return;
} else{
	prev = prev->next;
	node = node->next;
} 
	} 
		return;
}

void disList(List *list){
	Node *node = list->head;
	int i = 0;
	while(node != NULL){
		printf("the %dth node:%d\n",i+1,node->data);
		node = node->next;
		i++;
	}printf("disp finished!\n");
	return;
}
