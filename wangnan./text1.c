#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20


//直接插入排序
void InsertSort(int a[], int n) {
	int i, j, temp;
	for (i=1; i<n; i++){
		temp = a[i];
		j = i - 1;
		while (j>=0 && a[j]>temp){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
	}
}
//直接选择排序
void SelectSort(int a[], int n){
	int i, j, k, m;
	for(i=0;i<n-1; i++){
		m =a[i];
		k = i;
		for (j=i+1; j<n; j++)
			if (a[j] < m){
				m=a[j]; k=j;
			}
		a[k] = a[i];
		a[i] = m;
	}
}
int main(){
	int a[N], i;
	srand(time(0));
	for (i=0; i<N; i++)
		a[i] = rand() % 100;
	printf("初始数据为:");
	for (i=0; i<N; i++)
		printf("%d", a[i]);
	printf("\n");
	InsertSort(a, N);
	//SelectSort(a, N);
	printf("排序后数据:");
	for (i=0; i<N; i++) printf("%d", a[i]);

}
