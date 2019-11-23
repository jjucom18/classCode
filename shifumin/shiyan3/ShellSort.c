#include"sort.h"

int main(int argc,char **argv)
{   int i,R[20];
	srand((int)time(NULL));
	for(i=0;i<20;i++){
	R[i]=random_1(1,20);
	}
	printf("原 数 组 数 据:");
	for(i=0;i<10;i++){
    printf("%d\t",R[i]);
	} printf("\n");
	ShellSort(R,10);
	printf("希尔排序后的数据:");
	{
	for(i=0;i<10;i++)
	printf("%d\t",R[i]);}
	printf("\n");
    return 0;
}

