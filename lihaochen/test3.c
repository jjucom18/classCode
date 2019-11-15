#include<stdio.h>

void main()
{ 

       	int *ptr_arr;

        int x;
	 
       	printf("input x:\n");
    
	scanf("%d",&x);
 
       	if(x<=0) x=100;
	 ptr_arr=(int*)malloc(sizeof(int)*x);
	
	 if(!ptr_arr){
		 printf(0);
								 }
	 else{
		 printf(" success!\n");
						       }
}
