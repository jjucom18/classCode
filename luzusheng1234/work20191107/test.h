#ifndef test_h
#define test_h

#define MaxSize 50
#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct 
{
	DataType data[MaxSize];
	int last;
}SeqList;

SeqList *init_SeqList();
void Input_SeqList(SeqList *,DataType);
void bubbleSort(SeqList *);
void Out_SeqList(SeqList *);
void Del_data();


#endif
