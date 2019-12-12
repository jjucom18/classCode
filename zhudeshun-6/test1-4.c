#include<stdio.h>
#include<stdlib.h>
void Ptr1(int var1)
{
        int *ptr_var1;
        ptr_var1 = &var1;
        printf("输入的var1 = %d\n",var1 );
        var1++;
        printf("变量自增后的var1 = %d\n",var1 );
        (*ptr_var1)++;
        printf("指针运算的后var1 = %d\n",var1 );
        return;
}//指向变量的指针
void Ptr2(int var1,const int cvar1){
        const int *ptr_cvar1;
        ptr_cvar1 = &var1;
        printf("输入的var1 = %d,cvar1 = %d\n",var1,cvar1);
        *ptr_cvar1++;
        //printf("指针运算的后var1 = %d\n",var1 );
        //不能通过解引指向常量的指针来改变变量的值
        printf("ptr_cvar1 = %p\n",ptr_cvar1 );
        ptr_cvar1 = &cvar1;
        printf("修改后的ptr_cvar1 = %p\n",ptr_cvar1 );
        return;
        }//指向常量的指针
        void Ptr3(int var1,const int var2 ){
        int *const ptr_var1 = &var1;
        int *const ptr_var2 = &var2;
        printf("输入的var1 = %d,var2 = %d\n",var1,var2 );
        (*ptr_var1)++;
        (*ptr_var2)++;
        printf("自增操作后var1 = %d,var2 = %d\n",var1,var2);
        //ptr_var1++;
        //ptr_var2++;
        //无法改变常量指针的值
        return;
        }//指向变量的常量指针
        void Ptr4(const int cvar1){
        const int *const cptr_cvar1 = &cvar1;
        //(*cptr_cvar1)++;
        //cptr_cvar1++;
        //无法改变指向常量的常量指针的值
        //不能通过解引指向常量的指针来改变常量的值
        return;
        }
        int main(int argc, char **argv)
        { int var1;
        int cvar1,var2;
        printf("指向变量的指针\n");
        printf("请输入var1的值:\n");
        scanf("%d\n",&var1);
        Ptr1(var1);
        printf("指向常量的指针\n");
        printf("请输入var1的值:\n");
        scanf("%d",&var1);
        printf("请输入cvar1的值:\n");
        scanf("%d\n",&cvar1);
        Ptr2(var1,cvar1);
        printf("指向变量的常指针\n");
        printf("请输入var1的值:\n");
        scanf("%d",&var1);
        printf("请输入var2的值:\n");
        scanf("%d",&var2);
        Ptr3(var1,var2);
        return 0;}
