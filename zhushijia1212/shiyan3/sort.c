#include"sort.h"

void InsertSort(int list[],int n){
	int i,j;
	int compare = 0;
	int move = 0;
	for (i = 2; i < n; ++i){
		if (list[i] < list[i-1],compare++){
			
			list[0] = list[i];
			for (j = i-1; list[0] < list[j]; --j,compare++){
				move++;
				list[j+1] = list[j];
			}
			list[j+1] = list[0];
		}
	}
	printf("关键字比较次数为%d\n",compare);
	printf("关键字移动次数为%d\n",move );
	return;
}


void bubbleSort(int list[],int n){
	int tmp;
	int i,j;
	for (i = 0; i < n; ++i)
		for (j = 0; j <n-i; ++j){
			if (list[j] > list[j+1]){
				tmp = list[j];
				list[j] = list[j+1];
				list[j+1] = tmp;
			}
		}
		return;
}

void Selectsort(int list[],int n)
{
	int i,j,k;
	for (i=1;i<n;i++)
	{k=i;
		for(j=i+1;j<=n;j++)
			if(list[j]<list[k])
				k=j;
			if(i!=k)
			{list[0]=list[k];
				list[k]=list[i];
				list[i]=list[0];

			}

	}
}
int partition(int list[],int low,int high)
{
	list[0]=list[low];
	while(low<high){

		while(low<high && list[high]>=list[0])
			high--;

		if(low<high){
			list[low]=list[high];low++;
		}
		while(low<high&&list[low]<list[0])
			low++;

		if(low<high){
			list[high]=list[low];high--;
		}
	}
		list[low]=list[0];
	return low;
}
void QuickSort(int list[],int s,int t)
{
	int i;
	if(s<t)
	{i=partition(list,s,t);
		QuickSort(list,s,i-1);
		QuickSort(list,i+1,t);

	}
}