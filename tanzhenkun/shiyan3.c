#include <stdio.h>  
# include <stdlib.h>
# include <time.h>

# define N 100
# define SR 150

int A[N],B[N],C[N],D[N],E[N],F[N],G[N];
int a,aa,b,bb,d,dd,e,ee,f,ff,num;   

long long c,cc;

void insertsort(int A[],int n);
void selecctsort(int A[],int n);
void bubblesort(int A[],int n);  
void Quicksort(int A[],int L,int R);
void GBPX(int S[],int L,int R,int T[]);

int gainint(int *p,int min,int max);
int change(int *a,int *b);

void insertsort(int A[],int n)

{  

   int i,j,temp;  

   for (i=1,a++;i<n;i++,a++)  

   if (A[i]<A[i-1])  

 {   
          temp=A[i];

          for(a++,aa++,j=i-1;j>=0&& A[j]>temp;j--,a++,aa++)

           A[j+1]=A[j];

           A[j+1]=temp;

      }  

                             }  

void selectsort(int A[],int n) 

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

          bb+=change(&A[i],&A[k]);   

       }

    }   

} 

void bubblesort(int A[],int n)  

{  

    int i,j;  

    for (i = n -1 ; i>=0 ;i--)  

   {  

      for (j = 0; j<i; j++)  

       {  

         if(A[j]>A[j+1])

             cc+=change(&A[j],&A[j+1]);

        }  

    }  

}  

void Quicksort(int A[],int L,int R)

{  

    int i=L,j=R,T=A[L];  

    if(L>R)  return;  

    while(i!=j) 

    {  

        while(A[j]>=T&&i<j){j--;d++;}  

        while(A[i]<=T&&i<j){i++;d++;}  

        if(i<j)dd+=change(&A[i],&A[j]);   

    }  

    if(L!=i)

        dd+=change(&A[L],&A[i]);       

    Quicksort(A,L,i-1);          

    Quicksort(A,i+1,R);           

}  

int gainint(int *p,int min,int max)         

{           

   do{          

        *p=min-1;      

        scanf("%d",p);          

        while(getchar()!='\n');          

        if(*p>max||*p<min)          

           printf("输入有误,请重新输入[%d--%d]:",min,max);          


    }while(*p>max||*p<min);          

    return *p;          

}  

int change(int *a,int *b) 

{  

    int c=*a;  
    *a=*b;  
    *b=c;  

    return 3;

}  

int main(){    
    int i,t,g;   srand(time(0));
    printf("请输入N [2,%d]:",N); gainint(&num,2,N);
    for(g=0;g<6;g++){
    printf("第%d次排序的结果为:\n\n",g+1);	    
    for(i=0;i<num;i++ )
    { printf("%d\t",A[i]=B[i]=C[i]=D[i]=E[i]=F[i]=rand()%SR);}
    insertsort(A,num);
    printf("\n直接插入排序:\n比较次数:%10d\t移动次数%10d\n\n",a,aa);
    selectsort(B,num);
    printf("简单选择排序:\n比较次数:%10d\t移动次数%10d\n\n",b+bb/3,bb);
    c=(num-1)*num/2;
    bubblesort(C,num); 
    printf("冒泡排序:\n比较次数:%10lld\t移动次数%10lld\n\n",c+cc/3,cc);
    Quicksort(D,0,num-1);
    printf("快速排序:\n比较次数:%10d\t移动次数%10d\n\n",d+dd/3,dd);
	getchar();} 
    return 0;  }  
