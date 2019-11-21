#include "Insert.c"  
int main(){
   int a[N],i;
   srand(time(0));
   for(i=0;i<N;i++)
           a[i]=rand()%100;
 printf("初始数据为: ");
  for(i=0;i<N;i++)
          printf("%d\t",a[i]);
  printf("\n");
  InsertSort(a,N);
  printf("排序后数据:");
  for(i=0;i<N;i++)
          printf("%d\t",a[i]);
  }       

