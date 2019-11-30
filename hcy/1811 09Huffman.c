#include<iostream>
using namespace std;
#pragma warning (disable:4996)
#define maxSize 100
typedef struct Node
{
	int weight;                //权值  
	int parent;                //父节点的序号，为-1的是根节点  
	int lchild, rchild;         //左右孩子节点的序号，为-1的是叶子节点  
}HTNode, *HuffmanTree;          //用来存储赫夫曼树中的所有节点  
typedef char **HuffmanCode;    //用来存储每个叶子节点的赫夫曼编码  
HuffmanTree create_HuffmanTree(int *wet, int n);
void select_minium(HuffmanTree HT, int k, int &min1, int &min2);
int min(HuffmanTree HT, int k);
void HuffmanCoding1(HuffmanTree HT, HuffmanCode &HC, int n);
void HuffmanCoding2(HuffmanTree HT, HuffmanCode &HC, int n);
int countWPL1(HuffmanTree HT, int n);
int countWPL2(HuffmanTree HT, int n);
int main()
{
	int  w[] = { 5,4,3,2,1 };//用数组w存储各个权值
	int n=5;//表示数组w中的个数
	HuffmanCode HC = NULL;
	HuffmanTree hTree = create_HuffmanTree(w, n);
	int wpl1 = countWPL1(hTree, n);
	printf("从叶子结点开始遍历二叉树求最小带权路径长度WPL=%d\n", wpl1);
	int wpl2 = countWPL2(hTree, n);
	printf("从根结点开始遍历二叉树求最小带权路径长度WPL=%d\n", wpl2);
	printf("\n从叶子到根结点编码结果为：\n");
	HuffmanCoding1(hTree, HC, n);
	printf("\n从根结点到叶子结点编码结果为：\n");
	HuffmanCoding2(hTree, HC, n);
	system("pause");
	return 0;
}
HuffmanTree create_HuffmanTree(int *wet, int n)
{
	//一棵有n个叶子节点的赫夫曼树共有2n-1个节点  
	int total = 2 * n - 1;
	HuffmanTree HT = (HuffmanTree)malloc(total * sizeof(HTNode));
	if (!HT)
	{
		printf("HuffmanTree malloc faild!");
		exit(-1);
	}
	int i;
	//HT[0],HT[1]...HT[n-1]中存放需要编码的n个叶子节点  
	for (i = 0; i < n; i++)
	{
		HT[i].parent = -1;
		HT[i].lchild = -1;
		HT[i].rchild = -1;
		HT[i].weight = *wet;
		wet++;
	}
	//HT[n],HT[n+1]...HT[2n-2]中存放的是中间构造出的每棵二叉树的根节点  
	for (; i < total; i++)
	{
		HT[i].parent = -1;
		HT[i].lchild = -1;
		HT[i].rchild = -1;
		HT[i].weight = 0;
	}
	int min1, min2; //用来保存每一轮选出的两个weight最小且parent为0的节点  
//每一轮比较后选择出min1和min2构成一课二叉树,最后构成一棵赫夫曼树  
	for (i = n; i < total; i++)
	{
		select_minium(HT, i, min1, min2);
		HT[min1].parent = i;
		HT[min2].parent = i;
		//这里左孩子和右孩子可以反过来，构成的也是一棵赫夫曼树，只是所得的编码不同  
		HT[i].lchild = min1;
		HT[i].rchild = min2;
		HT[i].weight = HT[min1].weight + HT[min2].weight;
	}
	return HT;
}
void select_minium(HuffmanTree HT, int k, int &min1, int &min2)
{
	min1 = min(HT, k);
	min2 = min(HT, k);
}
int min(HuffmanTree HT, int k)
{
	int i = 0;
	int min;        //用来存放weight最小且parent为-1的元素的序号  
	int min_weight; //用来存放weight最小且parent为-1的元素的weight值  
	while (HT[i].parent != -1)
		i++;
	min_weight = HT[i].weight;
	min = i;

	//选出weight最小且parent为-1的元素，并将其序号赋给min  
	for (; i < k; i++)
	{
		if (HT[i].weight < min_weight && HT[i].parent == -1)
		{
			min_weight = HT[i].weight;
			min = i;
		}
	}
	//选出weight最小的元素后，将其parent置1，使得下一次比较时将其排除在外。  
	HT[min].parent = 1;

	return min;
}
void HuffmanCoding1(HuffmanTree HT, HuffmanCode &HC, int n)
{
	//用来保存指向每个赫夫曼编码串的指针
	HC = (HuffmanCode)malloc(n * sizeof(char *));
	if (!HC)
	{
		printf("HuffmanCode malloc faild!");
		exit(-1);
	}
	char *code = (char *)malloc(n * sizeof(char));
	if (!code)
	{
		printf("code malloc faild!");
		exit(-1);
	}
	code[n - 1] = '\0';  //编码结束符，亦是字符数组的结束标志
						 //求每个字符的赫夫曼编码
	int i;
	for (i = 0; i < n; i++)
	{
		int current = i;           //定义当前访问的节点
		int father = HT[i].parent; //当前节点的父节点
		int start = n - 1;           //每次编码的位置，初始为编码结束符的位置
									 //从叶子节点遍历赫夫曼树直到根节点
		while (father != -1)
		{
			if (HT[father].lchild == current)   //如果是左孩子，则编码为0
				code[--start] = '0';
			else                              //如果是右孩子，则编码为1       
				code[--start] = '1';
			current = father;
			father = HT[father].parent;
		}

		//为第i个字符的编码串分配存储空间
		HC[i] = (char *)malloc((n - start) * sizeof(char));
		if (!HC[i])
		{
			printf("HC[i] malloc faild!");
			exit(-1);
		}
		
		strcpy(HC[i], code + start);
	}
	for (int i = 0; i < n; ++i) {
		printf("%s\n", HC[i]);
	}
	free(code); //释放保存编码串的临时空间
}


