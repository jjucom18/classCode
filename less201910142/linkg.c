#include "linkg.h"

typedef struct _stu{
	char *name;
	int age;
	double record;
} Student;

typedef struct _node{
	void *data;
	struct _node *next;
} Node;

typedef struct _linkedList{
	Node *head;
	Node *tail;
	Node *current;
} LinkedList;

Student initStu(char *name, int age, double record){
	//DONE
}

void outStu(Student stu){
	//DONE
}

void initList(LinkedList *list){
	list->head = NULL;
	list->tail = NULL;
	list->current = NULL;

	return;
}

void addHead(LinkedList *list, void *data){
	Node *node = (Node *)malloc(sizeof(Node));
	//Student stu = initStu("zhangsan", 20, 78.5);
	//node->data = (Student *)malloc(sizeof(Student));
	//node->data->name = (char *)malloc(30);
	node->data = data;

	if(list->head == NULL){
		list->tail = node;
		node->next = NULL;
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
void delNode(LinkedList *, Node *);
Node *getNode(LinkedList *, void *);
void displayList(LinkedList *);
