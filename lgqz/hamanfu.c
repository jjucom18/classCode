
#include<stdio.h>
#include<malloc.h>

#define N 6

struct HuffmanTree
{
	int weight;
	struct HuffmanTree *parent, *leftChild, *rightChild;
};

struct HuffmanTree *init(int a[N], int aLength)
{
	struct HuffmanTree *pHuffmanTree[N];
	//给所有值创建空间
	for (int i = 0; i < N; i++)
	{
		pHuffmanTree[i] = (struct HuffmanTree *)malloc(sizeof(struct HuffmanTree));
		pHuffmanTree[i]->parent = NULL;
		pHuffmanTree[i]->leftChild = NULL;
		pHuffmanTree[i]->rightChild = NULL;
		pHuffmanTree[i]->weight = a[i];
	}
	struct HuffmanTree *min1, *min2;
	for (;;)
	{
		//找到第一个值最深的地方的值并进行赋值
		struct HuffmanTree *p = pHuffmanTree[0];
		for (; p->parent != NULL;)
		{
			p = p->parent;
		}
		min1 = p;
		//找到第一小的值
		for (int i = 0; i < N; i++)
		{
			//找到最深的地方的值并进行判定
			struct HuffmanTree *t = pHuffmanTree[i];
			for (; t->parent != NULL;)
			{
				t = t->parent;
			}
			if (t->weight < min1->weight)
			{
				min1 = t;
			}
		}

		//找一个值进行赋值
		for (int i = 0; i < N; i++)
		{
			struct HuffmanTree *t = pHuffmanTree[i];
			for (; t->parent != NULL;)
			{
				t = t->parent;
			}
			if (t != min1)
			{
				min2 = t;
				break;
			}
			//如果没有找到合适的值赋值
			if (i == N - 1)
			{
				return t;
			}
		}

		//找到第二小的值
		for (int i = 0; i < N; i++)
		{
			//找到最底部的地方的值并进行判定
			struct HuffmanTree *t = pHuffmanTree[i];
			for (; t->parent != NULL;)
			{
				t = t->parent;
			}
			if (t->weight < min2->weight && t != min1)
			{
				min2 = t;
			}
		}
		struct HuffmanTree *pp = (struct HuffmanTree *)malloc(sizeof(struct HuffmanTree));
		pp->parent = NULL;
		pp->leftChild = min1;
		pp->rightChild = min2;
		pp->weight = min1->weight + min2->weight;
		min1->parent = pp;
		min2->parent = pp;
	}
	return NULL;
}

int main()
{
	int a[N] = { 3, 5, 7, 8, 11, 12 };
	
	struct HuffmanTree *huffman = init(a, N);

	getchar();
	return 0;
}
