#include"sort.h"

void InsertSort(datatype list[],int n){
	int i,j;
	int compare = 0;
	int move = 0;
	for (i = 2; i < n; ++i){
		compare++;
		if (list[i].data < list[i-1].data){
			list[0] = list[i];
			compare++;
			for (j = i-1; list[0].data < list[j].data; --j){
				
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

void bubbleSort(datatype list[],int n){
	int tmp;
	int i,j;
	int compare = 0;
	int move = 0;
	for (i = 0; i < n; ++i)
		for (j = 0; j < n-i; ++j){
			compare++;
			if (list[j].data > list[j+1].data){
				
				move++;
				tmp = list[j].data;
				list[j].data= list[j+1].data;
				list[j+1].data = tmp;
			}
		}
		printf("关键字比较次数为%d\n",compare);
		printf("关键字移动次数为%d\n",move );
		return;
}
void SelectSort(datatype list[],int n){
	int i,j;
	int tmp;
	int compare = 0;
	int move = 0;
	for (i = 1; i < n; ++i){
		tmp = i;
		for (j = i+1; j <n; ++j){
			compare++;
			if (list[j].data < list[tmp].data){
				tmp = j;
			}
		}	
		if (i != tmp){
			move++;
			list[0] = list[tmp];
			list[tmp] = list[i];
			list[i] = list[0];
		}
		
	}
	printf("关键字比较次数为%d\n",compare);
	printf("关键字移动次数为%d\n",move );
	return;

}

int Partition(datatype list[],int low, int high){

	//move++;
	list[0] = list[low];
	while(low < high){
		//compare++;
		while(low < high && list[high].data >= list[0].data)
			high--;
		if(low < high){
			//move++;
			list[low] = list[high];
			low++;
		}
		//compare++;
		while(low < high && list[low].data < list[0].data)
			low++;
		if(low < high){
			//move++;
			list[high] = list[low];
			high--;
		}
		//move++;
		list[low] = list[0];
		
	}
	return low;
}
void QuickSort(datatype list[],int s,int t){
	int i;
	if (s<t)
	{
		i = Partition(list,s,t);
		QuickSort(list,s,i-1);
		QuickSort(list,i+1,t);
	}


	return;
}



















