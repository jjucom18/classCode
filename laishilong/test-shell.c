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
void ShellSort(datatype R[],int n,int d[],int t)
{
 int i,j,k,h;
 for(k=0;k<t;k++)
    {h=d[k];
      for(i=h+1;i<=n;i++)
        if(R[i].key<R[i-h].key)
          {R[0]=R[i];
           for(j=i-h;j>0&&R[0].key<R[i].key;j=j-h)
              R[j+h]=R[i];
              R[j+h]=R[0];
           }
       }
   }
}      
