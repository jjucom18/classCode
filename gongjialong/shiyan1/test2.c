#include <stdio.h>

int main()

{

void swap(int *p1,int *p2);

int *pt1,*pt2,*p;

int a,b;

scanf("%d,%d",&a,&b);

pt1=&a;

pt2=&b;

if(a<b)

{ p=pt1;pt1=pt2;pt2=p;

}

swap(pt1,pt2);

printf("%d,%d\n",*pt1,*pt2);

}

void swap(int *p1,int *p2)

{

int *p;

p=p1;p1=p2;p2=p;

}
