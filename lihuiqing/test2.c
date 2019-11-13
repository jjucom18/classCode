#include<stdio.h>
void swap(int *p1,int *p2)
{int p;//指针是利用地址指向存在电脑存储器的另一个地方的值，此处应该是将指针变量p1的值赋给p，所以应该将指针变量p改成变量p
	p=*p1;*p1=*p2;*p2=p;//然后应该是将指针p1，即a的地址赋值给p,指针p2赋值给p1,即将b的地址给a,最后再将a的地址给b,以此完成交换
}
int main()
{int a,b;
int *p1,*p2;
	scanf("%d,%d",&a,&b);
	p1=&a;p2=&b;//此处应该是指针p1,p2,因为pt1和pt2是没有定义的变量
	if(a<b) swap(p1,p2);
	printf("%d,%d\n",a,b);//这里应该是输出经过比较后并将大的值给a，小的值给b

}
