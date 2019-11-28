#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20

int main(int agrc,char **argv)

int a[N]
{
	srand((int)time(NULL));
	for(int i = 0;i < N; i++)
		a[i] = rand()%100;
	printf("初始数据为:");
	for(i=0;i<N;i++) printf("%d",a[i]);printf("\n");
	bubble(a,N);
	printf("冒泡排序后的数据：")；
	for(i=0;i<N;i++) printf("%d",a[i]);printf("\n");
	insertsort(a,N);
	printf("直接插入排序后的数据：");
	for(i=0;i<N;i++) printf("%d",a[i]);printf("\n");
	selectsort(a,N);
	printf("简单排序后的数据：");
	for("i=0;i<N;i++") printf("%d",a[i]);printf("\n");
	Quicksort(a,N);
	printf("快速排序后数据：");
	for(i=0;i<N,i++) printf("%d",a[i]);printf("\n");
	shellsort(a,N);
	printf("希尔排序后的数据：");
	for(i=0;i<N;i++)printf("%d",a[i]);printf("\n");
	return 0;
}
