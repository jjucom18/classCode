#include<stdio.h>
int main()
{
void swap(int *p1,int *p2)
{int p;
p=*p1,*p1=*p2,*p2=p;
}
#include<stdio.h>
void main()
{void swap(int *p1,int *p2)
int a,b;
int *pt1,*pt2;
scanf("%d,%d",&a,&b);
pt1=&a;pt2=&b;
if(a<b)swap(pt1,pt2);
printf("%d,%d\n",*pt1,*pt2）; //函数里局部变量p不能定义成指针变量，定义成int交换a,b的地址
}
