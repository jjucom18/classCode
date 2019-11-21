#include"test6.h"

int main(int argc,char **argv)
{
	int a[]={12,23,34,45,67,78,89,90,68};
	int n=sizeof(a)/sizeof(int);
	printf("sort before:\n");
	for(int j=0;j<n;j++){
		printf("%d\t",a[j]);
	}
	printf("\n");
	printf("sort after:\n");
	SelectSort(a,n);
	for(int i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
}

