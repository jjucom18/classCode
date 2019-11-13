#include<stdio.h>
int  swap(int*p1,int*p2)
	{int p;                                           //指针之间的相互赋值只是地址之间的相互转移，
		                                              //解引指针表示变量的值，用变量存储变量的值，再通过指针进行
													  //交换，才能使变量的值发生改变，而不仅仅只是地址的交换。
		p=*p1;
		*p1=*p2;
		*p2=p;
	}
int main (int argv,char **argc)
{
	int a,b;
	int *pt1,*pt2;
	printf("please input data");
	scanf("%d,%d",&a,&b);
	pt1=&a;pt2=&b;
	if(a<b)swap(pt1,pt2);	
	printf("%d,%d\n",*pt1,*pt2); 

	
}


