#include "haffman.h"

void main()  
{      int n, i;  
       ElemType* a;  
       struct BTreeNode* fbt;  
       printf("从键盘输入待构造的哈夫曼树中带权叶子结点数n：");  
        while(1)   {  
	       scanf("%d", &n);  
	       if (n > 1)  
		       break;  
	       else  
		       printf("重输n值：");  
	}  
	a = malloc(n*sizeof(ElemType));  
	printf("从键盘输入%d个整数作为权值：", n);  
	for (i = 0; i < n; i++)  
		scanf(" %d", &a[i]);  
	fbt = CreateHuffman(a, n);  
	printf("广义表形式的哈夫曼树：");  
	PrintBTree_int(fbt);  
	printf("\n");  
	printf("哈夫曼树的带权路径长度：");  
	printf("%d\n", WeightPathLength(fbt, 0));  
	printf("树中每个叶子结点的哈夫曼编码：\n");  
	HuffManCoding(fbt, 0);  
}  
