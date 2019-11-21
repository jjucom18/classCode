#include <stdio.h> 

#include <stdlib.h>

#include <time.h>

#define N 100

#define SR 20

int A[N],B[N],C[N],D[N],E[N],F[N],G[N];

int a,a1,b,b1,d,d1,e,e1,num; //比较次数以及移动次数

long long c,c1;

void charu(int A[],int n);//直接插入排序

void xuanzepai(int A[],int n);//选择排序 

void maopao(int A[],int n); // 冒泡排序 

void Quicksort(int A[],int L,int R);//快速排序

void shell(int A[],int n);//希尔排序

int gainint(int *p,int min,int max);

int change(int *a,int *b); 

void charu(int A[],int n)//循环比较次数 

{ 

int i,j,temp; 

for (i=1,a++;i<n;i++,a++) 

if (A[i]<A[i-1]) 

{ 

temp=A[i];

for(a++,a1++,j=i-1;j>=0&& A[j]>temp;j--,a++,a1++)

	A[j+1]=A[j];

A[j+1]=temp;

} 
} 
void xuanzepai(int A[],int n)//以A[0]为比较依据 升序 

{ 

int i,j,k; 

for(i=0,b++;i<n-1;i++,b++) 

{ 

k=i; 

for(j=i+1,b++;j<n;j++,b++) 

if(A[j]<A[k]) 

{ k=j;b++;} 

if(k!=i) 

{

b1+=change(&A[i],&A[k]); 

}

} 

} 

void maopao(int A[],int n) 

{ 

int i,j; 

for (i = n -1 ; i>=0 ;i--) 

{ 

for (j = 0; j<i; j++) 

{ 

if(A[j]>A[j+1])

c1+=change(&A[j],&A[j+1]);

} 

} 

} 

void Quicksort(int A[],int L,int R)//快速排序  

{ 

int i=L,j=R,T=A[L];  

if(L>R) return; 

while(i!=j)  

{ 

while(A[j]>=T&&i<j){j--;d++;} //从右向左找

while(A[i]<=T&&i<j){i++;d++;} //从左向右找 

if(i<j)d1+=change(&A[i],&A[j]); //交换两数 

} 

if(L!=i)

d1+=change(&A[L],&A[i]);  

Quicksort(A,L,i-1); //递归    左 

Quicksort(A,i+1,R); //递归    右 

} 

void shell(int A[],int n)//希尔排序 

{
	int i,j,k;
	for(k=n>>1,e++;k>0;k=k>>1,e++)
	{
		for(i=k,e++;i<n;i++,e++)
		{
			for(j=i-k,e++;j>=0;j-=k,e++)
			 if(A[j]>A[j+k])
			 e1+=change(&A[j],&A[j+k]);
		}
	}
}   
int gainint(int *p,int min,int max)
{
do{
	*p=min-1;
scanf("%d",p);
while(getchar()!='\n');
  }
while(*p>max||*p<min);
return *p;
}

int change(int *a,int *b)//交换 

{ 

int c=*a; 

*a=*b; 

*b=c; 

return 3;

} 

int main(int argc,char **argv){ 
int i,t,g; 
srand(time(0));
printf("请输入N [2,%d]:",N);
gainint(&num,2,N);
for(g=0;g<6;g++){
printf("第%d次排序：\n\n",g+1);
for(i=0;i<num;i++){
printf("%d\t",A[i]=B[i]=C[i]=D[i]=E[i]=F[i]=rand()%SR);}
charu(A,num);
printf("\n插入排序:\n比较次数:%10d\t移动次数%10d\n\n",a,a1);
xuanzepai(B,num);
printf("选择排序:\n比较次数:%10d\t移动次数%10d\n\n",b+b1/3,b1);
c=(num-1)*num/2;
maopao(C,num); 
printf("冒泡排序:\n比较次数:%10lld\t移动次数%10lld\n\n",c+c1/3,c1);
Quicksort(D,0,num-1);
printf("快速排序:\n比较次数:%10d\t移动次数%10d\n\n",d+d1/3,d1);
shell(E,num);
printf("希尔排序:\n比较次数:%10d\t移动次数%10d\n\n",e+e1/3,e1);
printf("按任意键继续……");}
	getchar(); 
return 0;
}
