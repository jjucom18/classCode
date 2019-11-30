#ifndef Huffman_h
#define Huffman_h
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int csnode;
typedef struct HuffmanTree
{
    csnode weight;
    csnode nu;       
    struct HuffmanTree* lchild;
    struct HuffmanTree* rchild;
}HuffmanNode;

HuffmanNode* createHuffmanTree(int* a, int n)
void PrintHuffmanTree(HuffmanNode* hufmTree)
void HuffmanCode(HuffmanNode* hufmTree, int depth)
void HuffmanDecode(char ch[], HuffmanNode* hufmTree, char string[])

#endif
