#ifndef workclass_h
#define workclass_h

#define MaxSize 20
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
SeqList *bubbleSort(SeqList *);
void Inout_SeqList(SeqList *);
SeqList *Delete_element();


#endif