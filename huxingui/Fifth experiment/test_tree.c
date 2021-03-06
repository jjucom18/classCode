#include"tree.h"

int main(int argc, char **argv)
{
	Tree *tree = (Tree *)malloc(sizeof(Tree));
	tree->root = NULL;
	for (char i = 'A'; i < 'W'; ++i){
		CreateTree(tree,i);
	}
	printf("先序遍历为:\n");
	PreOrder(tree->root);
	printf("\n");
	printf("中序遍历为:\n");
	InOrder(tree->root);
	printf("\n");
	printf("后序遍历为:\n");
	PostOrder(tree->root);
	printf("\n");
	printf("层次遍历为:\n");
	LevelOrder(tree->root);
	printf("\n");
	return 0;
}
