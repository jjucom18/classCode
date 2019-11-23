#include"paixu.h"

 int D_insertsort1(int *p,int n){int i,j;
	int a;
	 for(i=2;i<=n;i++)
if(p[i]<p[i-1]){
	a=p[i];
	for(j=i-1;a<p[j];j++)
		p[j+1]=p[j];
	p[j+1]=a;
}return *p;
}



 int Bubble_sort1(int *p,int n){
	int i,j;int a;
	int swap;
	for(i=1;i<n-i;i++){
		swap=0;for(j=1;j<=n;j++)
			if(p[j]>p[j+1]){
				a=p[j+1];
				p[j+1]=p[j];
				p[j]=a;
				swap=1;
			}
		if(swap==0)break;
	}return *p;
}



 int Select_sort1(int *p,int n){int i,j,k;
for(i=1;i<n;i++){int a;
	k=i;for(j=i+1;j<=n;j++)
		if(p[j]<p[k])
			k=j;
	if(i!=k){
		a=p[k];
		p[k]=p[i];
		p[i]=a;
	}
}return *p;
}
		


 int  Partition1(int *p,int low,int high)
{int a;
	a=p[low];
	while(low<high){
		while(low<high&&p[high]>=a)
			low++;
		if(low<high){
			p[high]=p[low];high--;
		}
	}
	p[low]=a;
	return low;
}



 int Shellsort1(int *p,int n,int *f,int t){
	int i,j,k,h;int a;
	for(k=0;k<t;k++)
	{
		h=f[k];
		for(i=h+1;i<=n;i++)
			if(p[i]<p[i-h]){
				a=p[i];
				for(j=i-h;j>0&&a<p[j];j=j-h)
					p[j+h]=p[j];
				    p[j+h]=a;
			}
	}return *p;
}




    int Quick_sort1(int *p,int s,int t){
	if(s<t){int i;
		i=Partition1(p,s,t);
			Quick_sort1(p,s,i-1);
			Quick_sort1(p,i+1,t);
	}return *p;
}



int  displayArray1(int *p,int size){
	for(int i=0;i<size;i++){
		printf("%d\t",p[i]);
	}return *p;
}
