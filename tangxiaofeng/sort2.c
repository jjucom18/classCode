#include"sort.h"
int main(int argc,char **argv){
	int i;
	srand(time(NULL));
	int arr[MAXSIZE];
	for(i=1;i<MAXSIZE;i++)
	arr[i]=rand()%100;
	InsertSort1(arr,MAXSIZE);
	for(i=1;i<=10;i++)
		printf("%d\t",arr[i]);printf("\n");
	return 0;
}
