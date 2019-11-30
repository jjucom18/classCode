//This is c program code!
/* *=+=+=+=+* *** *=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
  * 文档信息: *** :~/classCode/zhengmingzhu/test_5.c
  * 版权声明: *** :(魎魍魅魑)MIT
  * 联络信箱: *** :guochaoxxl@163.com
  * 创建时间: *** :2019年11月25日的下午06:56
  * 文档用途: *** :数据结构与算法分析-c语言描述
  * 作者信息: *** :guochaoxxl(http://cnblogs.com/guochaoxxl)
  * 修订时间: *** :2019年第47周 11月25日 星期一 下午06:56 (第329天)
  * 文件描述: *** :自行添加
 * *+=+=+=+=* *** *+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+*/
#include "test_5.h"
#include "struct5.c"
#include<stdio.h>
#include<malloc.h>

int main(int argc,char **argv)
{
TreeNode *t;
	Printf("请按先序序列输入各节点字符，某节点的左子树或右子树为空时输入一字符串#。\n");
	printf("如输入ABD#G###CE##F##\n");

	CreateTree(t,'#');

	printf("先序遍历为 ：");
	PreOrder(t);
	print("\n");

	printf("中序遍历为 ：");
	InOrder(t);
	printf("\n");

	Printf("后序遍历为 ：");
	PostOrder(t);
	printf("\n");

	Printf("层序遍历为 ：");
	LevelOrder(t);
	printf("\n");


}
