#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20


//先将定义的数组分为两个区
int Partition(int a[], int low, int high){
	int x = a[low];
	while (low < high) {
		while (low <high && a[high]>=x) high--;
		if (low < high){
			a[low]  = a[high] ;
			low++;
		}
		while (low<high && a[low]<=x) low++;
		if (low <high); {
			a[high] = a[low];
			high--;
		}

	}
	a[low] = x;
	return low;
}

//另一个分区算法
int Partition2(int a[], int low, int high) {
	int i=low, j=high+1, x=a[low], t;
	while (i < j){
		do i++; while (a[i] < x);
		do j--; while (a[j] > x);
		if (i < j){
			t= a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	a[low] = a[j];
	a[j] = x;
	return j;
}

//将a数组的区间[low..high]的元素进行快速排序
void QSort(int a[] , int low, int high){
	if (low < high){
		int mid = Partition(a, low, high);
		//int mid = Partition2(a, low, high);
		QSort(a, low, mid-1);
		QSort(a, mid+1, high);
	}
}
//快速排序
void QuickSort(int a[], int n){
	QSort(a, 0, n-1);
}

int main() {
	int a[N], i;
	srand(time(0));
	for (i=0; i<N; i++)
       a[i] = rand() % 100;
	printf("初始数据为: ");
	for (i=0; i<N; i++)
		printf("%d", a[i]);
	printf("\n");
	QuickSort(a, N);
	//MergeSort2(a, N);
	printf("排序后的数据: ");
	for (i=0; i<N; i++)
		printf("%d",a[i]);
} 
