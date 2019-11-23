#include "text.h"

void bubble_sort(int arr[],int arr_size){
    int i,j,tmp;
    for (i=0;i<arr_size-1;i++){
        for (j=0;j<arr_size-1;j++){
            if(arr[j+1]<arr[j]){
                tmp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=tmp;
            }
        }
    }
}

void insert_sort(int *array,unsigned int n){
    int i,j;
    int temp;
    for (i=1;i<n;i++){
        temp=*(array+i);
        for(j=i;j>0 && *(array+j-1)>temp;j--){
            *(array+j)= *(array+j-1);
        }
        *(array+j)=temp;
    }
}

void select_sort(int arr[],int n){
    int i,j,k;
    for(i=1;i<n;i++){
        k=1;
        for(j=i+1;j<=n;j++)
            if(arr[j]<arr[k])
                k=j;
        if(i!=k){
            int temp;
            temp=arr[k];
            arr[k]=arr[i];
            arr[i]=temp;
        }
    }
}

void quick_sort(int left,int right){
    int i,j,t,temp;
    if(left>right)
        return;
    temp=a[left];
    i=left;
    j=right;
    while(i!=j){
        while(a[j]>=temp && i<j)
            j--;
        while(a[i]<=temp && i<j)
            i++;
        if(i<j){
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    a[left]=a[i];
    a[i]=temp;
    quick_sort(left,i-1);
    quick_sort(i+1,right);
}




