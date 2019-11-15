#include<stdio.h>
void  swap(int *p1,int *p2)
{
	int temp;
	temp=*p2;
	*p2=*p1;
	*p1=temp; } 
	int main()
{
		int a,b;
		int *ptr1,*ptr2;
		scanf("%d,%d",&a,&b);
		ptr1=&a; ptr2=&b;
		if(a<b)
			swap(ptr1,ptr2);
		printf("%d,%d\n",*ptr1,*ptr2);
}
