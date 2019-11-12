#include<stdio.h>

void swap(int *p1,int *p2){
	int temp;
    temp=*p1;
	*p1=*p2;
	*p2=temp;
}
int main() {
	int a,b;
	int *pt1,*pt2;
	scanf("%d,%d",&a,&b);
	pt1=&a;
    ptr=&b;
	if(a<b)
		swap(pt1,pt2);
	printf("%d,%d\n",*pt1,*pt2);
}
