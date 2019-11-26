nclude <stdlib.h>

#include <stdio.h>

#define Maxsize 10



int main() 
	
	
	
{


	 SeqList *L;

	L = Init_SeqList() ;
				
	int i=0;
					
	printf("L的地址：%p\n",L) ;
						
	while(L->date[i] ) 								
{
	printf("L->date[%d] 的地址:%p\n",i,&L->date[i] ) ;												
	i++;												
			} 							
	Menu( L ) ;}
