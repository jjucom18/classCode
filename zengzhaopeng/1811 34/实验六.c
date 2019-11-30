#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define n  4//树的叶子节点数
#define m  (2*n-1)//树的节点总数
#define MAXVALUE 1000 //权重最大值
typedef struct htreetype
{
    int weight;//权重
    int parent;//双亲节点
    int Rchild;
    int Lchild;//左右孩子节点
    char name[5];//节点名称

}HtreeType;//树节点的结构体
typedef struct hcodetype
{
    char bit[n];//用于存放编码的数组
     char name[5];//储存节点的名称
     int start;//编码开始的下标

}HcodeType;//编码节点的结构体
void select_htree(HtreeType tree[],int position,int *node1,int *node2);//选择最小的两个
void htree_code(HtreeType tree[],HcodeType code[]);//译码的过程
void creat_htree(HtreeType tree[]);//哈夫曼树的创建
void show_htree(HcodeType code[] );//输出
int main()
{
    HtreeType tree[m];
    HcodeType code[n];
    htree_code(tree,code);
    show_htree(code);
    return 0;


}
void creat_htree(HtreeType tree[])//哈夫曼树的创建
{
    /*
      *初始化树的节点
      *给树的叶子节点赋值
      *利用选择函数进行分支节点的创建
    */
    int node1,node2;
    char name[5];//临时字符串
    int now_weight;//临时变量
    int i,j,k;
    node1=node2=0;
    for(i=0;i<m;i++)
    {
        tree[i].weight=0;
        tree[i].Rchild=-1;
        tree[i].Lchild=-1;
        tree[i].parent=-1;
    }
    printf("一共有%d个叶子节点\n",n);
    for(j=0;j<n;j++)
    {
          printf("请输入节点的数据:");
          scanf("%s",name);
          printf("请输入叶子节点的权重:");
          scanf("%d",&now_weight);
           tree[j].weight=now_weight;
            strcpy(tree[j].name,name);


    }
    for(k=n;k<m;k++)
    {
        select_htree(tree,k,&node1,&node2);
        tree[node1].parent=k;
        tree[node2].parent=k;
        tree[k].Rchild=node2;
        tree[k].Lchild=node1;
        tree[k].weight=tree[node1].weight+tree[node2].weight;
    }
}
void select_htree(HtreeType tree[],int position,int *node1,int *node2)
//选择最小的两个
{
    /*
    *以position为起始点进行寻找最小的两个节点的下标
    *每次调用之后返回
    */
    int i;
    int min1,min2;
    min1=min2=MAXVALUE;
     *node1=*node2=0;
     for(i=0;i<position;i++)
     {
         if(tree[i].parent==-1&&tree[i].weight<min1)
         {
             min2=min1;
             min1=tree[i].weight;
             *node2=*node1;
             *node1=i;

         }
         else if(tree[i].parent==-1&&tree[i].weight<min2)
         {
             min2=tree[i].weight;
              *node2=i;
         }
     }
}
void htree_code(HtreeType tree[],HcodeType code[] )//译码的过程
{
    HcodeType cd;//临时储存节点的编码
    int i;//循环变量
    creat_htree(tree);
    int parent_position,now_position;
    for(i=0;i<n;i++)
       {
           cd.start=n;
           strcpy(cd.name,tree[i].name);
           now_position=i;
           parent_position=tree[i].parent;
           while(parent_position!=-1)//从下往上遍历指点根节点结束
           {
               cd.start--;//作为数组的循环下标
               if(tree[parent_position].Lchild==now_position)
                   cd.bit[cd.start]='0';
                   else
                   {
                       cd.bit[cd.start]='1';
                   }
                   now_position=parent_position;
                 parent_position=tree[now_position].parent;
           }
           code[i]=cd;//传递编码到code数组去
        }
}
void show_htree(HcodeType code[] )//输出
{
     int i,j;
     for(i=0;i<n;i++)
     {
            printf("%s     ",code[i].name);
           for(j=code[i].start;j<n;j++)
            printf("%c",code[i].bit[j]);
             printf("\n");
    }

}





