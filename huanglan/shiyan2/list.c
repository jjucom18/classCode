#include"list.h"


void initList (LinkedList *list){

	list->head = NULL;
	list->tail = NULL;
	list->current = NULL;

	return;
}

void addTail(LinkedList *list, int data){

	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	if(NULL == list->head){
		list->head = node;
	}
	else{
		list->tail->next = node;
	}
	list->tail = node;

	return;
}
void addHead(LinkedList *list, int data){

	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	if(NULL == list->head){
		list->tail = node;
	}
	else{
		node->next = list->head;
	}
	list->head = node;

	return;
}

void displayList(LinkedList *list){

	Node *tmp = list->head;
	while(tmp !=NULL){
		printf("%d\t",tmp->data);
		tmp = tmp->next;
	}

}
void delNode(LinkedList *list,Node *node){

	if(node == list->head){
		if(list->head->next == NULL){
			list->head = list->tail = NULL;
		}
		else{
			list->head = list->head->next;
		}
	}
	else{
		Node *tmp = list->head;
		while(tmp != NULL && tmp->next != node){
			tmp = tmp->next;
		}
		if(tmp != NULL){
			tmp->next = node->next;
		}
	}
	free(node);

	return;
	
}

Node *FindData(LinkedList *list,int data){

	Node *tmp = list->head;
	while(tmp != NULL && tmp->data != data){
		tmp = tmp->next;
	}
	return tmp;
}

