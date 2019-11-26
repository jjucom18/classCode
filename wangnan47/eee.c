#include"tree.h"

int main(int argc,char **argv)
{
	TreeNode *tree;
	printf("请按先序序列遍历输入各节点的字符，某节点的左字数或右子树为空时输入一个字符#\n");
	printf("如输入ABD#G###CE##F##\n")
	CreateTree(tree, '#');
	printf("先序遍历为:\n");
	PreOrder(tree);
	printf("\n");
	printf("中序遍历为:\n");
	InOrder(tree);
	printf("\n");
	printf("后序遍历为:\n");
	PostOrder(tree);
