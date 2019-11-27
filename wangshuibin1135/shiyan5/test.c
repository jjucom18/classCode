#include"tree.c"

int main()
{
	printf("----------------------二叉树的遍历--------------------------：\n");
	bitnode* root = CreatBiNode();
	
	printf("先序遍历：\n");
	PreOrder(root); 
 	printf("\n中序遍历：\n");
 	InOrder(root);
	printf("\n后序遍历：\n");
	PostOrder(root);
	printf("\n层次顺序遍历：\n");
	LevelOrder(root);
return 0;
}
