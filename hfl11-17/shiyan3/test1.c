#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#define MAXSIZE 100

typedef int RedType;

typedef struct SqList

{


	RedType INT[MAXSIZE+1] ;
	
	int length;     
	
} SqList;

SqList L;


void PRINT(SqList *L)      
{


	int i;

	printf("\t\t") ;
	
	for(i=1;i<=L->length;i++) 
		
		printf("%d ",L->INT[i] ) ;
	
	printf("\n") ;
	
} 

void STINSORT(SqList *L)   //直接插入排序
{


	int i,j;

	for(i=2;i<=L->length;i++)                  
		
	{


		L->INT[0] =L->INT[i] ;                   
		
		j=i-1;
		
		while(L->INT[j] >L->INT[0] ) 
			
		{


			L->INT[j+1] =L->INT[j] ;
			
			j--;
			
		} 
		
		L->INT[j+1] =L->INT[0] ;
		
	} 
} 
void BUBBLE(SqList *L)                           //冒泡排序
	
{


	int i,j,flag=1;   

	for(i=0;i<=L->length-1&&flag==1;i++) 
		
	{


		flag=0;

		for(j=0;j<L->length-i;j++) 
			
		{


			if(L->INT[j] >L->INT[j+1] ) 
				
			{


				flag=1;

				L->INT[0] =L->INT[j] ;
				
				L->INT[j] =L->INT[j+1] ;
				
				L->INT[j+1] =L->INT[0] ;
				
			} 
			
		} 
		
	} 
	
} 
void SELECT(SqList *L)                         //选择排序
	
{


	int i,j,small;

	for(i=1;i<=L->length-1;i++) 
		
	{


		small=i;       

		for(j=i+1;j<=L->length;j++)  
			
		{


			if(L->INT[j] <L->INT[small] ) 
				
				small=j;   
			
		} 
		
		if(small!=i)  
			
		{
			L->INT[0] =L->INT[i] ;
			
			L->INT[i] =L->INT[small] ;
			
			L->INT[small] =L->INT[0] ;
			
		} 
		
	} 
	
} 
void QUICK(SqList *L,int low,int high)         //快速排序
	
{


	int i,j,temp;

	i=low;

	j=high;

	temp=L->INT[low] ;         
	
	while(i<j)                                  
		
	{


		while(i<j&&temp<=L->INT[j] )  
			
			j--;
		
		if(i<j) 
			
		{


			L->INT[i] =L->INT[j] ;
			
			i++;
			
		} 
		
		while(i<j&&L->INT[i] <=temp)  
			
			i++;
		
		if(i<j) 
			
		{


			L->INT[j] =L->INT[i] ;
			
			j--;
			
		} 
		
	} 
	
	L->INT[i] =temp;
	
	if(low<i) 
		
		QUICK(L,low,i-1) ; 
	
	if(i<high) 
		
		QUICK(L,j+1,high) ;   
	
} 
void SHELL(SqList *L)                         //希尔排序 
	
{


	int i,j,d;

	d=L->length/2;           

	while(d>=1)            
		
	{


		for(i=d+1;i<=L->length;i++) 
			
		{


			L->INT[0] =L->INT[i] ;
			
			j=i-d;
			
			while(L->INT[j] >L->INT[0] &&j>0) 
				
			{


				L->INT[j+d] =L->INT[j] ;
				
				j=j-d;
				
			} 
			
			L->INT[j+d] =L->INT[0] ;
			
		} 
		
		d=d/2;
		
	} 
	
} 
nt main(){

	int a[20];

int flag;

printf("please choose:\n");

printf("1BubbleSort:\n");

printf("2InsertSort:\n");

printf("3SelectSort:\n");

printf("4QuickSort:\n");

printf("5ShellSort:\n");

scanf("%d",&flag);

switch (flag){

case 1:

       Bubble_Sort(a,20);

case 2:

       Insert_Sort(a,20);

case 3:

       Select_Sort(a,20);

case 4:

       Quick_Sort(a,20);
case 5:
       Shell_Sort(a,20);
default:

       break;}

       for (int i=0;i<20;i++){

       printf("%d",a[i]);

       }

printf("\n");

return 0;}
