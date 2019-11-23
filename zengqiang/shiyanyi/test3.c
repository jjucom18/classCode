#include<stdio.h>
   void main() ;
   int *ptr_arr;
   int M;
			    
    printf("input M\n") ;
    scanf("%d",&M) ;
      if(M<=0)  M=100;
	 ptr_arr=(int *)  malloc(sizeof(int)  *M) ;
	  if(!ptr_arr) {

	 printf("NULL\n") ;
} 
       else{

	 printf("alloc ptr_arr success!\n") ;
					   
}                          
	
