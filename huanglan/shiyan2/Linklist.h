#ifndef  Linklist_h
#define  Linklist_h

typedef char ElenType;
typedef struct _node
{void *data;
 struct _node *next;

}Node;
typedef struct _linkedList{
	Node *head;
	Node *tail;
	Node *current;
}LinkedList;
typedef void(*DISPLAY)(void*);
typedef int(*COMPARE)(void*,void*);
typedef struct _employee{
char name[32];
unsigned char age;
}Employee;


void initializeList(LinkedList *list);
void addHead(LinkedList *list,void* data);
void addTail(LinkedList *list,void* data);
void delete(LinkedList *list,Node *node);
void displayLinkList(LinkedList *list);
int compareEmploye(Employee *el,Employee *e2)
void displayEmployee(Employee* employee)
	

#endif



















