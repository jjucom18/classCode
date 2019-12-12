#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define LEN sizeof(struct Node)
#define MAX 1000
#define OK          1
#define ERROR       0
#define OVERFLOW   -1
#define TRUE        1
#define FALSE       0

typedef int Status;//定义一个自变量
typedef struct Node
{
	int data;
	struct Node *prior ,*next;
}Node,NodeList;//定义双向循环链表结构体

//--------------------------------------------//
//求指数函数值
int axp(int a ,int k)
{
	int r = 1;
	if(k == 0)
		return 1;
	for(;k > 0;k --)
		r = r * a;
	return r;
}

//输入转换函数
Status conversion(char str[] ,NodeList &oprh)
{//将字符串形式的操作转换成所需类型
	NodeList p;
	int i, k, buffer;
	k = buffer = 0;
	oprh = 
	oprh
	oprh
}
