#ifndef stackg_h
#define stackg_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Node;
typedef struct _node {
	void *data;
	struct _node *next;
} Node;

typedef int LinkedList;
typedef struct _linkedList {
	Node *head;
	Node *tail;
	Node *current;
} LinkedList;

int COMPARE,DISPLAY;
void initializeList(LinkedList*);
void addHead(LinkedList*,void*);
void addTail(LinkedList*,void*);
void delete(LinkedList*,Node*);
Node *getNode(LinkedList*,COMPARE,void*);
void displayLinkedList(LinkedList*,DISPLAY);

#endif


