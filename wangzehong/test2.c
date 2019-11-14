#include<stdio.h>



swap(int *pl,int *p2){

	int x;

	x=*pt1;

	*pt1=*pt2;

	*pt2=x;

}

 main()

{

	int a,b;int *pt1,*pt2;

	scanf("%d,%d",&a,&b);

	pt1=&a;pt2=&b;

	if(a<b)swap(pt1,pt2);/如果a<b,则交换pt1和pt2的值/

	printf("%d,%d\n",*pt1,*pt2);/打印*pt1,*pt2的地址/

	return 0;

}
