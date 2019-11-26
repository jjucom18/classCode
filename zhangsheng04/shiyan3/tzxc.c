#ifndef sort_h
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAXSIZE 20

typedef int datetype;
void BubbleSort(SqList &L, int &bubble_c, int &bubble_s)
{
	int i,j;
	RcdType temp;
	int reg=1;
	for(i=L.length;i>1&&reg; i--){
		reg=0;
		for(j=1; j<i;j++){
			bubble_c++;
			if(L.rcd[j].key>L.rcd[j+1].key){
				bubble_s +=3;
				temp=L.rcd[j];
				L.rcd[j]=L.rcd[j+1];
				L.rcd[j+1]=temp;
				reg=1;
			}
		}
	}
}
void InsertSort(SqList &L,int &insert_c,int &insert_s){
	//直接插入排序
	int i,j; for(i=1;i<L.length;i++){
		insert_c++; //比较一次
		if(L.rcd[i+1].key<L.rcd[i].key){
			//需要将L.elem[i+1]插入有序序列
			L.rcd[0]=L.rcd[i+1];//先将L.elem[i+1]保存在空闲的0号
			insert_s++;  //关键字移动一次
			j=i+1;
			do{
				//循环将关键字后移，直到找到合适的位置进行0号元素的插入操作
				j--;
				L.rcd[j+1]=Lrcd[j];
				insert_s++;  //移动一次
				insert_c++; //在whlie中将会比较一次
			} whlie(L.rcd[0]key<L.rcd[j-1].key);
			L.rcd[j]=L.rcd[0];
			insert_s++;  //移动一次
		} 
	}
}

void ShellInsert(SqList &L,int dk, int &shell_c,int &shell_s){
	//一趟希尔排序算法
	int i,j;
	for(i=1;i<=.length-dk;i++){
		shell_c++; //比较一次
		if(L.rcd[i+dk].key<L.rcd[i].key){
			//需要将L.elem[i+1]插入有序序列
			L.rcd[0]=L.rcd[i+dk]; //先将L.elem[i+1]保存在空闲的0号单元
			shell_s++;//关键字移动一次
			j=i+dk;
			do{
				//循环将关键字后移，直到找到合适的位置进行0号元素的插入操作
				j-=dk;
				L.rcd[j+dk]=L.rcd[j];
				shell_s+=;//移动一次
				shell_c++;//whlie将会比较一次
			}whlie(j-dk>0&&L.rcd[0].key<Lrcd[j-dk].key);
			//(j-dk>0)注意数组越界问题
			L.rcd[j]=L.rcd[0];
			shell_s++;//移动一次
		}
	}
}
void ShellSort(SqList &L,int d[],int t,int &shell_c,int &shell_s){
	//希尔排序
	int k;
	for(k=0; k<t;k++){
		ShellInsert(L, d[k],shell_c,shell_s);
	}
}
int Partition(RcdTyp rcd[],int low,int high,int &quick_c,int &quick_s){
	//对子裂elem进行一次划分，并返回返回枢轴应当所处的位置
	rcd[0]=rcd[low];//将默认枢轴移至0号位置
	quick_s++;//关键字移动一次
	whlie(low<high){
	while(low<high &&rcd[high].key
			>=rcd[0].key){
		--high;
		quick_c++;//关键字进行比较一次
	}
	quick_c++;
	rcd[low]=rcd[high];
	quick_s++;//关键字移动一次
	whlie(low<high &&rcd[low].key<=rcd[0].key){
		quick_c++;//关键字进行比较一次
		++low;
	} quick_c++;
	rcd[high]=rcd[low];
	quick_s++;//关键字移动一次
}  rcd[low]=rcd[0];//当low等于high,枢轴的位置下标微low或high
quick_s++;//移动一次
return low;
}
void HeapSort(SqList &L,int &Heap_c,int &Heap_s){
	//堆排序
	Heap H;
	int i,j;
	RcdType e;
	MakeHeap(H,L.rcsd, L.length, L.size,1, greatPrior,Heap_c,Heap_s);//待排列建大顶堆
	for(i=H.n;i>0;i--) {
RemoveFirstHeap(H,e,Heap_s);//堆顶与堆尾结点交换，堆长度减一，筛选新的堆顶结点
L.rcd[i]=e;   //给原来的顺序表重新赋值好排序后的元素
	}
}
