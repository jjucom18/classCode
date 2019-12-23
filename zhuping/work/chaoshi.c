#include "chaoshi.h"
#include <time.h>

void input(LNode *L)//录入商品信息 //尾插法创建链表
{
    int i,n;
    LNode *r=L,*s;
    goods x;
    printf("\n请输入商品的种数:");
    scanf("%d",&n);
    printf("\n请输入商品的名称、编号、数量\n");
    printf("\n");
    for(i=1;i<=n;i++)
    {
        printf("商品名称： ");
        scanf("%s",x.name);
        printf("商品编号： ");
        scanf("%s",x.no);
        printf("商品数量： ");
        scanf("%d",&x.num);
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=NULL;
        r->next=s;
        r=s;
        printf("\n");
    }
        printf("\n录入结束，返回上一级\n");
}
void run_over(LNode *L)//输出商品信息 //遍历链表
{
    LNode *p=L->next;
 
    if(p==NULL)
    {
        printf("系统还未录入商品信息，请录入后在进行操作\n");
        menu();
    }
    printf("\n下面是商品信息一览表\n");
    printf("\n");
    printf("商品名称   商品编号    商品数量\n");
    printf("\n");
 
    while(p!=NULL)
    {
        printf("%5s%10s%12d\n",p->data.name,p->data.no,p->data.num);
        p=p->next;
    }
}

LNode* search(LNode *L,goods x)//查找商品，输入商品编号在链表中查找
{
    LNode *p=L->next;
    while(p!=NULL&&(strcmp(p->data.no,x.no)!=0))
    {
        p=p->next;
    }
    if(p!=NULL&&(strcmp(p->data.no,x.no)==0))            //查找到相应商品，返回指针
    {
        return p;
    }
    else
    {
        return NULL;
    }
}
  
void insert(LNode *L,goods x)//插入商品
{
    LNode *p=L,*s;
    while(p->next!=NULL&&(strcmp(p->next->data.no,x.no)!=0))//商品不存在时可插入到已有链表上
    {
        p=p->next;
    }
    s=(LNode*)malloc(sizeof(LNode));
    s->data=x;
    s->next=p->next;
    p->next=s;
}
 
 
void goodspai(LNode *L)//排序商品
{
    LNode *p,*q,*r;
    int choose;
    goods x;
    printf("请选择排序方式：");
    printf("1.按商品编号排序   2.按库存数量排序 \n");
    scanf("%d",&choose);
    switch(choose)
    {
        case 1: //按商品编号直接插入排序
            p=L->next->next;//p指向第一个节点的后继
            L->next->next=NULL;//直接插入排序，第一个元素在有序区，从第二元素起依次插入
            while(p!=NULL)
            {
                r=p->next;//r指针暂存p的后继
                q=L;
                while(q->next!=NULL&&(strcmp(q->next->data.no,p->data.no)>0))//查找插入位置
                    q=q->next;  //将p节点链入链表
                p->next=q->next;
                q->next=p;
                p=r;
            }
            break;
 
        case 2: //按商品数量冒泡排序
             p=L->next;
             while(p)
             {
                q=p->next;
                while(q)
                {
                    if(p->data.num<=q->data.num)
                    {
                        x=p->data;
                        p->data=q->data;
                        q->data=x;
                    }
                    q=q->next;
                }
                p=p->next;
            }
            break;
    }
 
}

void storage(LNode *L,goods x)//商品信息入库
{
    LNode *p;
    p=search(L,x);
    if(p==NULL) //链表中没有这个商品时可直接插入
    {
        insert(L,x);
    }
    else
    {
        p->data.num=p->data.num+x.num; //链表中中有这个商品时只增加商品的数量
    }
}
 
void goodsChange(LNode *L,goods x) //以商品编号修改商品信息
{
 
    LNode *p;
    char chname[30];
    char chno[30];
    int chnum;
    p=search(L,x);
    if(p==NULL)
    {
        printf("\n仓库中无此商品！\n");
    }
    else
    {
        printf("\n修改商品编号：");
        scanf("%s",chno);
        strcpy(p->data.no,chno);
        printf("\n修改商品名称：");
        scanf("%s",chname);
        strcpy(p->data.name,chname);
        printf("\n修改商品数量：");
        scanf("%d",&chnum);
        p->data.num=chnum;
        printf("\n成功修改！\n");
    }
 
}
 
int del(LNode *L,goods x)//删除商品信息
{
    LNode *p;
    long n;
    int flag=0;          //flag为判断商品是否删除的标志
    p=L;
    for(; p!=NULL; p=p->next)
    {
        if(p->next!=NULL&&(strcmp(p->next->data.no,x.no)==0))
        {
            p->next=p->next->next;     //删除语句
 
            flag=1;
            break;
        }
    }
    if(p==NULL&&flag==0)
    {
        printf("\n不存在此商品！");
        menu();
    }
    return 1;
}
 
void out(LNode *L,goods x)//商品出库
{
    int j;
    LNode *p;
    p=search(L,x);
    if(p==NULL)
    {
        printf("\n仓库中无此商品！\n");
    }
    else
    {
        printf("\n   您要购买的商品为：%s。\n",p->data.name);
        if(p->data.num>x.num)                                     //购买的商品数量少于库存量时
        {
            printf("\n购买成功!欢迎下次光临！\n");
            p->data.num=p->data.num-x.num;                        //库存数=原库存数-购买数
            printf("\n");
            printf("\n该商品还有%d件。\n",p->data.num);           //显示现在的库存
        }
        else if(p->data.num==x.num)                               //购买的商品数量等于库存量时
        {
            printf("\n购买成功!欢迎下次光临！\n");                
            del(L,x);                                             //调用删除函数，系统显示已售空
            printf("\n");
            printf("\n该商品已售空，请及时补充库存。\n");          
        }
        else if(p->data.num<x.num)                                //购买的商品数量多于库存量时
        {
            printf("\n该商品数量不足，仅剩%d。是否购买\n",p->data.num);
            printf("(购买请按1，不购买请按0。)\n");
            printf("请输入您的的选择：");
            scanf("%d",&j);
            if(j==1)
            {
                del(L,x);                    //若选择购买，则把剩余的该商品全部买走
                printf("\n购买成功!欢迎下次光临！\n");
                printf("\n");
                printf("\n该商品已售空，请及时补充库存。\n");
            }
            else
            {
                printf("\n欢迎下次光临！\n");
            }
        }
    }
}
 

void save(LNode *L)    //保存操作结果
{
    int i;
    LNode *p=L->next, *q=L->next;
    FILE *fp;                                 //文件指针
    if(p==NULL)
    {
        printf("现在没有商品信息，请先输入信息再进行操作\n");
        return;
    }
    fp=fopen("goods.txt","w");    //在当前目录下打开goods.txt文件并设置只允许“写”操作
    if(!fp)
    {
        printf("文件不存在\n");
        return;
    }
    //将商品信息写入文件
    fprintf(fp,"商品信息一表\n");
    fprintf(fp,"\n");
    fprintf(fp,"商品名称\t商品编号\t商品数量\n");
    while(p!=NULL)
    {
        fprintf(fp,"%s\t\t%s\t\t%d\t\t",p->data.name,p->data.no,p->data.num);
        fprintf(fp,"\n");
        p=p->next;
    }
 
    fclose(fp); //把缓冲区内最后剩余的数据输出到内核缓冲区,并释放文件指针
    printf("数据已成功导入文件goods.txt！\n");
}
 
void menu()//系统界面
{
    printf("\n");
    printf("欢迎使用超市商品管理系统\n");
    printf("请选择您要操作的项目\n");
    printf("1 录入商品信息\n");
    printf("2 浏览商品清单\n");
    printf("3 查找商品信息\n");
    printf("4 修改商品信息\n");
    printf("5 商品信息排序\n");
    printf("6 商品入库\n");
    printf("7 商品出库\n");
    printf("8 删除商品\n");
    printf("9 保存操作\n");
    printf("0 退出系统\n");
}
