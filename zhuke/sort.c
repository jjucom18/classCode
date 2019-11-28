#include "sort.h"

void main(int argc,char **argv)
{
	int i,a[N],b[N],j,d[z]={12,5,3,1};
	getchar();
	printf("以下为随机产生的20个随机数：\n");
	for(i = 0;i<N;i++)
	{       a[i]=rand();
		printf("%d",a[i]);}
        bubble_sort(a,0);
	printf("\n以下对20个随机数进行排序：\n");
	for(i = 0;i<N;i++)
	{       printf("%3d",a[i]);}
	for(i = 0;i<6;i++)       //进行6次不同程度的打乱并进行排序
       {Random(a,change[i]);
	copydata(a,b);   bubch[i]=0;   bubcm[i]=0;    bubble_sort(b,i);
        copydata(a,b);   selch[i]=0;   selcm[i]=0;    select_sort(b,i);
	copydata(a,b);   insch[i]=0;   inscm[i]=0;    insert_sort(b,i);
	copydata(a,b);   quich[i]=0;   quicm[i]=0;    quick_sort(b,i);
	copydata(a,b);   shelch[i]=0;  shelcm[i]=0;   shell_sort(b,i);}
	getchar();
	for(i = 0;i<6;i++)
	printf("\n冒泡，选择，直接，快速，希尔排序的关键字参加比较次数：%d  %8d  %8d  %8d  %8d  %8d",i,bubcm[i],selcm[i],inscm[i],quicm[i],shelcm[i]);
	printf("\n冒泡，选择，直接，快速，希尔排序的关键字移动次数：%d  %8d  %8d  %8d  %8d  %8d",i,bubch[i],selch[i],insch[i],quich[i],shelch[i]);
	getchar();
}

    
