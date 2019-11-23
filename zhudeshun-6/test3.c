#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20

void bubble(int a[],int n){
	int i,j,t;
	for (i=1;i<n;i++){
	for (j=0;j<n-i;j++){
	if (a[j]>a[j+1]){
	t = a[j];
	a[j] = a[j+1];
	a[j+1] = t;
	}
	}
	}
}

void insertsort(int a[],int n){
	int i ,j,temp;
	for (i=1; i<n;i++){
	temp = a[i];
	j=i-1;
	while (j>=0 && a[j]>temp){
	a[j+1]=a[j];
	j--;
	}
	a[j+1] = temp;
	}
}

void selectsort(int a[],int n){
	int i,j,k,m;
	for (i=0;i<n-1;i++){
	m=a[i];
	k=i;
	for (j=i+1;j<n;j++)
	if(a[j]<m){
	m=a[j];k=j;
	}
	a[k] = a[i];
	a[i] = m;
	}
}

int partition(int a[],int low,int high){
	int x = a[low];
	while (low<high){
	while (low<high && a[high]>=x) high--;
	if (low < high){
	a[low] = a[high];
	low++;
	}
	while (low<high && a[low]<=x) low++;
	if (low < high){
	a[high] = a[low];
	high--;
	}
	}
        a[low] = x;
	return low;
}
void Qsort(int a[],int low, int high){
	if (low < high){
	int mid = partition(a,low,high);
	Qsort(a,low,mid-1);
	Qsort(a,mid+1,high);
	}	
}
void Quicksort(int a[],int n){
	Qsort(a,0,n-1);
}
int main(int argc, char **argv){
    int a[N],i;
    srand(time(0));
    for (i=0;i<N;i++)a[i] = rand() % 100;
    printf("初始数据为:");  
    for (i=0;i<N;i++)
    printf("%d ",a[i]);
    printf("\n");
    bubble(a,N);
    printf("冒泡排序后数据:");
    for (i=0;i<N;i++) printf("%d ",a[i]);
    printf("\n");										 
    insertsort(a,N);
    printf("直接插入排序后数据:");
    for (i=0;i<N;i++) printf("%d ",a[i]);
    printf("\n");
    selectsort(a,N);
    printf("简单选择排序后数据:");
    for (i=0;i<N;i++) printf("%d ",a[i]);
    printf("\n");																	       
    Quicksort(a, N);
    printf("快速排序后数据:");
    for (i=0;i<N;i++) printf("%d ",a[i]);
    printf("\n");
    }
