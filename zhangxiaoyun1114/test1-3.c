#include<stdio.h>
#include<stdlib.h>
int main(int argc,char **argv){
	int arr[]={18,11,12,36,84,21};
	int arrSize=sizeof(arr)/sizeof(int);
int *ptr=(int*)malloc(sizeof(int)*arrSize);
ptr=arr;
for(int i=0;i<arrSize;i++){
printf("%p,%d\n",ptr+i,*(ptr+i)) ;
} 
	return 0;
}
