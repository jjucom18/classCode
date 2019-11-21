#include"sort.h"
int main(int argc,char **argv){
    DataType a[20];
	int i,n=20,low=0,high=20;
	srand((int)time(NULL)) ;
	for(i=0;i<20;i++){
		a[i].key=random_1(1,20);}
QuickSort(a,n);display(a,20);
BubbleSort(a,n);display(a,20);
SelectSort(a,n);display(a,20);
InsertSort(a,n);display(a,20);} 
