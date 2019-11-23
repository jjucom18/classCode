#include <stdio.h>
void exchange(int A[], int i, int j)   
{
	    int temp = A[i];
	        A[i] = A[j];
		    A[j] = temp;
}

int partition(int A[], int left, int right) 
{
	    int pivot = A[right];              
	        int tail = left - 1;                    
		    for (int i = left; i < right; i++)      
	 {
	  if (A[i] <= pivot)          
    {
	      tail++;
        exchange(A, tail, i);
	       }
		    }
exchange(A, tail + 1, right);     
 return tail + 1;
}

void quicksort(int A[], int left, int right)
{
   int pivot_index;
       if (left < right)
   {
           pivot_index = partition(A, left, right);
            quicksort(A, left, pivot_index-1);
            quicksort(A, pivot_index+1, right);
      }

}

int main()
{
    int A[] = { 19 ,19 ,9 ,17 ,14 ,18 ,7 ,9 ,17 ,12 ,16 ,14 ,6 , 9, 3 ,8 ,5 ,17 ,13 ,16};
      int n = sizeof(A) / sizeof(int);
   quicksort(A, 0, n - 1);
       printf(快速排序结果为：);
   for (int i = 0; i < n; i++)
	    {
        printf("%d ",A[i]);
	    }
        printf("\n");
    return 0;
}
