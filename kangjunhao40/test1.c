include<stdio.h>
void main()
{
        int var1,var2,var3,X;
        int *p1=&var1,*p2=&var2,*p3=&var3;
        scanf("%d,%d,%d",&var1,&var2,&var3);
        printf("var1=%d,var2=%d,var3=%d",&var1,&var2,&var3);
        X=*p1;
        *p1=*p2;
        *p2=*p3;
        *p3=X;
        printf("var1=%d,var2=%d,var3=%d",var1,var2,var3);
}
