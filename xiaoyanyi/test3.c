#include<stdio.h>
#define LENGTH(array)((sizeof(array))/(sizeof(array[0])))
{
	int i,j,k;
	for (i=1,i<n;i++)
	{
		//为a[i]在前面的a[0...i-1]有序区间中找一个合适的位置
		for(j=i-1;j>=0;j--)
			if(a[j]<a[i])
				break;
		//如找到了一个合适的位置
		if(j !=i-1)
		{
			//将比a[i]大的数据向后移
			int temp=a[i];
			for(k=i-1;k>j;k--)
			//将a[i]放到正确位置上
			a[k+1]=temp;
		}
	}
} 
void main()
{
	int i;
	int a[]={20,40,30,10,60,50};
	int ilen=LENGTH(a);
	printf("before sort:");
	for(i=0;i<ilen;i++)
		printf("%d",a[i]) ;
	printf("\n");
	insert_sort(a,ilen);
	printf("after sort:");
	for (i=0;i<ilen;i++)
		printf("%d",a[i]);
	printf("\n");
}



void bubble_sort(int data[],int n)
{
	int sorted = 0;//false
	int i;
	while (!sorted)
	{
		sorted = 1;
		for (i=1;i<n;i++)
		{
			if (data[i-1]>data[i])
			{
				int temp = data[i];
				data[i] = data[i-1];
				data[i-1] = temp;
			}
			n--;
	}
}


packaage cn.ccnu.sort;
public class Select{
	public static void selectSort(int[] data){
		int min = -1;//用于最小值的小标
		for(int i=0;i<data.length;i++){
			min = i;//每次假设当前数为最小数，记录其下标
			for(int j=i+1;j<data.length;j++){
				min = j;
			}
		}
		if(min != i){
			swap(data,min,i);
		}
	}
}
private static viod swap(int[] data,int a,int b){
	int temp = data[a];
	data[a] = data[b];
	data[b] = temp;
}
public static void main(String[] args){
	int[] data = {10,3,12,5,4,9,5,7,6};
	selectSort(data);
	for (int i:data){
		System.out.print(i + " ");
	}
  }
}


void quickSort(vector<int>&nums,int left,int right){
	if(left>right)return;
	int low = left;
	int high = right;
	int base = nums[left];
	while(low<high){
		while(nums[high] >=base and low < high){
			high--;
		}
		nums[low]=nums[high];
		while(nums[low] <= base and low < high){
			low++;
		}
		nums[high]=nums[low];
	}
	nums[low] = base;
	quickSort(nums,left,low-1);
	quickSort(nums,high+1,right);
}
