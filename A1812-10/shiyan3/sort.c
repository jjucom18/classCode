#include"sort.h"
#define random_1(a,b) ((rand()%(b-a))+a)    
#define random_2(a,b) ((rand()%(b-a+1))+a)
typedef struct {  KeyType key; }
DataType; 
void InsertSort(DataType a[],int n)//直接插入排序
 {   printf("直接插入排序\n");
	 int i,j;  
DataType temp;   
     for(i=0;i<n-1;i++)
     {   
		 temp=a[i+1];  
         j=i; 
  while(j>-1&&temp.key<a[j].key)   
{    a[j+1]=a[j]; 
     j--; 
  }  
     a[j+1]=temp;  
   } 
}  
void BubbleSort(DataType a[],int n)//冒泡排序
{   
	printf("冒泡排序\n");
	int i,j,flag=1;
    DataType temp;
    for(i=;i<n&&flag==;i++)
     {
       flag=0;
	  for(j=0;j<n-1;j++){
		 if(a[j].key>a[j+].key) 
		 {
			 flag=;
			 temp=a[j];
			 a[j]=a[j+];
			 a[j+1]=temp; 
		 } 
	 }
  } 
}
void QuickSort(DataType a[],int low,int high)//快速排序 
{   printf("快速排序\n");  
    int i=low,j=high; 
 DataType temp=a[low]; 
 while(i<j) 
 {   while(i<j&&temp.key<=a[j].key)j--; 
  if(i<j)  
 {    
              a[i]=a[j];   
              i++;  
 }   
 while(i<j&&a[i].key<temp.key)i++;  
    if(i<j)  
     {     
            a[j]=a[i];   
            j--;   
     }  
  }  
} 
a[i]=temp; 
    if(low<i)QuickSort(a,low,i-1); 
    if(i<high)QuickSort(a,j+1,high);
 } 
void SelectSort(DataType a[],int n)//直接选择排序
 {   printf("直接选择排序\n");
	 int i,j,small;  
     DataType temp;  
     for(i=0;i<n-1;i++) 
   {   
	 small=i;  
     for(j=i+1;j<n;j++)   
     if(a[j].key<a[small].key)small=j;  
     if(small!=i)  
    {   
	 temp=a[i]; 
     a[i]=a[small]; 
     a[small]=temp; 
      }  
  } 
} 
int display(DataType a[],int n){
	int i;
	for(i=1;i<n;i++)
	{
		printf("%d",a[i+1].key);
	}
}
