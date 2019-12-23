#ifndef hotel_h
#define hotel_h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	int year;
	int month;
	int day;
}Data;
typedef struct{
	int id;//房号
	Data DATA;
	char name[20];
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
int seacher(linklist *head);//按id进行查找
linklist *change(linklist *head);//修改房间信息
linklist *insert(linklist *head);//添加房间
void display(linklist *head);//展示
int del(linklist *head);//按id删除房间
int findByname(linklist *head);//根据名字进行查找
void count(linklist *head);//计算所有客房

#endif
