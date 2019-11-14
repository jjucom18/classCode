#include<stdio.h>
int swap(int *p1,int *p2){
	int *p;
	p=p1;p1=p2;p2=p;
	printf("%d,%d",*p1,*p2);
}
int main(){
   int a,b;
   int *pt1,*pt2;
   scanf("%d,%d",&a,&b);
   pt1=&a;pt2=&b;
   if(a<b)
	   swap(pt1,pt2);
   else printf("%d,%d\n",*pt1,*pt2);

}
