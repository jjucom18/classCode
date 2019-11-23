#include "test3-1.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define random_1(a,b) ((rand()%(b-a))+a)
#define random_1(a,b) ((rand()%(b-a+1))+a)
 int main(int argc,char **argv)
{
	srand((int)time(NULL));
void E_InsertSort(int arr1[6],int n)
	printf("this is arr1: ");
void Selec_Sort(int arr2[6],int n)
printf("this is arr2: ");
void Bubble_Sort(int arr3[6],int n)
	printf("this is arr3: ");
void Quick_Sort(int arr4[6],int i,int j)
	printf("this is arr4: ");}
	

int arr1[6];
int i,j;
for(i=0;i<10;i++)
{		arr1[i]=random_1(1,20);
	}
{for(i=2;i<=n;i++)
if(arr1[i].key<arr1[i-1].key)
{arr1[0]=arr1[i];
	for(j=i-1;arr1[0].key<arr1[j].key;j--)
		arr1[j+1]=arr1[j];
	arr1[j+1]=arr1[0];}
		printf("%d\t",arr1[i]);
	}
	return 0;
}


int arr2[6];
int i,j,k;
for(int i=0;i<10;i++){
		arr2[i]=random_1(1,20);}
{for(i=1;i<n;i++)
	{k=i;
		for(j=i+1;j<=n;j++)
			if(arr2[j].key<arr2[k].key)
				k=j;
		if(i!=k)
		{arr2[0]=arr2[k];
			arr2[k]=arr2[i];
			arr2[i]=arr2[0];}

