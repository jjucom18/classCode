#include "Quick.c"
int main(int argc,char **argv){
int a[N],i;
srand(time(0));
for(i=0;i<N;i++)
	a[i]=rand()%100;
  for(i=0;i<N;i++)
     printf("%d\t",a[i]);
printf("\n");
 QuickSort(a,N);
   printf("排序后数据:");
	for(i=0;i<N;i++)
		printf("%d\t",a[i]);
  }
