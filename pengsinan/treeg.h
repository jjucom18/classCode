#ifndef treeg_h
#define treeg_h

#define MaxSize 100

typedef char dataType;
typedef struct TreeNode{
	char dataType ;
	void TreeNode *left ,*right ;
} TreeNode;

void CreateTree(TreeNode *t ,dataType x);
void PreOrder(TreeNode *t);
void InOrder(TreeNode *t);
void PostOrder(TreeNode *t);
void LevelOrder(TreeNode *t);

#endif
