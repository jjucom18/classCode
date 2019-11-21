#include "shiyan3g.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define random_1(a,b) ((rand()%(b-a))+a) 
#define random_2(a,b) ((rand()%(b-a+1))+a)

typedef int datatype;   //定义整型数据类型

typedef struct{
	datatype data[MAXSIZE];
	int size;
}seqlist;

int main(int argc,char **argv){
	srand((int)time(NULL));
	int arr[20];
	for(int i = 0;i < 20;i++){
		arr[i] = random_1(1,20); 
	}
	for(int i = 0;i < 20;i++){
		printf("%d\t",arr[i]);
	}
	return 0;
}

seqlist *initseq(){                                            //初始化排序表
	seqlist *list = (seqlist *)malloc(sizeof(seqlist));
	list->last = -1;

	return list;
} 	
				
void D_Insertseq(datatype arr[],int n){
	for(i=2;i<=n;i++)
		if(arr[i]<arr[i-1]){
			arr[0]=arr[i];
			for(j=i-1;arr[0]<arr[j];j--)
				arr[j+1]=arr[j];
			arr[j+1]=arr[0];	
	        }
} 
void Shellseq(datatype arr[],int n,int d[],int t){
	int i,j,k,h;
	for(k=0;k<t;k++){
		h=d[k];
		for(i=h+1;i<=n;i++)
			if(arr[i]<arr[i-h]){
				arr[0]=arr[i];
				for(j=i-h;j>0&&arr[0]<arr[j];j=j-h)
					arr[j+h]=arr[j];
				    arr[j+h]=arr[0];
			}
	}
}
void Quick_seq(datatype arr[],int s,int t){
	if(s<t){
		i=Partition(arr,s,t)
		Quick_seq(arr,s,i-1);
		Quick_seq(arr,i+1,t);
	}
}
void Select_seq(datatype arr[],int n){
	for(i=1;i<n;i++){
		k=i;
		for(j=i+1;j<=n,j++)
			if(arr[j]<arr[k])
				k=j;
		    if(i!=k){
				arr[0]=arr[k];
				arr[k]=arr[i];
				arr[i]=arr[0];
			}
	}
}

