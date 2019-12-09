#include <stdio.h>
#define MAXBIT 100
#define MAXVALUE 10000  //
#define MAXLEAF 30 //叶节点数目
#define MAXNODE MAXLEAF*2-1 //节点数目
//首先构造出一颗哈夫曼树的结点，包括
//权重weight，父亲parent， 左儿子lchild，右儿子rchild。
typedef struct
{
	int bit[MAXBIT];
	int start;
}HCodeType;  //编码结构体
typedef struct HNodeType
{
	int weight;
	int parent;
	int lchild;
	int rchild;
}HNodeType; //结点结构体
//开始创建一颗哈夫曼树
void Huffman(HNodeType HuffNode[MAXNODE],int n)
{
	int i,j,m1,m2,x1,x2; //i,j循环变量，m1,m2:构造哈弗曼树不同过程中两个最小权值结点的权值
	//x1,x2 构造哈弗曼树不同过程中两个最小权值结点在数组中的序号
	for(i=0;i<2*n-1;i++)//初始化哈弗曼树数组中的结点
	{
		HuffNode[i].weight = 0;
		HuffNode[i].parent = -1;
		HuffNode[i].lchild = -1;
		HuffNode[i].rchild = -1;
	}
	//输入n个叶子结点的权值
	for(i=0;i<n;i++)
	{
		printf("Plese input weight of leaf node %d:\n",i);
		scanf("%d",&HuffNode[i].weight);
	}
		//循环构造哈弗曼树
	for(i=0;i<n-1;i++)
	{
		m1=m2=MAXVALUE;//m1,m2中存放两个无父结点且结点权值最小的两个结点
		x1=x2=0;
		//找出所有结点中权值最小、无父节点的两个结点,并合并为一颗二叉树
		for(j=0;j<n+i;j++)
		{
			if(HuffNode[j].weight<m1 && HuffNode[j].parent==-1)
			{
				m2 = m1;
				x2 = x1;
				m1 = HuffNode[j].weight;
				x1 = j;
			}
			else if(HuffNode[j].weight < m2 && HuffNode[j].parent==-1)
			{
				m2 = HuffNode[j].weight;
				x2 = j;
			}
		}
		HuffNode[x1].parent = n+i;
		HuffNode[x2].parent = n+i;
		HuffNode[n+i].weight = HuffNode[x2].weight+HuffNode[x1].weight;
        HuffNode[n+i].lchild = x1;
		HuffNode[n+i].rchild = x2;
	}
}  
int main()
{
	HNodeType HuffNode[MAXNODE]; //定义一个结点结构体数组
	HCodeType HuffCode[MAXLEAF],cd;//定义一个编码结构体数组，同时定义一个临时变量来存放求解编码时的信息
	int i,j,c,n,p;
	printf("Please input n:\n");
	scanf("%d",&n);
	Huffman(HuffNode,n);
	for(i=0;i<n;i++)
	{
		cd.start = n-1;
		c = i;
		p = HuffNode[c].parent;
		while(p!=-1) //父节点存在
		{
			if(HuffNode[p].lchild==c)
			{
				cd.bit[cd.start] = 0;
			}
			else;
		{
			cd.bit[cd.start] = 1;
		}
		cd.start--;//求编码的低一位
		c=p;
		p=HuffNode[c].parent;//设置下一循环条件
		}
	for(j=cd.start+1;j<n;j++)
	{
		HuffCode[i].bit[j] = cd.bit[j];
	}
	HuffCode[i].start = cd.start;
	}
	for(i=0;i<n;i++)
	{
		printf("%d 's Huffman code is:",i);
		for(j=HuffCode[i].start+1;j<n;j++)
		{
			printf("%d",HuffCode[i].bit[j]);
		}
	printf("\n");
	}
	getchar();
	return 0;
}
