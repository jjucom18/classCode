#ifndef 1_h
#define 1_h
#include<stdio.h>
typedef struct _node{
     void *data;
     struct _node*next;
} Node;
typedef struct _linkedList{
	Node *head;
	Node *tail;
	Node *current;
} LinkedList;
void initializeList(LinkedlList*)
void addHead(LinkedList*, void*)
void addTail(LinkedList*, void)
void delete(LinkedList*, Node*)
Node *getNode(LinkedList*, COMPARE, void*)
void displayLinkedList(LinkedList*, DISPLAY)
#endif	
