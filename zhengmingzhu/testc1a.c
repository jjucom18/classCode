#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Swap(int *pt1,int *pt2){
       int temp;
       temp = *pt1; *pt1 = *pt2;
       *pt2 = temp;
} 

int main(int argc, char **argv) 
{
        int a,b;
        int *pt1,*pt2;
        scanf("%d,%d\n",&a,&b);
        pt1=&a; pt2=&b;

        if(a<b)
        Swap(pt1,pt2);
        printf("%d,%d\n",*pt1,*pt2);
         
        return 0;}








