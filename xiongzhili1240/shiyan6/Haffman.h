#include<Haffman.h>
void Select(HuffmanTree ht,int j,int *s1,int *s2)

{

    int i; 

    //int占4个字节，最大为2147483647

    int min = 2147483647;

    for(i=1;i<=j;i++){

        if((ht[i].parent == 0) && ht[i].weight < min){

            min = ht[i].weight;

            *s1 = i;

        }



    }

    int lessmin = 2147483647;

    for(i=1;i<=j;i++){

        if((ht[i].parent == 0) && ht[i].weight < lessmin && i != *s1){

        //下标不能相同

            lessmin = ht[i].weight;

            *s2 = i;

        }

    }

}





//建立哈夫曼树

void CrtHuffmanTree(HuffmanTree ht, int w[], int n)

{

    int m,i;

    m = 2*n-1;

    for(i=1;i<=n;i++){ 

        ht[i].weight = w[i];//初始化前n个元素成为根结点

        ht[i].parent = 0;

        ht[i].Lchild = 0;

        ht[i].Rchild = 0;

    }

    for(i=n+1;i<=m;i++){    //初始化后n-1个元素

        ht[i].weight = 0;

        ht[i].parent = 0;

        ht[i].Lchild = 0;

        ht[i].Rchild = 0;

    }

    for(i=n+1;i<=m;i++)    //从第n+1个元素开始构造新结点

    {

        int s1,s2;

        //在ht的前i-1项中选择双亲为0且全值较小的两结点s1,s2

        Select(ht,i-1,&s1,&s2);

        ht[i].weight = ht[s1].weight + ht[s2].weight;//建立新结点，赋权值

        ht[i].Lchild = s1;

        ht[i].Rchild = s2;  //赋新结点左右孩子的指针

        ht[s1].parent = i;

        ht[s2].parent = i;  //改s1,s2的双亲指针

    }

}



//哈夫曼编码

void CrtHuffmanCode1(HuffmanTree ht,huffmanCode hc,int n)

{

    //从叶子到根，逆向求各叶子结点的编码

    char *cd;

    int start,i,c,p;

    cd = (char * )malloc(n*sizeof(char ));//临时编码数组

    cd[n-1] = '\0';          //从后向前逐位求编码，首先放置结束符

    for(i=1;i<=n;i++)        //从每个叶子开始，求相应的哈夫曼编码

    {

        start = n-1;

        c = i;

        p = ht[i].parent;    //c为当前节点，p为其双亲

        while(p!=0){

            --start;

            if(ht[p].Lchild == c)

                cd[start] = '0';//左分支为'0'

            else

                cd[start] = '1';//右分支为'1'

            c = p;

            p = ht[p].parent;   //上溯一层 

        }

        hc[i] = (char *)malloc((n-start)*sizeof(char)); //动态申请编码空间

        strcpy(hc[i],&cd[start]);                       //复制编码

    }

}



//在生成的哈夫曼编码中查询目标

int find_code(huffmanCode hc,int n,char *dest,int *result)

{

    int i ;

    for(i=1;i<=n;i++){

        if(strcmp(dest,hc[i])==0){

            *result = i;

            return 1;

        }

    }

    return 0;

}
