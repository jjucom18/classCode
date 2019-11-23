#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define random_1(a,b) ((rand()%(b-a))+a)
#define random_1(a,b) ((rand()%(b-a+1))+a)

int main(int argc, char **argv)
{
	int i;
	srand((int)time(NULL));
	int arr[10];
	int n = 10;
	for( i = 0; i<10; i++){
		arr[i]= random_1(1,20);
	}
		InsertSort(i,n);
		SelectSort(i,n);
		bubble1(i,n);
		bubble2(i,n);
		bubble3(i,n);
		QuickSort(i,n);
		for(i=0; i<10;i++){
			printf("%d\t",arr[i]);

		}

	
return 0;
}
