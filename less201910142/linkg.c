#include "linkg.h"


Student* initStu(char *name, int age, double record){
	Student *stu = (Student *)malloc(sizeof(Student));
	//must malloc stu->name memory
	stu->name = (char *)malloc(sizeof(char) * 30);
	strcpy(stu->name, name);
	stu->age = age;
	stu->record = record;

	return stu;
}

void outStu(Student *stu){
	printf("%s'Info: age-%d and record-%f\n", stu->name, stu->age, stu->record);

	return;
}

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
void delNode(LinkedList *list, Node *node){
	if(node == list->head){
		if(list->head->next == NULL){
			list->head = list->tail = NULL;
		}else{
			list->head = list->head->next;
		}
	}else{
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

Node *getNode(LinkedList *list, void *data){
	/*Node *node = (Node *)malloc(sizeof(Node));
	node = list->head;
	if(list->head->data == *data){
		return node;
	}
	while(node != NULL){
		node = node->next;
	}
	if(node->data == *data){
		return node;
	}*/

	return NULL;
}

void displayList(LinkedList *list){
	Node *tmp = (Node *)malloc(sizeof(Node));
	tmp = list->head;
	while(tmp != NULL){
		outStu((Student *)(tmp->data));
		tmp = tmp->next;
	}

	return;
}
