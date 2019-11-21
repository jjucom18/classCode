#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define random_1(a,b) ((rand()%(b-a))+a)
#define random_2(a,b) ((rand()%(b-a+1))+a)

int main(int arhc,char **argv){
	srand((int)time(NULL));
	int arr[20];
	for(int i=0;i<10;i++){
		arr[i]=random_1(1,20);
	}
	for(int i=0;i<20;i++){
		printf("%d\t",arr[i]);
	}
	return 0;
}


void Bubble_Sort(int *a,int n){
for (int i=0;i<n-1;i++){
for (int j=n-1;j>i;j--){
if (a[j]<a[j-1]){
int temp;
temp=a[j-1];
a[j-1]=a[j];
a[j]=temp;
    }
   }
  }
 }
void Insert_Sort(int *a,int n){
	for (int j=1;j<n;j++){
	int key=a[j];
	int i=j;
	while (i>0&&a[i-1]>key){
	a[i]=a[i-1];
	i--;
	}
	a[i]=key;}

void Select_Sort(int *a,int n){
	int temp,pos;
	for (int i=0;i<n-1;i++){
	temp=a[i];
	pos=i;
	for (int j=i+1;j<n;j++){
	if (a[j]<temp){
	temp=a[j];
	pos=j;}
	}
	a[pos]=a[i];
	a[i]=temp;
 }
}

void Quik_Sort(int *a,int low,int high){
	int pivotkey=a[low];
	int i=low,j=high;
	while(i<j){
	while(i<j&&a[j]>=pivotkey){
		--j;}
	if(i<j){
	a[i++]=a[j];}
	while(i<j&&a[i]<=pivotkey){
		++i;}
	if(i<j){
	a[j--]=a[i];
	}
	a[i]=pivotkey;
	Quick_Sort(a,low,i-1);
	Quick_Sort(a,i+1,high);
	}
}
	
int main(){
	int a[20];
int flag;
printf("please choose:\n");
printf("1BubbleSort:\n");
printf("2InsertSort:\n");
printf("3SelectSort:\n");
printf("4QuickSort:\n");
scanf("%d",&flag);
switch (flag){
case 1:
       Bubble_Sort(a,20);
case 2:
       Insert_Sort(a,20);
case 3:
       Select_Sort(a,20);
case 4:
       Quick_Sort(a,0,19);
default:
       break;}
       for (int i=0;i<20;i++){
       printf("%d",a[i]);
       }
printf("\n");
return 0;}
