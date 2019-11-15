#ifndef test_h
#define test_h
#include <stdio.h>
#include <stdlib.h>


typedef struct _node{
    int data;
    struct _node *next;
} Node;

typedef struct _linkedList{
    Node *head;
    Node *tail;
    Node *current;
} LinkedList;

void initList(LinkedList*);
void addHead(LinkedList*,int);
void addTail(LinkedList*,int);
void delete(LinkedList*,Node*);
Node *getNode(LinkedList*,int);
void displayLinkedList(LinkedList*);

#endif
