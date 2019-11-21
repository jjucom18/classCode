#include "SelectSort.h"
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
