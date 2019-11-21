#include<iostream.h> 
#include<stdlib.h> 
#include<time.h> 
template<class T> 
void Swap(T &a,T &b) 
{ 
T temp=a; 
a=b; 
b=temp; 
} 
template<class T> 
void SelectSort(T A[],int n) //简单选择排序 
{ 
int small; 
for(int i=0;i<n-1;i++) 
{ 
small=i; 
for(int j=i+1;j<n;j++) 
if(A[j]<A[small]) 
small=j; 
Swap(A[i],A[small]); 
} 
} 
template<class T> 
void InsertSort(T A[],int n) //直接插入排序 
{ 
for(int i=1;i<n;i++) 
{ 
int j=i; 
T temp=A[j]; 
while(j>0&&temp<A[j-1]) 
{ 
A[j]=A[j-1]; 
j--; 
} 
A[j]=temp; 
} 
} 
template<class T> 
void BubbleSort(T A[],int n) //冒泡排序 
{ 
int i,j,last; 
i=n-1; 
while(i>0) 
{ 
last=0; 
for(j=0;j<i;j++) 
if(A[j+1]<A[j]) 
{ 
Swap(A[j],A[j+1]); 
last=j; 
} 
i=last; 
} 
} 
template<class T> 
void QuickSort(T A[],int n) //快速排序 
{ 
QSort(A,0,n-1); 
} 
template<class T> 
void QSort(T A[],int left,int right) 
{ 
int i,j; 
if(left<right) 
{ 
i=left; 
j=right+1; 
do 
{ 
do i++;while (A[i]<A[left]); 
do j--;while (A[j]>A[left]); 
if(i<j) 
Swap(A[i],A[j]); 
}while(i<j); 
Swap(A[left],A[j]); 
QSort(A,left,j-1); 
QSort(A,j+1,right); 
} 
} 
template<class T> 
void GQuickSort(T A[],int n) //改进的快速排序 
{ 
GQSort(A,0,n-1); 
} 
template<class T> 
void GQSort(T A[],int left,int right) 
{ 
int i,j; 
if(right>=9) 
{ 
if(left<right) 
{ 
i=left; 
j=right+1; 
do 
{ 
do i++;while (A[i]<A[left]); 
do j--;while (A[j]>A[left]); 
if(i<j) 
Swap(A[i],A[j]); 
}while(i<j); 
Swap(A[left],A[j]); 
QSort(A,left,j-1); 
QSort(A,j+1,right); 
} 
} 
else 
{ 
InsertSort(A,right-left+1); 
return ; 
} 
} 
template<class T> 
void Merge(T A[],int i1,int j1,int i2,int j2) //两路合并排序 
{ 
T* Temp=new T[j2-i1+1]; 
int i=i1,j=i2,k=0; 
while(i<=j1&&j<=j2) 
{ 
if(A[i]<=A[j]) 
Temp[k++]=A[i++]; 
else Temp[k++]=A[j++]; 
} 
while (i<=j1) 
Temp[k++]=A[i++]; 
while(j<=j2) 
Temp[k++]=A[j++]; 
for(i=0;i<k;i++) 
A[i1++]=Temp[i]; 
delete[] Temp; 
} 
template<class T> 
void MergeSort(T A[],int n) 
{ 
int i1,j1,i2,j2; 
int size=1; 
while(size<n) 
{ 
i1=0; 
while(i1+size<n) 
{ 
i2=i1+size; 
j1=i2-1; 
if(i2+size-1>n-1) 
j2=n-1; 
else 
j2=i2+size-1; 
Merge(A,i1,j1,i2,j2); 
i1=j2+1; 
} 
size*=2; 
} 
} 

int main() 
{ 
clock_t start,finish; 
srand(time(NULL)); 
int n=1000; 
int *a=new int[n]; 
int *b=new int[n]; 
int *c=new int[n]; 
int *d=new int[n]; 
int *e=new int[n]; 
int *f=new int[n]; 
cout<<"待排序序列为:"<<endl; 
for(int i=0;i<n;i++) 
{ 
a[i]=rand()%91; 
cout<<a[i]<<" "; 
b[i]=a[i]; 
c[i]=a[i]; 
d[i]=a[i]; 
e[i]=a[i]; 
f[i]=a[i]; 
} 
cout<<endl; 
start=clock(); 
SelectSort(a,n); 
cout<<"经过简单选择排序后的序列为:"<<endl; 
for(i=0;i<n;i++) 
cout<<a[i]<<" "; 
cout<<endl; 
finish=clock(); 
cout<<"开始时间为:"<<start<<" "<<"结束时间为:"<<finish<<" "<<"持续时间为:"<<(double)(finish - start)/ CLOCKS_PER_SEC<<endl; 
start=clock(); 
InsertSort(b,n); 
cout<<"经过直接插入排序后的序列为:"<<endl; 
for(i=0;i<n;i++) 
cout<<b[i]<<" "; 
cout<<endl; 
finish=clock(); 
cout<<"开始时间为:"<<start<<" "<<"结束时间为:"<<finish<<" "<<"持续时间为:"<<(double)(finish - start)/ CLOCKS_PER_SEC<<endl; 
start=clock(); 
BubbleSort(c,n); 
cout<<"经过冒泡排序后的序列为:"<<endl; 
for(i=0;i<n;i++) 
cout<<c[i]<<" "; 
cout<<endl; 
finish=clock(); 
cout<<"开始时间为:"<<start<<" "<<"结束时间为:"<<finish<<" "<<"持续时间为:"<<(double)(finish - start)/ CLOCKS_PER_SEC<<endl; 
start=clock(); 
QuickSort(d,n); 
cout<<"经过快速排序后的序列为:"<<endl; 
for(i=0;i<n;i++) 
cout<<d[i]<<" "; 
cout<<endl; 
finish=clock(); 
cout<<"开始时间为:"<<start<<" "<<"结束时间为:"<<finish<<" "<<"持续时间为:"<<(double)(finish - start)/ CLOCKS_PER_SEC<<endl; 
start=clock(); 
MergeSort(e,n); 
cout<<"经过两路合并排序后的序列为:"<<endl; 
for(i=0;i<n;i++) 
cout<<e[i]<<" "; 
cout<<endl; 
finish=clock(); 
cout<<"开始时间为:"<<start<<" "<<"结束时间为:"<<finish<<" "<<"持续时间为:"<<(double)(finish - start)/ CLOCKS_PER_SEC<<endl; 
start=clock(); 
GQuickSort(f,n); 
cout<<"经过改进后的快速排序后的序列为:"<<endl; 
for(i=0;i<n;i++) 
cout<<f[i]<<" "; 
cout<<endl; 
finish=clock(); 
cout<<"开始时间为:"<<start<<" "<<"结束时间为:"<<finish<<" "<<"持续时间为:"<<(double)(finish - start)/ CLOCKS_PER_SEC<<endl; 
return 0; 
}

