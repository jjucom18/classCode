#include <stdio.h>
#include <stdlib.h>

void selcetsort(int a[],int n){
int i,j,max,t=0;
for(i=1;i<n;++i){
max=n-i;
for(j=0;j<n;++j){
if(a[j]>a[max]){
max=j;
}
}
if (max!=n-i){
t=a[j];
a[j]=a[max];
a[max]=t;
}
}
}
