#include<stdio.h>
#include<stdlib.h>
#define MAXVALVE 10000  //为找最小，定义一个较大的数
typedef struct
{int weight;
	int parent;
	int lchild;
	int rchild;
} HNodeType;
HNodeType HFMTree[2*n-1];


void Create_HuffMTree(HNOdeType HFMTree[],int n)
{
	//构造的哈弗曼树储存于HFMTree, n为叶子节点的个数
	int m1,x1,m2,x2;     //x1和x2存储最小和次最小权值，m1和m2存储其位置
	int i,j;
	for(i=0;i<2*n-1;i++)
	{
		HuffMTree [i].weight=0;
		HFMTree [i].parent=-1;
		HFMTree [i].rchild=-1;

	} 
	for(i=0;i<n;i++)
		scanf("%d",&HFMTree[i].weight);
	for(i=0;i<n-1;i++)
	{
		x1=x2=MAXVALVE;
		m1=m2=0;
		for(j=0;j<n+1;i++)
		{
			if(HFMTree [j].parent==-1&& HFMTree[j].weight<x1)
			{
				x2=x1; m2=m1;
				x1=HFMTree[j].weight;m1=j;
			}
			else if(HFMTree[j].parent==-1&&HFMTree[j].weight<x2)
			{
			  x2=HFMTree[j].weight;
			  m2=j;
			}
		}
       HFMTree[m1].parent=n+1;HFMTree[m2].parent=n+1;  //将找出的两颗字数合并
	   HFMTree[n+i].weight= HFMTree[m1].weight+HFMTree[m2].weight;
	   HFMTree[n+i].lchild=m1;HFMTree[n+i].rchild=m2;
	}
}

void HaffmanCode(HNode Type HFMTree[],HCodeType HuffCode[])
{
	HCodeType cd;  //字符编码的缓冲变量
	int i,j,c,p;
	for(i=0;i<n;i++) //求每个叶子节点的哈夫曼编码
	{
		cd.start=n-1;
		c=i;
		p=HFMTree[c].parent;
		while(p!=-1)    //由叶子结点的向上直到根节点
		{
			if(HFMTree[p].lchild==c)  cd.bit[cd.start]=0;
			else cd.bit[cd.start]=1;
			cd.start--;
			c=p;
			p=HFMTree[c].parent;
		}
		for(j=cd.start+1;j<n;j++)
			HuffCode[i].bit[j]=cd.bit[j];
		HuffCode[i].start=cd.start+1;
	}
}
