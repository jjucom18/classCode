#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int main(int argc,char *argv)

{
	int p;
	scanf("%d",&p);
	printf("\n");

	int *ptr_arr = NULL;
	ptr_arr = (int*)malloc(sizeof(int)*p);
	printf("初始值：%d\n",p);
	printf("地址：%p\n",&p);

	if (NULL == ptr_arr)
		printf("内存申请失败1\n");

	free(ptr_arr);


	printf("输入改变值:\n");
	scanf("%d",&p);

	ptr_arr = (int*)malloc(sizeof(int)*p);
	printf("改变值：%d\n",p);
	printf("地址：%p\n",&p);

	if (NULL == ptr_arr)
		printf("内存申请失败2\n");
	free(ptr_arr);





	return 0;


}
