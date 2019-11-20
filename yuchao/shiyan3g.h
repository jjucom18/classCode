#ifndef seqlistg_h
#define seqlistg_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 20
typedef int datatype;                                  //定义整型数据类型

typedef struct{
	datatype data[MAXSIZE];
	int size;
}seqlist;

seqlist *initseq();
void D_Insertseq(datatype R[],int n);                  //直接插入排序
void Shellseq(datatype R[],int n,int d[],int t);       //希尔排序
int Partition(datatype arr[],int low,int high);        //划分算法
void Quick_seq(datatype R[],int s,int t);              //快速排序 
void Select_seq(datatype R[],int n);                   //简单选择排序

#endif
