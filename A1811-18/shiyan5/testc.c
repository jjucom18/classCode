#include "tree.h"
int main(int argc,char **argv)
{
	TreeNode *t;
	t = (TreeNode *)malloc(sizeof(TreeNode));
	printf("请先按照先序输入各节点的字符，某节点的左子树或右子树为空时输入一个字符\n");
	printf("如输入ABD#G###CE##F##\n");
	CreateTree(t,'#');
	printf("先序遍历为：\n");
	PreOrder(t);
	printf("中序遍历为：\n");
	InOrder(t);
	printf("后序遍历为：\n");
	PostOrder(t);
	printf("层次遍历为：\n");
	LeveOrder(t);
	return 0;
}
