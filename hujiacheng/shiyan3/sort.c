#include"sort.h"
void D_InsertSort(datatype R[],int n){ //直接插入排序
	int i,j;
	for(i=2;i<=n;i++)
		if(R[i].key<R[i-1].key){
			R[0] =R[i];
			for(j=i-1;R[0].key<R[j].key;j--)
				R[j+1]=R[j];
			R[j+1]=R[0];
		}
  } 

void Bubble_Sort(datatype R[],int n){ //冒泡排序
	int i,j;
	int swap;
	for(i=1;i<n-1;j++){
		swap = 0;
	  for(j=1;j<=n-1;j++)
		if(R[j].key>R[j+1].key){
		R[0]=R[j+1];
		R[j+1]=R[j];
		R[j]=R[0];
		swap =1; }
	if(swap == 0) break;	
	}
  }  

int Partition(datatype R[],int low,int high){//划分算法
	R[0]=R[low];
	while(low<high){
	while(low<high&&R[high].key>=R[0].key)
		high--;
	if(low<high){R[low]=R[high];low++; }
	while(low<high&&R[low].key<R[0].key)
		low++;
	if(low<high){
	R[high]=R[low];high--; }
		}
	R[low]=R[0];
	return low;
}
void Quick_Sort(datatype R[],int s,int t){//快速排序
	if(s<t){ int i;
	i =Partition(R,s,t);
	Quick_Sort(R,s,i-1);
	Quick_Sort(R,i+1,t);
	}
  }
void Select_Sort(datatype R[],int n){//简单选择排序
	int i, k,j;	
	for(i=1;i<n;i++){
		k=i;
		 for(j=i+1;j<=n;j++)
		   if(R[j].key<R[k].key)
			 k=j;
		 if(i!=k){
		 R[0]=R[k];
		 R[k]=R[i];
		 R[i]=R[0];
		 }
	}
}

int    display(datatype R[],int n){
	int i;
	for(i=1;i<n;i++){
	printf("%d\t",R[i].key);
	}
}

