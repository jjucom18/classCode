#include <stdio.h>
#include <stdlib.h>
void swap(int *pt1,int *pt2)
{
        int t;
        t = *pt1;
        *pt1 = *pt2;
        *pt2 = t;
}
int main(int argc,char **argv)
{
        int a,b;
        int *pt1,*pt2;
        scanf("%d%d",&a,&b);
        pt1 = &a,pt2 = &b;
        if (a < b)
                swap(pt1,pt2);
        printf("大小分别为：%d\t%d\n",*pt1,*pt2);
        return 0;
}
