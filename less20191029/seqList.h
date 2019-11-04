#ifndef seqList_h
#define seqList_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 10

typedef int DataType;
typedef struct{
	DataType data[MaxSize];
	int last;
}SeqList;

SeqList *initList();										//初始化列表
bool emptyList(SeqList *list);								//判断表是否为空
bool fullList(SeqList *list);								//判断表是否已满
void insertElementList(SeqList *list, int k, DataType data);//在表的指定位置插入值为data的元素，
int searchLocalList(SeqList *list, DataType data);			//查找指定值元素，返回下标
DataType searchElementList(SeqList *list, int k);			//查找制定位置的元素，返回元素值
void delLocalList(SeqList *list, int k);					//删除制定位置的元素
void delElementList(SeqList *list, DataType data);			//删除指定值的元素
void outList(char *msg, SeqList *list);

#endif
