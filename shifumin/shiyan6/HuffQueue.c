#include "HuffQueue.h"
#include <stdlib.h>
 
//初始化队列
void InitHuffQueue(HuffQueue** queue)
{
	*queue = (HuffQueue*)malloc(sizeof(HuffQueue));
	(*queue)->size = 0;
	(*queue)->first = NULL;
}
 
//获取结点（出队操作），只需要树节点的数据，故只返回树节点数据
HuffQueueNode* GetHuffQueueNode(HuffQueue* queue)
{
	if (NULL == queue || 0 == queue->size || NULL == queue->first)
	{
		return NULL;
	}
	HuffQueueNode* queueNode = queue->first;
	queue->first = queue->first->next;
	queue->size--;
	return queueNode;
 
}
 
//插入结点（入队操作），特殊插入 根据权值大小进行有序的插入结点 非队尾处插入
void AddHuffQueueNode(HuffQueue* queue, HuffmanNode* treeNode, int weightNum)
{
	HuffQueueNode *queueNode = (HuffQueueNode*)malloc(sizeof(HuffQueueNode));
	queueNode->weightNum = weightNum;
	queueNode->treeNode = treeNode;
	queueNode->next = NULL;
	//队列为空
	if (0 == queue->size)
	{
		queue->first = queueNode;
		queue->size++;
		return;
	}
	else
	{
		//比第一个结点权值都小
		if (weightNum < queue->first->weightNum)
		{
			queueNode->next = queue->first;
			queue->first = queueNode;
			queue->size++;
			return;
		}
 
		HuffQueueNode* iterator = queue->first;
		HuffQueueNode* pre = NULL;
		while (iterator != NULL && weightNum > iterator->weightNum)
		{
			pre = iterator;
			iterator = iterator->next;
		}
		//在队列中找到自己位置，将其插入其中
		if (NULL != iterator)
		{
			queueNode->next = iterator->next;
			iterator->next = queueNode;
		}
		//没找到，说明自己权值最大，插入到末尾
		else
		{
			pre->next = queueNode;
		}
		queue->size++;
		return;
	}
	return;
}
