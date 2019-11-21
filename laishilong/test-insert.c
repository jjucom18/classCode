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

void D_InsertSort(datatype R[],int n)
{
  for(i=2;i<=n;i++)
    if(R[i].key<R[i-1].key)
      {R[0]=R[i];
        for(j=i-1;R[0].key<R[j].key;j--)
             R[j+1]=R[j];
        R[j+1]=R[0];
       }
    }
}  
