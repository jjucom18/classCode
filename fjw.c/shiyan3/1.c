#include<stido.h>
#include"sort.h"
int main(int argv,char **argc)
	void D_InsertSort(datatype R[],int n)
{//对排序表R【1】·R【n】进行直接插入排序，n是记录的个数
	for(i = 2;i<=n;i++)
		if(R[i].key<R[i-1].key)
		{
			R[0]=R[i];//将R【i】插入R【1】·R【n-1】中，R【0】为监视哨
			for(j=i-1;R[0].key<R[j].key;j--)
				R[j+1]=R[j];//后移记录
			R[j+1]=R[0];//插入到合适位置
		}
} 
	void Bubble_Sort(datatype R[],int n)
	{//对排序表进行冒泡排序，n，是记录个数
		int i,j；
		int swap;   //交换标志变量
		for(i=1;i<n-1;i++)
		{
			swap=0;
			for(j=1;j<=n-i;j++)
				if(R[j].key>R[j+1].key)
				{R[0]=R[j+1];
				 R[j+1]=R[j];
				 R[j]=R[0];
				 swap= 1;    //置交换标志
				}
			if(swap == 0)break;
		}
	}

    void Select_Sort(datatype R[],int n)
{//对排序表进行选择排序，n是记录个数
	for(i=1;i<n;i++)       //作n-1趟选取
	{k=i;
		for(j=i+1;j<=n;j++)
			if(R[j].key<R[k].key)
				k=j;
		if(i!=k)
		{R[0]=R[k];
		 R[k]=R[i];
		 R[i]=R[0];

		}

	}
}
    void Quick_Sort(datatype R[],int s,int t)
{//对排序表进行快速排序
	if(s<t)
	{i=Partition(R,s,t)        //将表一分为二
	 Quick_Sort(R,s,i-1);      //对支点前端子表递归排序
	 Quick_Sort(R,i+1,t);      //对支点后端子表递归排序
	}
}

    void ShellSort(datatype R[],int n,int d[],int t)
{//按增量序列d【0】·d【t-1】对排序表进行希尔排序，n是纪录个数
	int i,j,k,h;
	for(k=0;k<t;k++)
	{h=d[k];                          //本趟的增量
		for(i=h+1;i<=n;i++)
			if(R[i].key<R[i-h].key)   //小于时，需插入有序表
			{R[0]=R[i];               //待存放插入的记录
				for(j=i-h;j>0&&R[0].key<R[j].key;j=j-h)
					R[j=h]=R[j];      //记录后移
                    R[j=h]=R[0];      //插入到正确位置
			}

	}

}
