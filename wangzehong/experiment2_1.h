#ifndef list_h
#define list_h
#include<stdio.h>
#include<stdlib.h>


typedef struct_node
{int data;
	struct_ node*next;
}Node;


void InitLinklist Linklist();
void Locate Linklist(Linklist L,datatype y);
void InsertTail Linklist(Linklist *List,int data);
void InsertHead Linklist(Linklist *list,int data);

void deletenode(Linklist *list,Node *node);
void Delete LinkList(Linklist L,int i);

void displaylist(LinkedList *List);
Node *discoverData(LinkedList *list,int data);

#endif

