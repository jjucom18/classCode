#ifndef linkg_h
#define linkg_h

#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	void *data;
	struct _node *next;
} Node;

typedef struct _linkedList{
	Node *head;
	Node *tail;
	Node *current;
} LinkedList;

void initList(LinkedList *);
void addHead(LinkedList *, void *);
void addTail(LinkedList *, void *);
void delNode(LinkedList *, void *);
Node *getNode(LinkedList *, void *);
void displayList(LinkedList *);

#endif
