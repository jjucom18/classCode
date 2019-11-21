#ifndef text_h
#define text_h
#include <stdio.h>
#include <stdlib.h>

typedef int dataType;
typedef struct {
    dataType data;
    struct node *next;
}node;
typedef struct node {
    dataType data;
    struct node *next;
} LinkList;

LinkList* CreateList ();
int Size(LinkList *l);
void Insert (LinkList *l,int k,dataType x);
void Delete(LinkList *l,int k);
int Empty(LinkList *l);
dataType GetData(LinkList *l,int k);
node* Find(LinkList *l, dataType x);
void Print(LinkList *l);
void ClearList(LinkList *l);

#endif
