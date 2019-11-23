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
    for (int j = 0; j < n - 1; j++) 
 {
	         for (int i = 0; i < n - 1 - j; i++)
	   {
		               if (A[i] > A[i + 1]) 
	 {
		                 exchange(A, i, i + 1);        
				             }
			               }
		     }
        printf(冒泡排序结果为：);
	    for (int i = 0; i < n; i++)
		        {
				        printf("%d ", A[i]);
					    }
	        printf("\n");
		    return 0;
}
