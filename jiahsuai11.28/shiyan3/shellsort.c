#include <stdio.h>
int main()
{
  int A[] = { 19 ,19 ,9 ,17 ,14 ,18 ,7 ,9 ,17 ,12 ,16 ,14 ,6 , 9, 3 ,8 ,5 ,17 ,13 ,16 };
  int n = sizeof(A) / sizeof(int);
  int i, j, get;
  int h = 0;
  while (h <= n)
        {
        h = 3*h + 1;
	             }
  while (h >= 1) 
  {
   for (i = h; i < n; i++)
   {
       j = i - h;
       get = A[i];
      while ((j >= 0) && (A[j] > get))
            {
		    {	    A[j + h] = A[j];
	            j = j - h;
																						                }
       A[j + h] = get;
           }
  h = (h - 1) / 3;
        }
   printf("希尔排序结果为：);
       for (i = 0; i < n; i++)
    {
   printf("%d ", A[i]);
        }
  printf("\n");
       return 0;
}
