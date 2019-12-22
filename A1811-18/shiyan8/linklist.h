#ifndef library_h
#define library_h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	int year;
	int month;
	int day;
}Data;
typedef struct{
	int id;
	Data DATA;
	char name[20];
	char author_name[20];
	char info[50];
	char publish[20];
	double price;
}book;
typedef struct Node{
	book data;
	struct Node *next;
	int count;//计数器
}linklist;


linklist *Init();
int seacher(linklist *head);
linklist *change(linklist *head);
int insert(linklist *head);
void display(linklist *head);
int del(linklist *head);
void bubble_id(linklist *head);
void bubble_price(linklist *head);
int findByname(linklist *head);
int findByauthor_name(linklist *head);
void count(linklist *head);

#endif
