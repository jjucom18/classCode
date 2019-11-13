#include<stdio.h>
#include<stdlib.h>
void swap(int*p1,int*p2)
{int*p;
p=p1;p1=p2;p2=p;	
}
void main()
{
int a,b;int *pt1,*pt2;
scanf("%d,%d",&a,&b);
if(a<b)swap(pt1,pt2);
printf("%d,%d\n",*pt1,*pt2);
}
