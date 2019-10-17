#ifndef linkg_h
#define linkg_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _stu{
	char *name;
	int age;
	double record;
} Student;

typedef struct _node{
	void *data;
	struct _node *next;
} Node;

typedef struct _linkedList{
	Node *head;
	Node *tail;
	Node *current;
} LinkedList;

Student *initStu(char *name, int age, double record);
void outStu(Student *stu);
void initList(LinkedList *);
void addHead(LinkedList *, void *);
void addTail(LinkedList *, void *);
void delNode(LinkedList *, Node *);
Node *getNode(LinkedList *, void *);
void displayList(LinkedList *);

#endif
