#ifndef link_h
#define link_h

#include <stdio.h>

#define Maxsize 20
typedef int DataType;
typedef struct{
	DataType data[Maxsize];
}outArr;

void outArr(int arr[], int n);
void insertSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void selectSort(int arr[], int n);
void shellSort(int arr[], int n);


#endif
