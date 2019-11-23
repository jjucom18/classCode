简单选择.h
#include<iostream.h>
template<class T>
void SelectSort(T A[], int n)
{
    int small;
    for (int i-0; i<n-1;i++){
          small=i;
          for(int j=i+1;j<n;j++)
                 if(A[j]<A[small])small=j;
            Swap(A[i],A[small]);
          }
}

直接插入.h
#include <iostream.h>//直接插入排序
template <class T>
 void InsertSort(T A[], int n)
{
       for(int i=1; i<n; i++){
                    int j=i;
                    T temp=A[i];
                    while(j>0&&temp<A[j-1]){
                            A[j]=Al[j-1];
                            j--;
                          }
                         A[j]=temp;
  }

冒泡排序.h
#include <iostream.h>
template <class T>
void BubbleSort(T A[], int n)
{
        int i,j,last;
        i=n-1;
        while(i>0)
        {
             last=0;
             for(j=0;j<i;j++)
             {
                 if(A[j+1]<A[j])
                  {
                         Swap(A[j],A[j+1]);
                         last=j;
                  }
           i=last;
          }
}

快速排序
#include<iostream.h>
template<class T>
void quick(T A[],int n)
{
       int *a;
       int top=O,right,left,j;
       a=new int[n];
       if(a==NULL) return;
       a[top++]=0;
       a[top++]=n-1;
       for(j=0;a[j]!=NULL;j++)
       {
             left=a[j++];
             right=a[j];
             if(left>right)
                   Swap(left,right);
             if(right-left<15)
             InsertSortExt(A,left,right);
             else
             {
                     a[top++]=left;
                     a[top++]=QuickSort(A,left,right)-1; 
                     a[top++]=a[top-2]+2;
                     a[top++]=right;
             }

       }
}
template<class T>
int QuickSort(T A[],int left,int right)

{

    int i,j;  

    if(left<right)(

    i=left;

    j=right+1;

    do{

          do i++;while(A[i]<A[left]);

          do j--;while(A[j]>A[left]);

          if(i<j)Swap(A[i],A[j]);

    }while(i<j);

   Swap(A[left),A[j]);
   return j;

}

return 0;

}

template<class T>

void InsertSortExt(T A[],int left,int right) 

{ 

      for(int i=left+1; i<right; i++){

            int j=i;

            T temp=A[i]; 

            while  (j>0 && temp<A[j-1]){ 

                 A[j]=A[j-1];  j--; 

            }

             A[j]=temp; 

          }

}


合并排序.h
#include <iostream.h>
template<class T>
void Merge(T A[],int i1,int j1,int i2,int j2)
{
    T *Temp=newT[j2-i1+1];
    int i=i1,j=i2,k=0;
    while(i<=j1&&j<=j2)
                if(A[i]<=A[j])
                      Temp[k++]=A[i++];
    else                     Temp[k++]=A[j++];
           while(i<=j1)Temp[k++]=A[i++];
           while(j<=j2)Temp[k++]=A[j++];
            for(i=0;i<k;i+t)A[i1++]=Temp[il;
            delete [] Temp; 
       }
template<class T>
void MergeSort(T A[], int n) {
         int i1,j1,i2,j2;
         int size=1; 
                       while(size<n){ 
i1=0;
while(i1+size<n)[
i2=i1+size;
j1=i2-1;
if(i2+size-1>n-1)
j2=n-1;
else j2=i2+size-1;
Merge(A,i1,j1,i2,j2);
i1=j2+1;
}
size*=2;
}
}
