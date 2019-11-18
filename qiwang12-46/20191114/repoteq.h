#ifndef reporteq_h
#define reporteq_h

#include<stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct _node{
    DataType data;
    struct _node *next;
} Node;

typedef struct _list{
    Node *head;
    Node *tail;
    Node *current;
} List;

void initList(List *);
void addHead(List *, DataType);
void addTail(List *, DataType);
Node *getNode(List *, DataType);
void deleNode(List *, DataType);
void dispList(List *);

#endif
