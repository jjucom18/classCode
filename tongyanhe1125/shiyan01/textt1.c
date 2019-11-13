#include<stdio.h>

typedef struct _str{
    int ch1;
    int ch2;
    int ch3;
} Str;

void main(int argc,char **argv){
    int var1,var2,var3;
    int temp;
    int *ptr_var1=&var1,*ptr_var2=&var2,*ptr_var3=&var3;
    scanf("%d,%d,%d",&var1,&var2,&var3);

    Str str1;
    str1.ch1=var1;
    str1.ch2=var2;
    str1.ch3=var3;

    printf("var1=%d,var2=%d,var3=%d\n",var1,var2,var3);
    printf("str1.ch1: %d and %p\n",var1,&var1);
    printf("str1.ch2: %d and %p\n",var2,&var2);
    printf("str1.ch3: %d and %p\n",var3,&var3);

    temp=*ptr_var1;
    *ptr_var1=*ptr_var3;
    *ptr_var3=*ptr_var2;
    *ptr_var2=temp;    

    printf("var1=%d,var2=%d,var3=%d\n",var1,var2,var3);
    printf("str1.ch1: %d and %p\n",var1,&var1);
    printf("str1.ch2: %d and %p\n",var2,&var2);
    printf("str1.ch3: %d and %p\n",var3,&var3);
}
