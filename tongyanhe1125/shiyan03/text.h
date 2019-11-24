#ifndef textt_h
#define textt_h

#include <stdio.h>
#include <stdlib.h>

#define random_1(a,b)((rand()%(b-a))+a)
#define random_2(a,b)((rand()%(b-a+1))+a)

#define ARR_SIZE 20

void bubble_sort(int arr[],int arr_size);
void insert_sort(int *array,unsigned int n);
void select_sort(int arr[],int n);
void quick_sort(int left,int right);

#endif
