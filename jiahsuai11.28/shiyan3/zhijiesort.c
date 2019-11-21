#include <stdio.h>
int main()
{
	    int A[] = { 19 ,19 ,9 ,17 ,14 ,18 ,7 ,9 ,17 ,12 ,16 ,14 ,6 , 9, 3 ,8 ,5 ,17 ,13 ,16};
	        int n = sizeof(A) / sizeof(int);
		    int i, j, a;

     for (i = 1; i < n; i++)            
	   {
		  a = A[i]; 
		 j = i - 1; 
	            while (j >= 0 && A[j] > a)  
          {
		 A[j + 1] = A[j]; 
	                   j--;
				            }
		A[j + 1] = a;
				        }
	  printf(直接插入排序结果为：);
	    for (i = 0; i < n; i++)
	  {
          printf("%d ", A[i]);
			        }
	   printf("\n");
	 return 0;
}
