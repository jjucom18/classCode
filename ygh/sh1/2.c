#include<stdio.h>
void swap(int *p1, int *p2) 
{   int p;
	p = *p1;
	*p1 = *p2;
	*p2 = p;
} 
int main() 
{	int a, b;
	printf("请输入两个数字 a 和 b :") ;
	scanf("%d,%d", &a, &b) ;
	int *pt1, *pt2;
	pt1 = &a;
	pt2 = &b;
	if(a < b)  swap(pt1, pt2) ;
	printf("*pt1 = %d\n*pt2 = %d\n", *pt1, *pt2) ;
	return 0;
}                                                      
