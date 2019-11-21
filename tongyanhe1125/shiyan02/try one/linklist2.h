#ifndef linkList_h
#define linkList_h
#include <stdio.h>
#include <stdlib.h>

typedef Strust _node{
    void *data;
    struct _node *next;
}Node,*LinkedList;

typedef struct _linkedList {
    Node *head;
    Node *tail;
    Node *current;
} ListedList;

void initializeList(ListedList *list);
void addHead(LinkedList *list, void *data);
void addTail(LinkedList *list, void *data);
void delete(LinkedList *list, Node *node);
void displayLinkedList(LinkedList *list, DISPLAY display);

#endif
