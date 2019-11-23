#include <stdio.h>

#include <stdlib.h>
#include <time.h>

#define N 20

#define random_1(a,b) ((rand()%(b - a)) + a)

#define random_2(a,b) ((rand()%(b - a + 1)) + a)
        void bublesort(int arr[])

{	int i,j;
	int tmp;
	for(int i = 0;i <9 ;i++)
{ 
	for(int j = 1;j < 10 ;j++)
{
																			
	if (arr[j] < arr[j - 1]	)
																								{																								tmp=arr[j];arr[j]=arr[j-1];arr[j-1]=tmp;
																														}
																							
																						
														}
}

     void insertSort(int arr[] )
{
     int i, j, tmp;

     for(i = 1; i < 10; i++)
							  {
     for(j = i; j > 0; j--)
							{ 
     if(arr[j] < arr[j-1]		     {  tmp = arr[j];     arr[j] = arr[j-1];    arr[j-1] = tmp;
																								  				                }
																						  						         else
																		 							  {   break;}
																													 																	            
																													 				 }
											  		}

						    return;
}
void selectSort(int arr[])
{
		  int i, j , minValue, tmp;
		  	        for(i = 0; i < 9; i++)
{  minValue = i;
			 for(j = i + 1; j < 10; j++)
	{ if(arr[minValue] > arr[j])
{ minValue = j;
																						  				   }
																	 }
 if(minValue != i)
{ tmp = arr[i]; arr[i] = arr[minValue];  arr[minValue] = tmp;
																							 					  }
						 }
}


	  void shellSort(int arr[])
{
	    int i, j, elem;
	        int k = 5;

		    while(k>=1)
			    	    {
	 for(i = k; i < 10; i ++)
{
		 elem = arr[i];
																								                for(j = i; j >= k; j-=k)
																							            {     																    					                    if(elem < arr[j-k])
   																																										    						                {
																																													                        arr[j] = arr[j-k];
																																																								                }
																																									    				                    else																																											    				                {
																																																 break;
																																																								 }
																																															    		                }
																											                arr[j] = elem;
																													        }
	k = k/2;
								}
}


void out_arr(int arr[])

{

		for(int i = 0;i < 10;i++){

						printf("%d\t",arr[i]);

									}

			printf("\n");

}	

      void createrandom(int arr[10])

{
			
						
      srand((int)time(NULL));
											
      for(int i = 0;i < 10;i++){
  
      arr[i] = random_1(1,20);

																													}

      for(int i = 0;i < 10;i++){

																											printf("%d\t",arr[i]);

																															}

																								printf("\n");

																												
																												

																											
																											

																								    
}
	    	
    int main(int agrc,char **argv)

{

			int arr[10];

    createrandom(arr);
    bublesort(arr);
    out_arr(arr);
    printf("bublesort\n") ; 
    insertSort(arr);
																								out_arr(arr);																								 printf("insertSort\n") ;  
																				 				selectSort(arr);																									out_arr(arr);
																								printf("selectSort\n") ;  
																							        shellSort(arr);
																								out_arr(arr);
																								printf("shellSort\n") ;


   return 0;
}

