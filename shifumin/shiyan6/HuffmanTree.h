#ifndef __HUFFMANTREE_H__
#define __HUFFMANTREE_H__
 
//创建哈夫曼树提供的字符的最大长度
#define MAX_SZ 256
//哈夫曼编码字符串最大长度
#define MAX_ENCODE 1024
//哈夫曼树结点数据结构
typedef struct HuffmanNode
{
	char data;
	struct HuffmanNode *lchild, *rchild;
}HuffmanNode,*HuffmanTree;
 
//哈夫曼编码表结点数据结构
typedef struct HuffmanTableNode
{
	char data;		//字符
	char *encode;	//字符对应的哈夫曼编码
	struct HuffmanTableNode *next;
}HuffmanTableNode;
//哈夫曼编码表数据结构
typedef struct HuffmanTable
{
	HuffmanTableNode* front;//指向队头元素
	HuffmanTableNode* tail;	//指向队尾元素
}HuffmanTable;
 
//根据用户提供原始数据，生成对应的哈夫曼树
HuffmanTree BuildHuffmanTree(char* inputString);
 
//根据哈夫曼树 生成对应的哈夫曼编码表
HuffmanTable* BuildHuffmanTable(HuffmanTree tree);
 
//对用户提供的源字符进行哈夫曼编码
char* encode(HuffmanTable* table, char* src);
 
//根据用户提供的哈夫曼编码进行解码
char* decode(HuffmanTree root, char* encode);
 
//遍历哈夫曼编码表
void TraverseHuffmanTable(HuffmanTable* table);
#endif 

