#define sort_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define random_1(a, b) ((rand()%(b - a)) + a)
#define random_2(a, b) ((rand()%(b - a + 1)) + a)

int main(int argc, char **argv)
{
     srand((int)time(NULL));
     int arr[8];
     for(int i = 0; i < 8; i++){
          arr[i] = random_1(1, 20);
     }
void Select_Sort(datatype R[],int n)
{
     for(i=1;i<n;i++)
        {k=i;
         for(j=j+1;j<=n;j++)
             if(R[j].key<R[k].key)
                 k=j;
             if(i!=k)
               {R[0]=R[k]:
                R[k]=R[i];
                R[i]=R[0];
               }
         }
     }
}

