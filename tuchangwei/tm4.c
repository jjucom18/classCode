
#include<stdio.h>
#include<malloc.h>
int main(int argv,char **argc)
{int var1,p;int const cvar1,var2;p=cvar1;
        int *ptrvar1=&var1;
        int const *ptrcvar1=&cvar1;
        int const *const cptrvar=&cvar1;
printf("请输入你的数据");
scanf("%d,%d",&var1,&p);
(*ptrvar1)++;
printf("利用指针实现变量的自增\n");
printf("%d\n",var1);
ptrcvar1=&var1;
var1=*ptrvar1+*ptrcvar1;
printf("利用指向常量的指针实现变量的自增加\n");
printf("%d\n",var1);
printf("%p\n",ptrcvar1);
ptrcvar1++;
printf("指针值自增\n");
printf("%p\n",ptrcvar1);
int *const cptrvar1=&var1;
(*cptrvar1)++;
    printf("使用常量指针使变量自增\n");
    printf("%d\n",var1);
        printf("指针的值不能被修改\n");
return 0;
}
