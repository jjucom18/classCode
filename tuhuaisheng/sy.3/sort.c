#ifndef sort_h
#define sort_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MaxSize 10
#define random_1(a,b) ((rand()%(b-a)) +a)
#define random_2(a,b) ((rand()%(b-a+1))+a)
int main (int argc,char **argv){
	strand((int)time(NULL));
	int arr[10];
	for(int i=0;i<10;i++){
		arr[i]=random_1(1,20);
	}
	for(int i=0;i<10;i++){
		printf("%d\t",arr[i]);
	}
	return 0;
}
typedef int DataType;
typedef struct{
	DataType data[MaxSize];
	int top;
}SepStack;
#endif
