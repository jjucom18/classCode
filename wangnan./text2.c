#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20


//冒泡排序1，从前往后
void bubble1(int a[], int n){
	int i, j, t;
	for (i=1; i<n; i++){
		for (j=0; j<n-1; j++){
			if (a[i] > a[j+1]){
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
}

//冒泡排序2，从后往前
void bubble2(int a[], int n){
	int i, j, t;
	for (i=0; i<n-1; i++){
		for (j=n-1; j>i; j--){
			if (a[j-1] >a[j]){
				t = a[j-1];
				a[j-1] = a[j];
				a[j] = t;
			}
		} 
	} 
} 

//冒泡排序3，加上标志flag
void bubble3(int a[], int n){
	int i, flag=1, t;
	for (i=1; i<n && flag==1; i++) {
		flag = 0;
		for(int j=0; j<n-1; j++) {
			if (a[j] > a[j+1]) {
				t= a[j];
				a[j]= a[j+1];
				a[j+1] = t;
				flag = 1;
			}
		}
	}
}

int main(){
	int a[N],i;
	srand(time(0));

	for (i=0; i<N; i++)
		a[i] = rand () % 100;
	printf("初始数据为: ");

	for (i=0; i<N; i++)
		printf("%d", a[i]);
	printf("\n");
	bubble1(a, N);
	//bubble2(a,N);
	//bubble3(a, N);
	printf("排序后数据: ");
	for (i=0; i<N; i++)
		printf("%d", a[i]);
}
