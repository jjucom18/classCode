#include<stdio.h>
void output_a(int a[]);
void output_a(int a[]){
	for(int i=0;i<20;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
}
