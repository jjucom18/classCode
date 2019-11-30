#include "HTree.h"

void Creat_HuffMTree(HNodeType HTree[],int n){   //构造哈夫曼树
	int m1,x1,m2,x2;
	int i,j;
	for (i = 0; i < 2*n - 1; ++i)
	{	HTree[i].weight = 0;
		HTree[i].parent = -1;
		HTree[i].lchild = -1;
		HTree[i].rchild = -1;
	}
	for (i = 0; i < n; ++i)
		scanf("%d",&HTree[i].weight);
	for (i = 0; i < n-1; ++i)
	{	x1 = x2 = MaxValue;
		m1 = m2 = 0;
		for (j = 0; j < n - 1; ++j)
		{	if (HTree[j].parent == -1&&HTree[j].weight < x1)
			{	x2 = x1;
				m2 = m1;
				x1 = HTree[j].weight;
				m1 = j;
			}
			else if (HTree[j].parent == -1&&HTree[j].weight < x2)
			{	x2 = HTree[j].weight;
				m2 = j;
			}
		}
	HTree[m1].parent = n + 1;
	HTree[m2].parent = n + 1;
	HTree[n + 1].weight = HTree[m1].weight + HTree[m2].weight;	
	HTree[n + 1].lchild = m1;
	HTree[n + 1].rchild = m2;
	}
}

void HaffmanCode(HNodeType HTree[],HCodeType HCode[]){   //哈夫曼编码
	HCodeType cd;
	int i,j,c,p;
	for (i = 0; i < n; ++i)
	{	cd.start = n - 1;
		c = i;
		p = HTree[c].parent;
		while(p != -1)
		{	if (HTree[p].lchild == c)
			cd.bit[cd.start] = 0;
			else cd.bit[cd.start] = 1;
			cd.start--;
			c = p;
			p = HTree[c].parent;
		}
		for( j = cd.start + 1;j < n;j ++)
		HCode[i].bit[j] = cd.bit[j];
		HCode[i].start = cd.start + 1;
	}
}