#include<stdio.h>
#define n 8  //叶子结点数目
#define m (2*n-1) //总结点数目，可证明
#define MAXVALUE 10000 //最大权值
#define MAXBIT 20 //哈夫曼编码最大长度
typedef struct                                     
{
    char ch;
    int weight;                                    
    int parent;                                    
    int Lchild, Rchild;
}Htreetype;
typedef struct
{
    int bit[n];  //位串
    int start;  //编码在位串中的起始位置
    char ch;       
}Hcodetype;
void select(Htreetype t[], int k, int *p1, int *p2)  //选择权值最小的结点
{
    *p1 = *p2 = 0;
    int small1, small2;
    small1 = small2 = MAXVALUE;
    int i;
    for (i = 0; i < k; i++)
    {
        if (t[i].parent == -1)
        {
            if (t[i].weight < small1)
            {
                small2 = small1;
                small1 = t[i].weight;
                *p2 = *p1;
                *p1 = i;
            }
            else if (t[i].weight < small2)
            {
                small2 = t[i].weight;
                *p2 = i;
            }
        }
    }
}
void HuffmanTree(Htreetype t[]) //构造哈夫曼树
{
    int i, j, p1, p2, f;
    p1 = p2 = 0;
    char c;
    for (i = 0; i < m; i++)  //初始化
    {
        t[i].weight = 0;
        t[i].Lchild = -1;
        t[i].parent = -1;
        t[i].Rchild = -1;
    }
    printf("共有%d个字符\n", n);
    for (i = 0; i < n; i++)  //输入字符和对应的权值
    {
        printf("请输入第%d个字符和权值','分隔", i + 1);
        scanf("%c,%d", &c,&f);
        getchar();
        t[i].ch = c;
        t[i].weight = f;
    }
    for (i = n; i < m; i++)  //构造哈夫曼树
    {
        select(t, i, &p1, &p2);
        t[p1].parent = i;
        t[p2].parent = i;
        t[i].Lchild = p1;
        t[i].Rchild = p2;
        t[i].weight = t[p1].weight + t[p2].weight;
    }
}
void HuffmanCode(Hcodetype code[],Htreetype t[]) //哈夫曼编码
{
    int i, c, p;
    Hcodetype cd;      //缓冲变量，暂时存储
    HuffmanTree(t);
    for (i = 0; i < n; i++)
    {
        cd.start = n;
        cd.ch = t[i].ch;
        c = i;               //从叶子结点向上
        p = t[i].parent;     //t[p]是t[i]的双亲
        while (p != -1)
        {
            cd.start--;
            if (t[p].Lchild == c)
                cd.bit[cd.start] = '0';        //左子树编为0
            else
                cd.bit[cd.start] = '1';        //右子树编为1
            c = p;                             //移动
            p = t[c].parent;
        }
        code[i] = cd;                         //第i+1个字符的编码存入code
    }
}
void show(Htreetype t[], Hcodetype code[])
{
    int i, j;
    for (i = 0; i<n; i++)
    {
        printf("%c: ", code[i].ch);
        for (j = code[i].start; j<n; j++)
            printf("%c ", code[i].bit[j]);
        printf("\n");
    }
}
int main()
{
    Htreetype t[m];
    Hcodetype code[n];
    HuffmanCode(code, t);
    show(t,code);
    return 0;
}

