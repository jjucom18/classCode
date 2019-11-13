#include<stdio.h>
#include<stdlib.h> 
 void fun();
 int main()
{
	fun();

	return 0;
} 
 void fun()
{
	int size, initialValue, increment, *ptr_arr = NULL, *p = NULL;

	printf("请输入内存大小,初始值,增量：");

	scanf("%d,%d,%d",&size, &initialValue, &increment);	

	ptr_arr = (int*)malloc(size*sizeof(int));

	if(ptr_arr == NULL)
	{
		printf("申请失败！");

		return; 
	}
		p = ptr_arr;

	for(int i = 0; i < size; i++,p++)
	{
		*p = initialValue + i * increment;

	}
		p = ptr_arr;

	for(int i = 0; i < size; i++,p++)
	{
		if(p == NULL) 
		{
			printf("失败");

			break;
		}

		printf("初始值：%d 内存地址：%X\n", *p,p);

	}
	            return 0;  
} 
