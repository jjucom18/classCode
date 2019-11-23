#ifndef testc_h
#define testc_h
#include<time.h>

#define random_1(a, b) ((rand()%(b - a)) +a)
#define random_2(a, b) ((rand()%(b - a + 1)) + a)
#include<stdio.h>
#include<stdlib.h>

void selectSort(int arr[],int n);
void bubbleSort(int arr[],int n);
void insertSort(int arr[],int n);
void shellSort(int arr[],int n);
void createrandom(int arr[10]);

#endif
