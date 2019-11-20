#include"sort.h"
int main(int agrc,char **agrv){
	datatype R[20];
	int i,n=20,s=0,t=20;
	srand((int)time(NULL));
	for(i=0;i<20;i++){
	R[i].key = random_1(1,20);
	}
	D_InsertSort(R,n);display(R,20);	
	Bubble_Sort(R,n);display(R,20);	
	printf("快速排序\n");
	Quick_Sort(R,s,t);display(R,20);	
	Select_Sort(R,n);display(R,20);	}
