#include "linkg.h"


void initList(LinkedList *list){
	list->head = NULL;
	list->tail = NULL;
	list->current = NULL;

	return;
}

void addHead(LinkedList *list, void *data){
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	//if(list->head == NULL){
	if(NULL == list->head){
		list->tail = node;
	}else{
		node->next = list->head;
	}
	list->head = node;

	return;
}

void addTail(LinkedList *list, void *data){
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	if(list->head == NULL){
		list->head = node;
	}else{
		list->tail->next = node;
	}
	list->tail = node;
}

void delNode(LinkedList *list, void *data){
	Node *tmp = (Node *)malloc(sizeof(Node));
	tmp = list->head;
	if(*(tmp->data) == *data){
		if(tmp->next == NULL){
			list->head = list->tail = NULL;
		}else{
			list->head = list->head->next;
		}
	}else{
		while(tmp != NULL && *(tmp->data) != *data){
			tmp = tmp->next;
		}
		if(tmp != NULL){
			tmp->next = tmp->next->next;
		}
	}

	free(tmp);

	return;
}

Node *getNode(LinkedList *list, void *data){
	Node *tmp = (Node *)malloc(sizeof(Node));
	tmp = list->head;
	if(*(tmp->data) == *data){
		return tmp;
	}else{
		while(tmp != NULL && *(tmp->data) != *data){
			tmp = tmp->next;
		}
		if(tmp != NULL){
			return tmp;
		}
	}

	return NULL;
}

void displayList(LinkedList *list){
	Node *tmp = (Node *)malloc(sizeof(Node));
	tmp = list->head;
	while(tmp != NULL){
		printf("%d \t", *(tmp->data));
		tmp = tmp->next;
	}
	printf("\n");

	return;
}
