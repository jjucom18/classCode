#include "struct3.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void InsertSort(datatype R[],int n)
{ int i,j;
       	for(i = 2;i<=n;i++)
	if(R[i].key = R[i-1].key)
	   {R[0] = R[i];
	for(j = i-1;R[0].key = R[j].key;j--)
     		R[j+1] = R[j];
	R[j+1] = R[0];
	   }
}

void Bubble_Sort(datatype R[],int n)
{ int i,j;
  int swap;
  for(i=1;i<=n-1;i++)
  {swap = 0;
	  for(j =1;j<=n-1;j++)
		  if(R[j].key>R[j+1].key)
		  {R[0] = R[j+1];
	           R[j+1] = R[j];
		   R[j] = R[0];
		   swap = 1;}
       if(swap == 0)break;}
}

void Select_Sort(datatype R[],int n)
{int i,j;
int k;	
  for(i = 1;i<n;i++)
    {k=i;
  	for(j = i+1;j<=n;j++) 
	  if(R[j].key = R[k].key)
	     k = j;	     
	if(i!=k)
	{R[0] = R[k];
	R[k] = R[i];
	R[i] = R[0];}
    }
}

void HeapAdjust( datatype R[],int s, int t)
{ datatype r;
	int i,j;
  r = R[s];
  i = s;  
  for(j = i*2;j<=t;j=2*j)
      {if(j<t&&R[i].key<R[j+1].key)
	     j = j+1;
	    if(r.key>R[j].key)
		    break;
	    R[i] = R[j]; i = j;}
  R[i] = r;
}
