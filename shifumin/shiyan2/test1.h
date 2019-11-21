#ifndef list_h
#define list_h

#define MAXSIZE 10;
typedef int Datadata;
typedef struct{
	DataType data[MAXSIZE];
	int size;
} LinkedList;

void initializeList(LinkedListi *list);
void addHead(LinkedList *list,void *data);
void addTail(LinkedList *list,void *data);
void delete(LinkedList *list,Node *node);
Node *getNode(LinkedList *list,void*data);
void displayLinkedList(LinkedList *list);

#endif
