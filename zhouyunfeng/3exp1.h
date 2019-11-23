#ifndef 3exp1_h
#define 3exp1_h

# include <stdio.h>  
# include <stdlib.h>
# include <time.h>
# define N 100
# define SR 1001

int A[N],B[N],C[N],D[N],E[N],F[N],G[N];
int a,aa,b,bb,d,dd,e,ee,f,ff,num;   
long long c,cc;
void xuanzepai(int A[],int n);
void maopao(int A[],int n);  
void Quicksort(int A[],int L,int R); 
void shell(int A[],int n);
int gainint(int *p,int min,int max);
int change(int *a,int *b);

#endif
