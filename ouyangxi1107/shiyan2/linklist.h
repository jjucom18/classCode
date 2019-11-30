#ifndef linklist_h
#define linklist-h
#include<stdio.h>
  2 #include<stdlib.h>
  3 #include<string.h>
  4 
  5 typedef int DataType;
  6 
  7 typedef struct Node{
  8 DataType data;//定义单链表数据域
  9 
 10 struct Node *next;//定义单链表指针域
 11 }Node,*LinkedList;

LinkedList initLinkedList();
LinkedList Creat_LinkedListT();
LinkedList Creat_LinkedListW();
LinkedList Delete_LinkedList(LinkedList L,DataType i);
LinkedList InsertLinkedList(LinkedList L,int i,DataType x);

#endif
