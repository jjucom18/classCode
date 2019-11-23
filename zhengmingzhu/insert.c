#include "struct3.h"
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define N 20

void InsertSort(int R[],int n)
{ int i,j,temp;
     	for(i = 1;i<n;i++){
	   temp = R[i];
          j = i-1;
    while(j>=0 && R[j]>temp){
		   R[j+1] = R[j];
		   j--;}
	   R[j+1] = temp;}
	           }

//void InsertSort(int R[],int n)
//{ int i,j;
 //      	for(i = 2;i<=n;i++)
//	if(R[i] = R[i-1])
//	   {R[0] = R[i];
//	for(j = i-1;R[0] = R[j];j--)
  //   		R[j+1] = R[j];
//	R[j+1] = R[0];
//	   }
//}
