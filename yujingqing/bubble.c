#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
#define random_1(a,b) ((rand()%(b-a))+a)
#define random_2(a,b) ((rand()%(b-a+1))+a)
void bubble(int a[],int n) {
	int i,j,t;
	for(i=1;i<n;i++){
	for(j=0;j<n-i;j++){
		if (a[j] >a[j+1]){
			t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
               }
	}
    }
} 
     int main(int argc, char **argv){
    
   { int a[N],i;
   srand(time(0));

  for (i=0; i<N;i++)
	a[i]=rand()%100;
printf("初始数据为："); 
for(i=0; i<N;i++)
     printf("\n");
    bubble(a,N);
 printf("排序后的数据：");
 for (i=0;i<N;i++)
	printf("%d",a[i]);
   }
  
   { srand((int)time(NULL));
 int arr[10];
for(int i=0;i<10;i++){
       arr[i]=random_1(1,20);
       }
for(int i=0;i<10;i++){
	printf("%d\t",arr[i]);
}
return 0;}

}
