#ifndef __HUFFQUEUE_H__
#define __HUFFQUEUE_H__
#include "HuffmanTree.h"
 
//哈夫曼结点的队列 结点的数据结构
typedef struct HuffQueueNode
{
	HuffmanNode* treeNode;//哈夫曼树结点
	int weightNum;//权值
	struct HuffQueueNode* next;//指向下一个结点
}HuffQueueNode;
 
//哈夫曼结点组成的队列数据结构，由于插入数据（根据权值）和删除数据（删除队头的数据）的特性，需要结点个数 和 头指针
typedef struct HuffQueue
{
	int size;
	HuffQueueNode* first;
}HuffQueue;
 
//初始化队列
void InitHuffQueue(HuffQueue** queue);
 
//获取结点（出队操作），从队头出队
HuffQueueNode* GetHuffQueueNode(HuffQueue* queue);
 
//插入结点（入队操作），特殊插入 根据权值大小进行有序的插入结点 非结尾处插入
void AddHuffQueueNode(HuffQueue* queue, HuffmanNode* treeNode, int weightNum);
 
 
#endif
