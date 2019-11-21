#include"test5.h"

int main(int argc,char **argv)
{
	int a[]={24,67,45,78,69,98,78,65,45};
	int n=sizeof(a)/sizeof(int);
	printf("sort before:\n");
	for(int j=0;j<n;j++){
		printf("%d\t",a[j]);
	}
	printf("\n");
	printf("Sort after:\n");
	ShellSort(a,n);
	for(int i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
}



