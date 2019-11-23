#include <stdio.h>
void exchange(int A[], int i, int j)
{
	    int temp = A[i];
	        A[i] = A[j];
		    A[j] = temp;
}

int main()
{
	    int A[] = {19 ,19 ,9 ,17 ,14 ,18 ,7 ,9 ,17 ,12 ,16 ,14 ,6 , 9, 3 ,8 ,5 ,17 ,13 ,16 };
	     int n = sizeof(A) / sizeof(int);
	         int i, j, min;
		     for (i = 0; i <= n - 2; i++) 
	   {
		           min = i;    
			           for (j = i + 1; j <= n - 1; j++) 
			 {
				             if (A[j] < A[min])
			 {
				                 min = j;
						             }
					             }
				           if (min != i)
						           {
								               exchange(A, min, i); 
						  }
					       }
		         printf(选择排序结果为：);
			     for (i = 0; i < n; i++)
				         {
						         printf("%d ",A[i]);
							     }
			         printf("\n");
				     return 0;
}
