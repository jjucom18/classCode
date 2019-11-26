#include"BinTree.c"
#include<stdio.h>

int main()
{

	printf("请按先序输入各节点字符，某节点的左子树或右子树为空时输入一个字符#。\n");
	printf("如输入ABC#G###CE##F##\n");
	TreeNode *t = binaryTree_Create();
	printf("\n先序遍历结果：\n"); 
	pre_OrderTraverse( t );
	printf("\n中序遍历结果：\n");
	mid_OrderTraverse(t);
	printf("\n后序遍历结果：\n"); 
	post_OrderTraverse(t);
	printf("\n");
	
	
	
	return 0;
}
