#ifndef"Parking_Lot_h"
#define"Parking_Lot_h"
#include<stdio.h>
#include<stdlib.h>

#define MaxSize 100
typedef int DataType;
typedef struct node
{
	DataType data;
	struct node *next;
}Node;

typedef struct 
{
	Node *top;
}linkStack;

void Push(linkStack &p,int i);
void Pop(linkStack &p,int &i);
#endif
