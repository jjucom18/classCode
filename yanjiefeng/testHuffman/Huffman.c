#include"Huffman.h"

// 构建哈夫曼树
HuffmanNode* createHuffmanTree(int* a, int n)
{
    int i, j;
    HuffmanNode **temp, *hufmTree;
    temp = malloc(n*sizeof(HuffmanNode));
    for (i=0; i<n; ++i)     // 将数组a中的权值赋给结点中的weight
    {
        temp[i] = (HuffmanNode*)malloc(sizeof(HuffmanNode));
        temp[i]->weight = a[i];
        temp[i]->nu = i;
        temp[i]->lchild = temp[i]->rchild = NULL;
    }
 
    for (i=0; i<n-1; ++i)       
    {
        int small1=-1, small2;      // small1、small2分别作为最小和次小权值的下标
        for (j=0; j<n; ++j)         // 先将最小的两个下标赋给small1、small2
        {
            if (temp[j] != NULL && small1==-1)
            {
                small1 = j;
                continue;
            } else if(temp[j] != NULL)
            {
                small2 = j;
                break;
            }
        }
 
        for (j=small2; j<n; ++j)    // 比较权值，移动small1和small2使之分别成为最小和次小权值的下标
        {
            if (temp[j] != NULL)
            {
                if (temp[j]->weight < temp[small1]->weight)
                {
                    small2 = small1;
                    small1 = j;
                } else if (temp[j]->weight < temp[small2]->weight)
                {
                    small2 = j;
                }
            }
        }
        hufmTree = (HuffmanNode*)malloc(sizeof(HuffmanNode));
        hufmTree->weight = temp[small1]->weight + temp[small2]->weight;
        hufmTree->lchild = temp[small1];
        hufmTree->rchild = temp[small2];
 
        temp[small1] = hufmTree;
        temp[small2] = NULL;
    }
    free(temp);
    return hufmTree;
}
 
// 打印哈夫曼树
void PrintHuffmanTree(HuffmanNode* hufmTree)
{
    if (hufmTree)
    {
        printf("%d", hufmTree->weight);
        if (hufmTree->lchild != NULL || hufmTree->rchild != NULL)
        {
            printf("(");
            PrintHuffmanTree(hufmTree->lchild);
            printf(",");
            PrintHuffmanTree(hufmTree->rchild);
            printf(")");
        }
    }
}
 
// 递归进行哈夫曼编码
void HuffmanCode(HuffmanNode* hufmTree, int depth)      // depth是哈夫曼树的深度
{
    static int code[10];
    if (hufmTree)
    {
        if (hufmTree->lchild==NULL && hufmTree->rchild==NULL)
        {
            printf("nu为%d权值为%d的叶子结点的哈夫曼编码为 ", hufmTree->nu, hufmTree->weight);
            int i;
            for (i=0; i<depth; ++i)
            {
                printf("%d", code[i]);
            }
            printf("\n");
        } else
        {
            code[depth] = 0;
            HuffmanCode(hufmTree->lchild, depth+1);
            code[depth] = 1;
            HuffmanCode(hufmTree->rchild, depth+1);
        }
    }
}
 
// 哈夫曼解码
void HuffmanDecode(char ch[], HuffmanNode* hufmTree, char string[])     // ch是要解码的01串，string是结点对应的字符
{
    int i;
    int num[100];
    HuffmanNode* tempTree = NULL;
    for (i=0; i<strlen(ch); ++i)
    {
        if (ch[i] == '0')
            num[i] = 0;
        else
            num[i] = 1;
    }
    if(hufmTree)
    {
        i = 0;      // 计数已解码01串的长度
        while(i<strlen(ch))
        {
            tempTree = hufmTree;
            while(tempTree->lchild!=NULL && tempTree->rchild!=NULL)
            {
                if (num[i] == 0)
                {
                    tempTree = tempTree->lchild;
                } else
                {
                    tempTree = tempTree->rchild;
                }
                ++i;
            }
            printf("%c", string[tempTree->nu]);     // 输出解码后对应结点的字符
        }
    }
}
 
int main()
{
    int i, n;
    printf("请输入叶子结点的个数：\n");
    while(1)
    {
        scanf("%d", &n);
        if (n>1)
            break;
        else
            printf("输入错误，请重新输入n值！");
    }
 
    int* arr;
    arr=(int*)malloc(n*sizeof(csnode));
    printf("请输入%d个叶子结点的权值：\n", n);
    for (i=0; i<n; ++i)
    {
        scanf("%d", &arr[i]);
    }
 
    char ch[100], string[100];
    printf("请连续输入这%d个叶子结点各自所代表的字符：\n", n);
    fflush(stdin);      // 强行清除缓存中的数据，也就是上面输入权值结束时的回车符
    gets(string);
 
    HuffmanNode* hufmTree = NULL;
    hufmTree = createHuffmanTree(arr, n);
 
    printf("此哈夫曼树的广义表形式为：\n");
    PrintHuffmanTree(hufmTree);
    printf("\n各叶子结点的哈夫曼编码为：\n");
    HuffmanCode(hufmTree, 0);
 
    printf("要解码吗？请输入编码:\n");
    gets(ch);
    printf("解码结果为：\n");
    HuffmanDecode(ch, hufmTree, string);
    printf("\n");
 
    free(arr);
    free(hufmTree);
 
    return 0;
}

