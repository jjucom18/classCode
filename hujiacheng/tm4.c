#include<stdio.h>
#include<stdlib.h>
void vary() {

	int var1,*p,maxsize,i=0;
	printf("输入动态分配内存大小maxsize的值") ;
	scanf("%d\n",&maxsize) ;
	p = (int*) malloc(maxsize*sizeof(int) ) ;
	printf("用户输入x的值\n") ;
	scanf("%d\n",&var1) ;
	while(i<maxsize) 
	{

			p[i]  = var1++;
				printf("%d\t",p[i] ) ;
					i++;
	} 
} 
void element() {

		int var1,k,*ptr_cvar1;
		printf("请输入常量cvar1的值和var1值\n") ;
		const int cvar1 = k;
			scanf("%d\n%d\n",&k,&var1) ;
				 var1 = var1;
				 const int  *ptr_cvar = &cvar1;
				 ptr_cvar = &var1;
				 for() 
					 var1++;
				 printf("%d\n",var1) ;
								 
} 
void vary1() {

		int var1,var,*cptr_var2,*cptr_var1;
			 printf("输入常量var1") ;
				 scanf("%d\n",&var1) ;
				 cptr_var1 =&var1;
				 printf("输入常量var2") ;
				 scanf("%d\n",&var) ;
				 const int var2 = var;
				 *cptr_var2 = var2;
				 int * const p = &var1;
				 for(p;p<p+var2;cptr_var1++) 
				 {    var1++;
					 printf("%d\t",var1) ;
													} 
} 
