#include "struct3.h"
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define N 20
void Select_Sort(int R[],int n)
{int i,j;
int k;	
  for(i = 1;i<n;i++)
    {     k=i;
  	for(j = i+1;j<=n;j++){ 
	  if(R[j] = R[k])
	     k = j;	     
	if(i!=k)
	{R[0] = R[k];
	R[k] = R[i];
	R[i] = R[0];}
    }
}
}

