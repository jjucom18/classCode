#ifndef test1_h
#define test1_h
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct _people{
	int number;
	 Node *next;
}People;
typedef Node *LinkList;

void InitPeople(People *P);
bool emptyPeople(People P);
bool pullPeople(People P);
bool InserPeople(People *P,int i，data x);
bool DelPeople(People *P,int i,data x);
void LocatePeople(People P,data x);

#endif
