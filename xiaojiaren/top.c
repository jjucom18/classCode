#ifndef shiyan2_h
#define shiyan2_h
#include <stdio.h>
#include <stdlib.h>



typedef struct _node
{

		int  data;
			struct _node *next;
} Node;

typedef struct _linkedList
{

		Node *head;
			Node *tail;
				Node *current;
} LinkedList;


void initList (LinkedList *list) ;

void addTail(LinkedList *list, int data) ;
void addHead(LinkedList *list, int data) ;
void delNode(LinkedList *list,Node *node) ;

void displayList(LinkedList *list) ;
Node *FindData(LinkedList *list,int data) ;

#endif


