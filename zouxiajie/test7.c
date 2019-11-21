#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10000
void init_array(int a[N],int n)
{
int i;
srand(time(NULL));
for(i=0;i<n;i++){
a[i]=rand()%N;
}
}
void sort(int a[N],int n)
{
int i,j;
int t;
for(i=0;i<n;i++){
for(j=0;j<n-1-i;j++){
if(a[j]>a[j+1]){
t=a[j];
a[j]=a[j+1];
a[j+1]=t;
}
}
}
}
void display(int a[N],int n)
{
int i;
for(i=0;i<n;i++){
printf("%d\n",a[i]);
}
}
int main()
{
int array[N];
init_array(array,N);
sort(array,N);
display(array,N);
return 0;
}

int small_array[N];
int big_array[N];
void my_list(int a[],int n)
{
int i;
srand(time(NULL));
for(i=0;i<n;i++)
a[i]=rand()%n;
}
int my_quick(int a[],int start,int end)
{
int i,eq;
int small_count=0,big_count=0;
eq=a[start];
if(start>=end) return;
for(i=start+1;i<=end;i++){
if(a[i]<eq){
small_array[small_count]=a[i];
small_count++;
}
else{
big_array[big_count]=a[i];
big_count++;
}
}
for(i=0;i<small_count;i++)
a[start+i]=small_array[i];
a[start+small_count]=eq;
for(i=0;i<big_count;i++)
a[start+i+small_count+1]=big_array[i];
my_quick(a,start,start+small_count-1);
my_quick(a,start+small_count+1,end);
}
void display(int a[],int n)
{
int i;
for(i=0;i<n;i++)
printf("%d\n",a[i]);
}
int main()
{
int array[N];
my_list(array,N);
my_quick(array,0,N-1);
display(array,N);
}

void inti_list(int array[],int n)
{
int i;
srand(time(0));
for(i=0;i<n;i++){
array[i]=rand()%100000;
}
}
void buuble(int array[],int n)
{
int i,j,k,t,min;
for(i=0;i<n;i++){
min=array[i];
for(j=i+1;j<n;j++){
if(array[j]<min){
min=array[j];
k=j;
}
}
t=array[k];
array[k]=array[i];
array[i]=t;
}
}
void display(int array[],int n)
{
int i;
for(i=0;i<n;i++){
printf("%d\n",array[i]);
}
}
int main()
{
int n=N;
int array[N];
inti_list(array,n);
buuble(array,n);
display(array,n);
return 0;
}