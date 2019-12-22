#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "HuffmanTree.h"
#include "HuffQueue.h"
 
//根据用户提供字符集，生成对应的哈夫曼树
HuffmanTree BuildHuffmanTree(char* inputString)
{
	//统计每个字符出现的权值
	int charWeight[MAX_SZ] = { 0 };
	for (int i = 0; i < inputString[i]!='\0'; i++)
	{
		charWeight[(unsigned char)inputString[i]]++;
	}
	HuffQueue* queue = NULL;
	InitHuffQueue(&queue);
 
	for (int i = 0; i <MAX_SZ; i++)
	{
		//对应的字符有权值，创建树结点，添加到树节点队列中
		if (charWeight[i])
		{
			HuffmanNode* treeNode = (HuffmanNode*)malloc(sizeof(HuffmanNode));
			treeNode->data = i;
			treeNode->lchild = treeNode->rchild = NULL;
			AddHuffQueueNode(queue, treeNode, charWeight[i]);
		}
	}
	//根据哈夫曼树创建原理构建哈夫曼树
	//核心就是将权值最小的2个结点，取出作为新创建树结点的孩子结点，新创建树结点的权值为它们之和，然后放回树结点队列
	//一直这样循环进行操作，直到队列中最后剩一个结点，它就是树的根结点。
	while (queue->size != 1)
	{
		HuffQueueNode* node1 = GetHuffQueueNode(queue);
		HuffQueueNode* node2 = GetHuffQueueNode(queue);
		HuffmanNode* treeNode = (HuffmanNode*)malloc(sizeof(HuffmanNode));
		treeNode->data = '\0';
		treeNode->lchild = node1->treeNode;
		treeNode->rchild = node2->treeNode;
		int weightNum = node1->weightNum + node2->weightNum;
		AddHuffQueueNode(queue, treeNode, weightNum);
	}
	return queue->first->treeNode;
}
/*
递归遍历哈夫曼树
depth 树的深度
tree 哈夫曼树
hTable 哈夫曼编码表
encode 字符对应的哈夫曼编码
*/
void traverseHuffTree(HuffmanTable* hTable,HuffmanTree tree,char* encode,int depth)
{
	
	if (NULL == tree->lchild && NULL == tree->rchild)
	{
		HuffmanTableNode* tableNode = (HuffmanTableNode*)malloc(sizeof(HuffmanTableNode));
		tableNode->data = tree->data;
		tableNode->next = NULL;
		encode[depth] = '\0';
		tableNode->encode = (char*)malloc(depth+1);
		strcpy(tableNode->encode, encode);
		if (hTable->front == NULL)
		{
			hTable->front = hTable->tail = tableNode;
		}
		else
		{
			hTable->tail->next = tableNode;
			hTable->tail = tableNode;
		}
	}
	if (NULL != tree->lchild)
	{
		encode[depth] = '0';//左分支代表0
		traverseHuffTree(hTable, tree->lchild, encode, depth+1);
	}
 
	if (NULL != tree->rchild)
	{
		encode[depth] = '1';//右分支代表1
		traverseHuffTree(hTable, tree->rchild, encode, depth+1);
	}
	return;
}
 
//根据哈夫曼树生成哈夫曼编码表
HuffmanTable * BuildHuffmanTable(HuffmanTree tree)
{
	HuffmanTable* hTable = (HuffmanTable*)malloc(sizeof(HuffmanTable));
	hTable->front = hTable->tail = NULL;
	char encode[MAX_SZ] = { 0 };
	traverseHuffTree(hTable, tree, encode, 0);
	return hTable;
}
 
//对用户提供的源字符进行哈夫曼编码
char* encode(HuffmanTable* table,char* src)
{
	char* encode = (char*)calloc(sizeof(char)*MAX_ENCODE,1);
	for (int i = 0; i < src[i]!='\0'; i++)
	{
		char ch = src[i];
		HuffmanTableNode* iterator = table->front;
		while (iterator != NULL)
		{
			if (iterator->data == ch)
			{
				strcat(encode, iterator->encode);
				break;
			}
			iterator = iterator->next;
		}
		if (iterator == NULL)
		{
			printf("哈夫曼编码表中没有字符%c对应的哈夫曼编码！\n",ch);
			return NULL;
		}
	}
	return encode;
}
 
//根据用户提供的哈夫曼编码进行解码
char* decode(HuffmanTree root,char* encode)
{
	char* decode = (char*)calloc(MAX_SZ, 1);
	HuffmanTree tree = root;
	for (int i = 0; i < encode[i]!='\0'; i++)
	{
		char ch = encode[i];
		if ('0' == ch)//0 往左走
		{
			tree = tree->lchild;
		}
		else//1 往右走
		{
			tree = tree->rchild;
		}
		//走到头，也就是找到相应的 源字符了
		if (tree->lchild == NULL && tree->rchild == NULL)
		{
			strncat(decode, &tree->data, 1);
			//找到字符后，树节点回到根结点，继续解码
			tree = root;
		}
	}
	return decode;
}
 
//打印哈夫曼编码表
void TraverseHuffmanTable(HuffmanTable* table)
{
	HuffmanTableNode* node = table->front;
	while (node != NULL)
	{
		printf("源字符:%c ->哈夫曼编码:%s\n", node->data, node->encode);
		node = node->next;
	}
}

