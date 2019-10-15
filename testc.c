#include <stdio.h>

void addHead(List *list, void *data){
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	if(list->head == NULL){
		list->tail = node;
	}else{
		node->next = list->head;
	}
	list->head = node;

	return;
}

void addTail(List *list, void *data){
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	if(list->head == NULL){
		list->head = Node;
	}else{
		list->tail->next = node;
	}
	list->tail = node;

	return;
}
