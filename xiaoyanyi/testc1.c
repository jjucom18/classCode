 #include<stdio.h>
 int main (int argc,char**argv) 
{
 int var1=1,var2=2,var3=3,c;
 int *ptrvar1=&var1,*ptrvar2=&var2,*ptrvar3=&var3;
	 printf("var1,var2,var3:\n") ;
	 printf("%4d,%4d,%4d",var1,var2,var3) ;
	 c=*ptrvar3;
    *ptrvar3=*ptrvar2;
	*ptrvar2=*ptrvar1;
	*ptrvar1=c;                                                                         
    printf("\n") ;
	 printf("var1,var2,var3:\n") ;
	 printf("%4d,%4d,%4d",var1,var2,var3) ;
	  }
