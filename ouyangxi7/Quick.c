#include "Quick.h"
int Partition(int a[],int low,int high){
int x=a[low];
while(low<high){
 while(low<high&&a[high]>=x) high--;
if(low<high){
a[low]=a[high];
low++;
	}
while(low<high&&a[low]<=x) low++;
	if(low<high){
	a[high]=a[low];
	high--;
	}
   }
a[low]=x;
return low;
}

void QSort(int a[],int low,int high){
if(low<high){
int mid=Partition(a,low,high);
QSort(a,low,mid-1);
QSort(a,mid+1,high);
    }
}
//快速排序

void QuickSort(int a[],int n){
QSort(a,0,n-1);

}











