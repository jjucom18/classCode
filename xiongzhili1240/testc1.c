#include<stdio.h>
int main(int argc, char **argv)//第一题
     int var1;var2;var3;
{

scanf("%d,%d,%d",&var1,&var2,&var3);
	 printf("%d%d%d",var1,var2,var3);
void swap(	 *ptrvar1;*ptrvar2;*ptrvar3;) 
	     ptrvar1 = &var1;
		 ptrvar2 = &var2;
		 ptrvar3 = &var3;

		 var1 = *ptrvar2;
		 var2 = *ptrvar3;
		 var3 = *ptrvar1;
	printf("%p%p%p",&var1,&var2,&var3);

} 




swap(int *p1,int *p2)//第二题
{
	int *p;
	p=*p1;
	*p1=*p2;
	*p2=p;
}
main()
{
	int a,b;int *pt1,*pt2;
	scanf("%d,%d",&a,&b);
	pt1=&a:
	pt2=&b;
if(a<b) swap(pt1,pt2);
printf("%d,%d\n",*pt1,*pt2);
}
