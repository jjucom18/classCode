#include "tree_h"
int main(){
	TreeNode *t;
	printf("请先按........\n");
	printf("......\n");
	CreatTree(t,'#');
	printf("先序遍历");
	PreOrder(t);
	printf("\n");
	printf("中序遍历");
	InOrder(t);
	printf("\n");
	printf("后序遍历");
	PostOrder(t);
	printf("\n");
	printf("层序遍历");
	LeveOrder(t);
	printf("\n");
}
