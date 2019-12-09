#include "tree.h"

int main()
{
        TreeNote *t;
	printf(
		"请按先序序列输入各节点的字符，某节点的左子树或右子树为空时输入一个字符#。\n");
	printf("如输入ABD#G###CE##F##\n");
	createTree(t,'#');
	printf("先序遍历为：");
	preOrder(t);
	printf("\n");
	printf("中序遍历为：");
	inOrder(t);
	printf("\n");
	printf("后序遍历为：");
	postOrder(t);
	printf("\n");
	printf("层序遍历为：");
	levelOrder(t);
	printf("\n");i
}

