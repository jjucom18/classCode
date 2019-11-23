#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
#define random_1(a,b) ((rand()%(b - a)) + a)
#define random_2(a,b) ((rand()%(b - a + 1)) +a)

void InsertSort(int R[],int n){
	int i,j,t;
for(i=1;i<n;i++){
	t=R[i];
	j=i-1;
	while(j>=0 && R[j]>t){
		R[j=1]=R[j];
		j--;
	}
	R[j+1]=t;
}
}

void BubbleSort(int R[],int n){
	int i,j,t;
	for (i=1;i<n;i++){
		for (j=0;j<n-i;j++){
			if (R[j]>R[j+1]){
				t=R[j];
				R[j]=R[j+1];
				R[j+1]=t;
			}
		}
	}
}

void SelectSort(int R[],int n){
	int i,j,k,m;
	for (i=0;i<n-1;i++){
		m=R[i];
		k=1;
		for (j=i+1;j<n;j++)
			if (R[j]<m){
				m=R[j]; k=j;
			}
		R[k]=R[i];
		R[i]=m;
	}
}

void ShellSort(int R[],int n){
	int i,j,t;
	t=n/2;
	while(t>=1){
		for(i=t+1;i<=n;i++){
			R[0]=R[i];
			j=i-t;
			while((j>0)&&(R[0]<R[j])){
				R[j+t]=R[j];
				j=j-t;
			}
			R[j+t]=R[0];
		}
		t=t/2;
	}
}
int main(int argc, char **argv){
    srand((int)time(NULL));
    int arr[10];
    for(int i=0; i<10; i++){
	arr[i] = random_1(1,20);
    }
    for(int i=0; i<10; i++){
	printf("%d\t",arr[i]);
    }
    return 0;
	int R[N], i;
	srand(time(0));
	for(i=0;i<N;i++)
		R[i]=rand() % 100;
	printf("初始数据为：");
	for (i=0;i<N;i++)
		printf("%d",R[i]);
	printf("\n");
	InsertSort(R,N);
	BubbleSort(R,N);
	SelectSort(R,N);
	ShellSort(R,N);
	printf("排序后数据:");
	for (i=0;i<N; i++) printf("%d",R[i]);
}
