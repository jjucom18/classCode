#include<stdio.h>
  void swap()


{
	   int var1, var2, var3;
	      scanf("%d %d %d",&var1,&var2,&var3);
	         printf("var1=%d,var2=%d,var3=%d\n",var1,var2,var3);
		    printf("&var1=%p,&var2=%p,&var3=%p\n", &var1,&var2,&var3);
		       int *ptrVar1 = &var1;
		          int *ptrVar2 = &var2;
			     int *ptrVar3 = &var3;

			        int  *temp;
				   temp = ptrVar2;
				      ptrVar2 = ptrVar1;
				         ptrVar1 = ptrVar3;
					    ptrVar3 = temp;
					       printf("after swap\n");
					          printf("var1=%d,var2=%d,var3=%d\n",*ptrVar1,*ptrVar2,*ptrVar3);

}
int main()

{
	        swap();
}
