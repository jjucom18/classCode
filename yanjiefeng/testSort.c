# include <stdio.h>  
# include <stdlib.h>
# include <time.h>
# define N 50

int A[N],B[N],C[N],D[N],E[N],F[N],G[N];
int a,aa,c,cc,d,dd,e,ee,f,ff,num;   
long long b,bb;
void Insert(int A[],int n);
void Bubble(int A[],int n);
void Select(int A[],int n);  
void Quick(int A[],int L,int R);
int change(int *x,int *y);
void Insert(int A[],int n)
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
void Bubble(int A[],int n)  
{  
    int i,j;  
    for (i = n -1 ; i>=0 ;i--)  
    {  
        for (j = 0; j<i; j++)  
        {  
            if(A[j]>A[j+1])
              bb+=change(&A[j],&A[j+1]);
        }  
    }  
}
void Select(int A[],int n) 
{  
    int i,j,k;  
    for(i=0,c++;i<n-1;i++,c++)  
    {  
       k=i;  
       for(j=i+1,c++;j<n;j++,c++)  
          if(A[j]<A[k])  
              { k=j;c++;}  
       if(k!=i)    
       {
          bb+=change(&A[i],&A[k]);   
       }
    }   
}   
void Quick(int A[],int L,int R)
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
    Quick(A,L,i-1);          
    Quick(A,i+1,R);           
}  
int change(int *x,int *y) 
{  
    int z=*x;  
    *x=*y;  
    *y=z;  
    return 0;
}  
int gainint(int *p,int min,int max)         
{	scanf("%d",p);
    return *p; 
}

int main(int argc,char **argv)
{    
    int i,t,g; 
	srand((int)time(NULL));
	printf("请输入N [2,%d]:",N);
	gainint(&num,2,N);
    	for(g=0;g<6;g++){
	printf("第%d次排序：\n\n",g+1);
	for(i=0;i<num;i++)
	printf("%d\t",A[i]=B[i]=C[i]=D[i]=E[i]=F[i]=rand()%50);
	printf("\n排序算法\t比较次数\t移动次数\n");
	Insert(A,num);
	printf("直接插入\t%-10d\t%-10d\n",a,aa);
	c=(num-1)*num/2;
	Bubble(C,num); 
	printf("冒泡排序\t%-10lld\t%-10lld\n",b+bb/3,bb);
	Select(B,num);
	printf("简单选择\t%-10d\t%-10d\n",c+cc/3,cc);
	Quick(D,0,num-1);
	printf("快速排序\t%-10d\t%-10d\n",d+dd/3,dd);
		}
    return 0;  
}  
