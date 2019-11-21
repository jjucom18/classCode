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
void Quick_Sort(datatype R[],int s,int t)
{
     if(s<t)
     {i=partition(R,s,t)
      Quick_Sort(R,s,i-1);
      Quick_Sort(R,i+1,t);
     }
   }
}
