#include<stdio.h>
#include "test1.h"


typedef struct _people{
	int number;
	 Node *next;
}People;
typedef Node *LinkList;

void InitPeople(People *P)
		{P=(People*)malloc(sizeof(People));
		P_>next=Null;}

bool Inser_headPeople(People *P,data *x)
{int j=0;
	People *p=P,*q;
	while(j<i-1&&p!=Null)
	{j++;
		p=p->next;
	}
	if(p==Null)
		return false;
	else
	{p=(People *)malloc(sizeof(People));
		q->data=x;
		q->next=p->next;
		p->next=q;}
printf("this is head: ");
printf("x=%d\n",x);
}
bool DelPeople(People *P,int i,data x)
{int j=0;
	People *p=P,*s;
	while(j<i-1&&p!=Null)
	{j++;
		p=p->next;
	}
	if(p==Null)
		return false;
	else
	{s=p->next;
		x=s->data;
		p->next=s->next;
		free(s);
		printf("successful delete\n");
void LocatePeople(People P,data x)
