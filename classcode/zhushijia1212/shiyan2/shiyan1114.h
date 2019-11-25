#ifndef list_h
#define list_h
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
 int getLength(List *);
 void dispList(List *);
 #endif