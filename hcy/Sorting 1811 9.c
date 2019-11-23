#include"stdio.h"
#include"stdlib.h"
#include<stdbool.h>
#define Max 20
typedef struct{
	int key;
}RecType;
typedef RecType SeqList[Max+1];
int n;
void InserSort(SeqList R){
	int i,j;
	for(i=2;i<=n;i++)
		if(R[i].key<R[i-1].key){
			R[0]=R[i];
			j=i-1;
			do{
				R[j+1]=R[j];
				j--;
			}while(R[0].key<R[j].key);
			R[j+1]=R[0];
		}
}
typedef enum{
	FALSE,TRUE
}
    Boolean;
void BubbleSort(SeqList R){
	int i,j;
	Bool exchange;
	for(i=1;i<n;i++){
		exchange=false;
		for(j=n-1;j>=i;j--){
			if(R[j+1].key<R[j].key){
				R[0]=R[j+1];
				R[j+1]=R[j];
				R[j]=R[0];
				exchange=true;
			}
			if(!exchange)return;
		}
	}
}
int Partition(SeqList R,int i,int j){
	RecType pivot=R[i];
	while(i<j){
		while(i<j&&R[j].key>=pivot.key)
			j--;
		if(i<j)
			R[i++]=R[j];
		while(i<j&&R[i].key<=pivot.key)
			i++;
		if(i<j)
			R[j--]=R[i];
	}
	R[i]=pivot;
	return i;
}
void QuickSort(SeqList R,int low,int high){
	int pivotpos;
	if(low<high){
		pivotpos=Partition(R,low,high);
		QuickSort(R,low,pivotpos-1);
		QuickSort(R,pivotpos+1,high);
	}
}
void SelectSort(SeqList R){
	int i,j,k;
	for(i=1;i<n;i++){
		k=i;
		for(j=i+1;j<=n;j++)
			if(R[j].key<R[k].key)
				k=j;
		if(k!=i){
			R[0]=R[i];
			R[i]=R[k];
			R[k]=R[0];
		}				
	}
}
void MergeSort(SeqList R){
	int length;
	for(length=1;length<n;length*=2)
		MergePass(R,length);
}
void input_int(SeqList R){
	int i;
	printf("Please input num(int):");
	scanf("%d",&n);
	printf("Please input %d integer:",n);
	for(i=1;i<=n;i++)
		scanf("%d",&R[i].key);
}
void output_int(SeqList R){
	int i;
	for(i=1;i<=n;i++)
		printf("%4d",R[i].key);
}
void main(){
	int i;
	SeqList R;
	input_int(R);
	printf("\t\n");
	printf("\t1:lnsert Sort\n");
	printf("\t2:Bubble Sort\n");
	printf("\t3:Quick Sort\n");
	printf("\t4:Straight Selection Sort\n");
	printf("\t");

}
