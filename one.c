#include<stdio.h>
int main(int argc,char **agrv)
{
	int var1,var2,var3,acc;
	int *p1=&var1,*p2=&var2,*p3=&var3;
	scanf("%d,%d,%d",&var1,&var2,&var3);
	printf("var1=%d,var2=%d,var3=%d\n",var1,var2,var3);
	printf("%p,%p,%p\n",&var1,&var2,&var3);
	acc=*p1;
	*p1=*p2;
	*p2=*p3;
	*p3=acc;
	pritf("var1=%d,var2=%d,var3=%d\n",var1,var2,var3);

}



