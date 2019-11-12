#ifndef data_h
#define data_h

#define MAXSIZE 50
#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct 
{
	DataType data[MAXSIZE];
	int last;
}SeqList;

SeqList *init_SeqList();
void Input_SeqList(SeqList *,DataType);
SeqList *bubbleSort(SeqList *);
void Out_SeqList(SeqList *);
SeqList *Del_data();


#endif