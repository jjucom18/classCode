
#include<stdio.h>
#include<malloc.h>

struct TreeNode
{
	int num;
	struct TreeNode *left, *right;
}*treeNode = { NULL };


//先序遍历输入
struct TreeNode * createTree(struct TreeNode * treeNode, int num, int stopNum)
{
	//创建空间并赋值
	treeNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	treeNode->num = num;
	//输入左右节点的数字
	int numA, numB;
	scanf_s("%d", &numA);
	//如果左节点不是停止的数字
	if (numA != stopNum)
	{
		treeNode->left = createTree(treeNode->left, numA, stopNum);
	}
	else
	{
		treeNode->left = NULL;
	}
	scanf_s("%d", &numB);
	//如果右节点不是停止的数字
	if (numB != stopNum)
	{
		treeNode->right = createTree(treeNode->right, numB, stopNum);
	}
	else
	{
		treeNode->right = NULL;
	}
	return treeNode;
}

//先序遍历
void firstTreeSearch(struct TreeNode * treeNode)
{
	//如果不为空
	if (treeNode != NULL)
	{
		printf("%d ", treeNode->num);
		firstTreeSearch(treeNode->left);
		firstTreeSearch(treeNode->right);
	}
}

//中序遍历
void middleTreeSearch(struct TreeNode * treeNode)
{
	//如果不为空
	if (treeNode != NULL)
	{
		middleTreeSearch(treeNode->left);
		printf("%d ", treeNode->num);
		middleTreeSearch(treeNode->right);
	}
}

//后序遍历
void lastTreeSearch(struct TreeNode * treeNode)
{
	//如果不为空
	if (treeNode != NULL)
	{
		lastTreeSearch(treeNode->left);
		lastTreeSearch(treeNode->right);
		printf("%d ", treeNode->num);
	}
}

//层次遍历
void levelTreeSearch(struct TreeNode * treeNode)
{
	if (treeNode == NULL)
	{
		return;
	}
	struct TreeNode * t1[100], *tt;
	int front = 0, rear = 0;
	t1[rear] = treeNode;
	rear = (rear + 1) % 100;
	for (; front != rear;)
	{
		tt = t1[front];
		front = (front + 1) % 100;
		printf("%d ", tt->num);
		if (tt->left != NULL)
		{
			t1[rear] = tt->left;
			rear = (rear + 1) % 100;
		}
		if (tt->right != NULL)
		{
			t1[rear] = tt->right;
			rear = (rear + 1) % 100;
		}
	}
}


int main()
{
	printf("请先先序输入各个节点的数，并用空格隔开，当为空时输入9999\n");
	printf("举例：132 242 534 9999 54 9999 9999 9999 432 50 9999 9999 33 9999 9999\n");
	int num;
	scanf_s("%d", &num);
	if (num == 9999)
	{
		return -1;
	}
	treeNode = createTree(treeNode, num, 9999);
	printf("先序遍历的次序：\n");
	firstTreeSearch(treeNode);
	printf("\n中序遍历的次序：\n");
	middleTreeSearch(treeNode);
	printf("\n后序遍历的次序：\n");
	lastTreeSearch(treeNode);
	printf("\n层次遍历的次序：\n");
	levelTreeSearch(treeNode);
	printf("\n所有输出结束\n");

	getchar();
	getchar();
	return 0;
}

