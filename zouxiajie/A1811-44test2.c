#include<stdio.h>
void swap(int *p1,int *p2)
{int t = *p1;
    *p1 = *p2;
    *p2 = t;
}int main()
{void swap(int *p1,int *p2);
 int a,b;int *pt1,*pt2;
 scanf("%d,%d",&a,&b);
 pt1 = &a;pt2 = &b;
 if(a<b){swap(pt1,pt2);
    printf("%d,%d",*pt1,*pt2);
 }return 0;
}