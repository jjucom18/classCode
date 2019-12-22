#include"HuffmanTree.h"

int main(int argc, char *argv[])
{
	HuffmanTree tree = BuildHuffmanTree("aabbccc");
	HuffmanTable* table = BuildHuffmanTable(tree);
	TraverseHuffmanTable(table);
	char *src = "abc";
	char* dest = "10110101101";
	char* encode_str = encode(table, src);
	char* decode_str = decode(tree, dest);
	printf("原始字符串:%s ->哈夫曼编码:%s\n", src, encode_str);
	printf("哈夫曼编码:%s ->解码为:%s\n", dest, decode_str);
	return 0;
}

