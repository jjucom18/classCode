#include"tree.h"

int main(){
	TreeNode *t;
	printf("请按先序序列输入各节点的字符，某节点的左子树或右子树为空时输入一个字符#。\n");
	printf("如输入ABD#G###CE##F##\n");
	CreateTree(t,"#");
	printf("先序遍历为:");
	PreOrder(t);
	printf("\n");
	printf("中序遍历为:");
	InOrder(t);
	printf("\n");
	printf("后序遍历为:");
	PostOrder(t);
	printf("\n");
	printf("层序遍历为:");
	LevelOrder(t);
	printf("\n");
		}

