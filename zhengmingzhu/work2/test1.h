#ifndef testc_h
#define testc_h
#include<stdio.h>
#include<stdlib.h>

typedef int DataType;

typedef struct _node{
	DataType data;
	struct _node *next;
}Node;

typedef struct _list{

	Node *head;
	Node *tail;
	Node *current;
}List;

void initList(List *list);
void addHead(List *list,DataType data);
void addTail(List *list,DataType data);	
void deleteNode(List *list,Node *node);
Node *getNode(List *list,DataType data);
void displayList(List *list);	


#endif
