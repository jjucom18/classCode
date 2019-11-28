#include"huffman.c"

int main(int argc ,char **argv)
{
    int w[7] = {3,12,7,4,2,8,11};
    int n = 7;
    HuffmanTree htree;
    HuffmanCode htable;
    CreateHuffmanTree(&htree, w, n);
    HuffmanCoding(htree, &htable, n);
    PrintHuffmanCode(htable,w, n);
    return 0;
}
