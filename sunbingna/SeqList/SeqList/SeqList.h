#ifndef SeqList_h
#define SeqList_h

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 10

typedef int DataType;
typedef struct 
{
    DataType data[MaxSize];
    int leng;
}SeqList;

SeqList *initSeqList();
bool EmptyList(SeqList *list);
bool FullList(SeqList *list);
void inLocalList(SeqList *list,int k,DataType data);
int searchLocalList(SeqList *list,DataType data);//查找指定位置元素返回下标
DataType searchElementList(SeqList *list,int k);//查找指定值的元素返回元素值
void deLocalList(SeqList *list,int k);//删除指定位置的元素
void deElementList(SeqList *list,DataType data);//删除指定值的元素
void outList(char *msg,SeqList *list);

#endif
