#ifndef test2_h
#define test2_h
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int datatype;
typedef struct _node
{ 
        datatype data;
	struct _node *next;
}Node;
typedef struct _list
{
	Node *head;
	Node *tail;
}List;
void initList(List *);
void addHead(List *,datatype);
void addTail(List *,datatype);
void deleNode(List *,datatype);
Node *getNode(List *,datatype);
void dispList(List *);



#endif
	

              


	
	


