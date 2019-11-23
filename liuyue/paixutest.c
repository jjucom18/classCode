#include"testpaixu.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc,char **argv)
{
	srand((int)time(NULL));
	int a[10];
	int n=20;
	for(int i=0;i<10;i++){
		a[i]=random_1(1,20);
	}display(a,20);

Selet_Sort( a, n);display(a,20);
InsertSort( a, n);display(a,20);
Bubblel(a, n);display(a,20);
QuickSort( a, n);display(a,20);} 
