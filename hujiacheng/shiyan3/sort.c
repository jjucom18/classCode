#include"sort.h"
void D_InsertSort(datatype R[],int n){ 
	printf("直接插入排序\n");
	int i,j;
	for(i=2;i<=n;i++)
		if(R[i].key<R[i-1].key){
			R[0] =R[i];
			for(j=i-1;R[0].key<R[j].key;j--)
				R[j+1]=R[j];
			R[j+1]=R[0];
		}
 } 

void Bubble_Sort(datatype R[],int n){ 
	printf("冒泡排序\n");
	int i,j;
	int swap;
	datatype element;
	for(i=1;i<n-1;j++){
		swap = 0;
	  for(j=1;j<=n-1;j++)
		if(R[j].key>R[j+1].key){
		element=R[j+1];
		R[j+1]=R[j];
		R[j]=element;
		swap =1; }
	if(swap == 0) break;	
	}
  } 

int Partition(datatype R[],int low,int high){//划分算法
	datatype element;
	element=R[low];
	while(low<high){
	while(low<high&&R[high].key>=element.key)
		high--;
	if(low<high){R[low]=R[high];low++; }
	while(low<high&&R[low].key<element.key)
		low++;
	if(low<high){
	R[high]=R[low];high--; }
		}
	R[low]=element;
	return low;
}
void Quick_Sort(datatype R[],int s,int t){
	int i;
	if(s<t){ 
	i =Partition(R,s,t);
	Quick_Sort(R,s,i-1);
	Quick_Sort(R,i+1,t);
	}
void Select_Sort(datatype R[],int n){
	datatype element;
	printf("简单选择排序\n");
	int i, k,j;	
	for(i=0;i<=n;i++){
		k=i;
		for(j=i+1;j<=n;j++)
			if(R[j].key<R[k].key)
				k=j;
		if(i!=k){
			element=R[k];
			R[k]=R[i];
			R[i]=element;
		}	}	
}


void display(datatype R[],int n){
		int i;
		for(i=1;i<=n;i++){
			printf("%d  ",R[i+1].key);
		}
}

