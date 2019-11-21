#include "File.h"
void BubbleSort(int a[],int n){
        int i,flag=1,t;
        for(i=1;i<n && flag==1;i++){
                flag=0;
                for(int j=0;j<n-i;j++){
        if(a[j]>a[j+1]){
        t=a[j];
        a[j]=a[j+1];
        a[j+1]=t;
        flag=1;
        }
    }
  }
}

void InsertSort(int a[],int n){
int i,j,temp;
for(i=1;i<n;i++){
        temp=a[i];
j=i-1;
while(j>=0&&a[j]>temp)
{ a[j+1]=a[j];
        j--;

}
a[j+1]=temp;
  }
}

void SelectSort(int R[],int n){
int i,j,k,m;
 for(i=0;i<n-1;i++){
m=R[i];
k=i;
for(j=i+1;j<n;j++)
if(R[j]<m){
m=R[j];
k=j;
  }
R[k]=R[i];
R[i]=m;
        }

}
int Partition(int a[],int low,int high){
int x=a[low];
while(low<high){
 while(low<high&&a[high]>=x) high--;
if(low<high){
a[low]=a[high];
low++;
        }
while(low<high&&a[low]<=x) low++;
        if(low<high){
        a[high]=a[low];
        high--;
        }
   }
a[low]=x;
return low;
}

void QSort(int a[],int low,int high){
if(low<high){
int mid=Partition(a,low,high);
QSort(a,low,mid-1);
QSort(a,mid+1,high);
    }
}
//快速排序

void QuickSort(int a[],int n){
QSort(a,0,n-1);

void Menu(int a[],int n)
{
        int choice;
        printf("请按数字输入，选择对应的排序方式:\n");
        printf("1、插入排序\n");
        printf("2、冒泡排序\n");
        printf("3、选择排序\n");
        printf("4、快速排序\n");

        do
        {       do
                {       scanf("%d",&choice);
                        switch(choice)
                        {
                        case 1: InserSort ( int a[],int n );
                                break;                                  //插入排序
                        case 2: BubbleSort ( int a[],int n );
                                break;                                  //冒泡排序
                        case 3: SelectSort ( int a[],int n);
                                break;                                  //选择排序
                        case 4: QuickSort   ( int a[],int n );
                                break;                                  //快速排序
                        default :0;
                        printf("error:");
                                break;
                        }
                }while(choice==1||choice==2||choice==3||choice==4);

