#ifndef reporte6_h
#define reporte6_h

#include<stdio.h>
#include<time.h>

#define MaxValue 10000

typedef struct _HNodeType{
	int weight;
	int parent;
	int lchild;
	int rchild;
}HNodeType;

void CreateHFMTree(HNodeType HFMTree[], int n);

#endif