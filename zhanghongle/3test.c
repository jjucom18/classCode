#include <stdlib.h>
int main(int argc,char **argv)

{

        int n,i;
        printf("请输入想分配的内存空间：\n");
        scanf("%d",&n);
        int *ptr_arr;
        ptr_arr = (int *)malloc(sizeof(int) * n);
        printf("内存的初始值：%d\n",n);
        printf("指针的地址：%p\n",ptr_arr);
        free(ptr_arr);
        printf("请输入想改变的内存变量：\n");
        scanf("%d",&n);
        ptr_arr = (int *)malloc(sizeof(int) * n);
        printf("内存的初始值：%d\n",n);
        printf("指针的地址：%p",ptr_arr);                                                                               
        return 0;

}
