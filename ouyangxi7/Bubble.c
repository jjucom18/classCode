#include "Bubble.h"
void BubbleSort(int a[],int n){
	int i,flag=1,t;
	for(i=1;i<n && flag==1;i++){
		flag=0;
		for(int j=0;j<n-i;j++){
	if(a[j]>a[j+1]){
	t=a[j];
	a[j]=a[j+1];
	a[j+1]=t;
	flag=1;
	}	
    }
  }

}
