#ifndef work_h
#define work_h

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
void Out_SeqList(SeqList *);
SeqList *Del_element();


#endif