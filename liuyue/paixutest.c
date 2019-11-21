#include"paixutest.h"

int main(int argc,char **argv)
{
	srand((int)time(NULL));
	int a[10];
	for(int i=0;i<10;i++){
		a[i]=random_1(1,20);
	}
}

Selet_Sort(int a[],int n);
InsertSort(int a[],int n);
Bubblel(int a[],int n);
QuickSort(int a[],int n);
