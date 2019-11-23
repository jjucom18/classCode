#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
#define random_1(a,b) ((rand()%(b-a)+a)
#define random_2(a,b) ((rand()%(b-a+1))+a)

void selectsort(int a[],int n){
	int i,j,k,m;
	for (i=0;i,n-1;i++) {
		m=a[i];
		k=i;
		for (j=i+1; j<n;j++)
			if (a[j] <m) {
				m=a[j];k=j;
			}
		a[k]=a[i];
		a[i]=m;
	}
}

int main (int argc,char **argv){
	
	{int a[N],i;
	srand (time(0));
	for (i=0; i<N;i++)
	a[i]=rand()%100;
	printf("初始数据为：");
	for (i=0;i<N;i++)
		printf("%d",a[i]);
	printf("\n");
	selectsort(a,N);
	printf("排序后数据：");
	for (i=0;i<N;i++) printf("%d",a[i]);}


	{srand ((int)time(NULL));
	int arr[10];
	for(int i=0;i<10;i++){
		arr[i] = random_1(1,20);
	}
	for(int i=0;i<10;i++){
		printf("%d\t",arr[i]);
	}
	return 0;}


}	



