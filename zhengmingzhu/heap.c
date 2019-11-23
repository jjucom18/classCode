#include "struct3.h" 
#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#define N 20
void HeapAjust( int  R[],int s, int t)
{ int r;int i,j;
  r = R[s];
  i = s;  
  for(j = i*2;j<=t;j=2*j)
      {if(j<t&&R[i]<R[j+1])
	     j = j+1;
	    if(r>R[j])
		    break;
	    R[i] = R[j]; i = j;}
  R[i] = r;
}

