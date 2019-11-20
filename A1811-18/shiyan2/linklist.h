#ifndef linklist_h
#define linklist_h
#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef struct LNode{
	datatype data;
	struct LNode *next
}LNode,*linklist;

int createlist1(linklist head);//在表头插入
int createlist2(linklist head);//在表尾插入
int dellist(linklist L,int i);//删除单链表中的地i个元素
void linklist_out(linklist head);//顺序打印单链表的元素
int get_linklist(linklist L,int i);//返回某个特定的值



#endif
