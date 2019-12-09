#include<stdio.h>   
#include<string.h>   
#include<stdlib.h>   

int i,s1,s2;   
typedef struct HTNode   
{   
    int weight;    
    int parent,lchild,rchild;      
} HTNode,*HuffmanTree;                                                             //动态分配数组存储哈夫曼数   
HTNode *tree;   
typedef char * * HuffmanCode;                                               //动态分配数组存储哈夫曼编码表   

void select1(HTNode tree[],int k)    
{//在1...k选择parent为0且weight最小的两个结点，其序号分别为s1和s2且tree[s1].weight<tree[s2].weight   
    for(i=1 ; i<=k && tree[i].parent!=0 ; i++)   
        ;   
    s1=i;   
    for(i=1 ; i<=k ; i++)           
        if(tree[i].parent==0 && tree[i].weight<tree[s1].weight)    
            s1=i;   
    for(i=1 ; i<=k ; i++)   
        if(tree[i].parent==0 && i!=s1)   
            break;    
    s2=i;   
    for(i=1 ; i<=k ; i++)   
        if(tree[i].parent==0 && i!=s1 && tree[i].weight<tree[s2].weight)    
            s2=i;   
}   

void Huffman(int *w,int n)    
{ //构造哈夫曼树   
    int m;   
    FILE *fp;   
    m=2*n-1;   
    if(n<1) return;   
    tree=(HuffmanTree)malloc((m+1)*sizeof(HTNode));                             //0号单元未用   
    if((fp=fopen("huffman.txt","w"))==NULL)                                     //该文件用于存储哈夫曼树   
    {   
        printf("cannot open this file\n");   
        exit(0);   
    }   
    for(i=1 ; i<=n ; i++)   
    {   
        tree[i].weight=w[i];   
        tree[i].parent=0;   
        tree[i].lchild=0;   
        tree[i].rchild=0;   
    }   
    for(i=n+1;i<=m;i++)   
    {   
        tree[i].weight=0;   
        tree[i].parent=0;   
        tree[i].lchild=0;   
        tree[i].rchild=0;   
    }   
    for(i=n+1;i<=m;i++)   
    {   
        select1(tree, i-1);   
        tree[s1].parent=i;   
        tree[s2].parent=i;   
        tree[i].lchild=s1;    
        tree[i].rchild=s2;      
        tree[i].weight=tree[s1].weight+tree[s2].weight;   
    }   
    for(i=1;i<=n;i++)   
        if(fwrite(&tree[i],sizeof(struct HTNode),1,fp)!=1)   
        {   
            printf("file write error!\n");   
            return;   
        }   
    fclose(fp);   
}   

void encode(char * cha,int n)   
{//求哈夫曼编码   
    int c,f,start;   
    char t,*code,**hc;   
    FILE *fp;   
    if((fp=fopen("huffman.txt","r"))==NULL)   
    {   
        printf("cannot open this file\n");   
        exit(0);   
    }   
    for(i=1;i<=n;i++)   
        fread(&tree[i],sizeof(struct HTNode),n,fp);   
    fclose(fp);   
    hc=(HuffmanCode)malloc((n+1)*sizeof(char * ));                  //分配n个字符编码的头指针向量   
    code=(char *  )malloc(n*sizeof(char));                          //分配求编码的工作空间   
    code[n-1]='\0';                                                 //编码结束符   
    printf("Huffman编码:\n");   
    for(i=1;i<=n;i++)   
    {   
        start=n-1;   
        for(c=i,f=tree[i].parent;f!=0;c=f,f=tree[f].parent)         //从叶子到根逆向求编码   
            if(tree[f].lchild==c)         
                code[--start]='0';      
            else              
                code[--start]='1';   
        hc[i]=(char *)malloc((n-start)*sizeof(char));               //为第i个字符编码分配空间   
        strcpy(hc[i],&code[start]);                                 //从code复制编码串到hc   
        printf("%c--->%s\n",cha[i],hc[i]);   
    }   
    free(code);   
    printf("请输入您要编码的字符串：\n");   
    scanf("%c",&t);   
    printf("编码的结果为：\n");   
    while(t!='\n')   
    {     
        for(i=1;i<=n;i++)   
        {   
            if(t==cha[i])   
            printf("%s",hc[i]);   
        }   
        scanf("%c",&t);   
    }   
    fclose(fp);   
    printf("\n");   
}   

void menu();   
void decode(int n)   
{//译码函数   
    int j,m;   
    char *cha,t;   
    FILE *fp;   
    if((fp=fopen("huffman.txt","r"))==NULL)   
    {   
        printf("cannot open this file\n");   
        exit(0);   
    }   
    for(i=1;i<=n;i++)   
        fread(&tree[i],sizeof(struct HTNode),1,fp);   
    fclose(fp);   
    if((fp=fopen("cha.txt","r"))==NULL)   
    {   
        printf("cannot open this file\n");   
        exit(0);   
    }   
    cha=(char *)malloc((n+1)*sizeof(char));   
    for(i=1;i<=n;i++)   
        fread(&cha[i],sizeof(char),1,fp);   
    fclose(fp);   
    if((fp=fopen("result.txt","w"))==NULL)                          //该文件用于存储译码结果   
    {   
        printf("cannot open this file\n");   
        exit(0);   
    }   
    m=2*n-1;   
    i=m;   
    getchar();   
    printf("请输入你要译码的编码:\n");   
    scanf("%c",&t);   
    printf("译码结果为:\n");   
    while(t!='\n')      
    {   
        if(t=='0')   
            i=tree[i].lchild;   
        else  
            i=tree[i].rchild;   
        if(tree[i].lchild==0)   
        {   
            printf("%c",cha[i]);   
            fwrite(&cha[i],sizeof(char),1,fp);   
            j=i;   
            i=m;   
        }   
        scanf("%c",&t);   
    }   
    fclose(fp);   
    printf("\n");   
    menu();   
}   

void huff(int n)   
{//编码初始化   
    char *cha;   
    int *w;   
    FILE *fp;   
    if((fp=fopen("cha.txt","w"))==NULL)                             //该文件用于存储字符   
    {   
        printf("cannot open this file\n");   
        exit(0);   
    }   
    cha=(char *)malloc((n+1)*sizeof(char));   
    w=(int *)malloc((n+1)*sizeof(int));   
    printf("请输入字符(中间不加空格):\n");                                        
    getchar();   
    for(i=1;i<=n;i++)   
        scanf("%c",&cha[i]);   
    printf("请输入字符的权值:\n");   
    for(i=1 ; i<=n ; i++)   
        scanf("%d",&w[i]);   
    getchar();   
    for(i=1;i<=n;i++)   
        fwrite(&cha[i],sizeof(char),1,fp);   
    fclose(fp);   
    Huffman(w,n);   
    encode(cha,n);   
    menu();   
}   

void menu()   
{//主菜单   
    int n,num;   
    FILE *fp;   
    printf("****************哈夫曼编码译码****************\n");   
    printf("*** -->> 1. 编    码                       ***\n");   
    printf("************                               ***\n");   
    printf("*** -->> 2. 译    码                       ***\n");   
    printf("************                               ***\n");   
    printf("*** -->> 0. 退    出                       ***\n");    
    printf("请输入操作类型：\n");   
    scanf("%d",&num);   
    switch(num)   
    {   
        case 0:   
            printf("谢谢您的使用！\n");   
            break;   
        case 1:    
            if((fp=fopen("n.txt","w"))==NULL)                       //该文件用于存储字符个数   
            {   
                printf("cannot open this file\n");   
                exit(0);   
            }   
            printf("请输入字符个数:\n");   
            scanf("%d",&n);   
            fwrite(&n,sizeof(int),1,fp);   
            fclose(fp);   
            huff(n);   
            break;   
        case 2:    
            if((fp=fopen("n.txt","r"))==NULL)   
            {   
                printf("cannot open this file\n");   
                exit(0);   
            }   
            fread(&n,sizeof(int),1,fp);   
            fclose(fp);   
            decode(n);   
            break;   
        default:    
            printf("请您检查输入是否正确！\n");   
            }   
}   

void main()   
{   
    menu();   
}
