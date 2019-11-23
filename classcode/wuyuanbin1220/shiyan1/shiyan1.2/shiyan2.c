#include<stdio.h>

void swap(int *p1,int *p2){ 
	int p; 
	p=*p1;		//交换地址改为交换值
	*p1=*p2;
	*p2=p;
	return;
}

int main(int argc, char **argv){
	
	int a,b; 
	int *pt1,*pt2 ;
	scanf("%d,%d",&a,&b);
	pt1=&a; 
	pt2=&b;
	if(a<b) swap(pt1,pt2);
	printf("%d,%d \n",*pt1,*pt2);
	return 0;
}
