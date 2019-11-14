#include<stdio.h>
#include<stdlib.h>
void swap(int *pt1,int *pt2)
{int p;
p=*pt1;
*pt1=*pt2;
*pt2=p;
}
void main(int argc,char **argv)
{
int a,b;
scanf("%d%d",&a,&b);
int *pt1;int *pt2;
pt1 = &a;
pt2 = &b;
if(a<b) swap(pt1,pt2);
printf("%d%d\n",*pt1,*pt2);

}
