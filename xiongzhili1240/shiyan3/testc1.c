//直接插入排序
void InsertSort(datatype arr[],int n)
{
	for(i=2;i<=n;i--)
		if(arr[i].key<arr[i-1].key) 
		{
			arr[0]=arr[i];
			for(j=i-1;arr[0].key<arr[j].key;j--)
				arr[j]=arr[j+1];
			arr[j+1]=arr[0];
		}
}


//冒泡排序
void bubblesort(datatpye arr[],int bgn,int end)
{
	bool isLoop = true ;
	for (int i = end; true == isLoop && i > bgn; --i)
	{
		isLoop = false;
		for (int j = bgn + 1; j < i; ++j)
		{
			if (arr[j] < arr[j-1])
		{
			mySwap(&arr[j],&arr[j-1]);
			isLoop = true;
		} 
		} 
	} 
} 


//快速排序
void QuickSort(datatype arr[], int s ,int t)
{
	if (s<t)
	{
		i=Partition(arr,s,t)
		  QuickSort(arr,s,i-1);
          QuickSort(arr,i+1,t);
	}
}

//简单选择排序
void selectSort(datatype arr[],int bgn,int end)
{
	for (int i=bgn ;i<end;++i)
	{
		int minIndex = i;
		for (int j=i+1;j<end;++j)
		{
			if(arr[j]<arr[minIndex])
				minIndex = j;
		}
		if (minIndex != i)
			mySwap(&arr[i],&arr[minIndex]);
	}
}
