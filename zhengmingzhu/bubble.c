#include "struct3.h"
#include<stdlib.h>
#include<stdio.h>
#include <time.h>

#define N 20
void Bubble_Sort(int R[N],int n)
{ int i,j;
  int swap;
  for(i=1;i<=n-1;i++)
  {swap = 0;
	  for(j =1;j<=n-1;j++)
		  if(R[j]>R[j+1])
		  {R[0] = R[j+1];
	           R[j+1] = R[j];
		   R[j] = R[0];
		   swap = 1;}
       if(swap == 0)break;}
}
