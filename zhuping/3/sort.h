#ifndef sort_h                                                                                      
#define sort_h
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
	
#define random_1(a,b)((rand()%(b-a))+a) 
#define random_2(a,b)((rand()%(b-a+1))+a) 
#define MAXSIZE 200
void insertSort(int R[] ,int n); 
void Bubble_Sort(int R[]  ,int n) ;
void Select_Sort(int R[]  ,int n) ;
void Qoick_Sort(int R[]  ,int s,int t); 
	 
#endif
