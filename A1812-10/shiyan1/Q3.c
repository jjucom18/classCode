#include<stdio.h>
#include<malloc.h>
void main(){
	int p,q,m;
	printf("%d,%p\n",p,&p);
	printf("输入第一次分配的内存\n");
	scanf("%d",&p);
	printf("%d,%p\n",p,&p);
	printf("输入第二次分配的内存\n");
	scanf("%d",&q);
 	 int *ptr_arr = (int*)malloc((p+q));
	m=*ptr_arr;
	printf("%d\n",p+q);
}
