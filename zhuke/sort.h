#ifndef sort_h
#define sort_h
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>

#define z 12
#define N 20
int change[]={0,3,4,15,99,257,1200};

int bubch[10]={0},bubcm[10]={0};
int selch[10]={0},selcm[10]={0};
int insch[10]={0},inscm[10]={0};
int quich[10]={0},quicm[10]={0};
int shelch[10]={0},shelcm[10]={0};

void *copydata(int a[],int b[])     //复制数组函数
{
	int i;
	for(i = 0;i<N;i++)
	{
		b[i] = a[i];
	}
}

void Random(int a[],int n)
{
	int i,t,t1,t2;
	for(i = 0;i<n;i++)
	{
		t1 = rand()%20;       //随机取20以内的数
		t2 = rand()%20;
		t = a[t1];
		a[t1] = a[t2];
		a[t2] = t;
	}
}

void bubble_sort(int a[],int ck)       //求冒泡法的比较与交换次数
{
	int i,j,t;
	for(i = 0;i<N-1;j++)
	{
		if(a[j]>a[j+1])
		{t=a[j+1];
			a[j+1]=a[j];
			a[j]=t;
			bubch[ck]+=3;
		}
		bubcm[ck]++;
	}
}

void select_sort(int a[],int ck)          //求选择排序法的比较和交换次数
{
	int i,j,min,t;
	for(i = 0;i<N-1;i++)
	{
	        min = a[i];
		for(j = i+1;j<N;j++)
		{
		     if(min>a[j])
		     {t = min;
		     min = a[j];
		     a[j] = t;
		     selch[ck]+=3;
		     }
		     selcm[ck]++;
	         }
		     a[i] = min;
         }
}

void insert_sort(int r[],int ck)        //求插入法的比较和交换次数
{
         int i,j;
	 for(i = 2;i<=N;i++)
	 {
		 r[0]=r[i];
		 j=i-1;insch[ck]++;
		 while(r[0]<r[j])
		 {
			 r[j+1]=r[j];
			 j--;
			 inscm[ck]++;
			 insch[ck]++;
		 }
	 }
}

void quick_sort(int r[],int low,int high,int ck)        //求快速排序法的比较和交换次数
{
	int p;
	if(low<high)
	{
		p = partition(r,low,high,ck);
		quick_sort(r,low,p-1,ck);
		quick_sort(r,p+1,high,ck);
	}
	quicm[ck]++;
	quich[ck]++;
}

int partition(int r[],int i,int j,int ck)         //划分算法
{
	int p=r[0];
	while(i<j)
	{
		while(i<j && r[j]>=p)
		{j--;quicm[ck]++;}
		if(i<j)
		{r[i]=r[j];quich[ck]++;}
		while(i<j && r[i]<=p)
		{i++;quicm[ck]++;}
		if(i<j)
		{r[j]=r[i];quich[ck]++;}
	}
	r[i]=p;
	return i;
}

void shell_sort(int r[],int n,int d[],int ck)           //求希尔排序的比较和交换次数
{
	int i,j,k;
	int x;
	k = 0;
	while(k<z)
	{
		for(i=d[k]+1;i<n;i++)
		{
			x=r[i];
			j=i-d[k];
			shelcm[ck]++;
			while((j>0) && (x<r[j]))
			{
				r[j+d[k]]=r[j];
				j=j-d[k];
				shelcm[ck]++;
				shelch[ck]++;
			}
			r[j+d[k]]=x;
			shelch[ck]++;
		}
		k++;
	}
}

#endif
