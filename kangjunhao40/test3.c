#include< stdio.h>
void main()
{
        int *ptr_arr;
        int X;
        printf("input X:\n");
        scanf("%d",&X);
        if(X<=0) X=100;
        ptr_arr=(int*)malloc(sizedf(int)*X);
        if(!ptr_arr){
                printf("alloc ptr_arr error!\n");
                exit(0);
        }
        else{
                printf("alloc ptr_arr success!\n");
        }
}
