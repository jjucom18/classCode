#include<stdio.h>
#include<stdlib.h>

void swap(int **p1,int **p2)
{
	int *p;
//	p=p1;p1=p2;p2=p;(这里要区分p1和*p1的区别，这里改变的是指针的变量地址）//
       p = *p1;
       *p1 = *p2;
       *p2 = p;
}
int main()
{int a,b;int *pt1,*pt2;
	scanf("%d,%d",&a,&b);
	pt1=&a;pt2=&b;
	if(a<b)
		//swap(pt1,pt2);我们需要改变的是形参值//
		swap(&pt1,&pt2);

        printf("%d,%d\n",*pt1,*pt2);
		return 0;
}
