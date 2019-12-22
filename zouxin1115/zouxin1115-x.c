#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct BSTree
{ int id;
char name[20];
char factory[20];
char transporter[20];
int entertime;
int number;
struct BSTree *lchild,*rchild; 
}BSTree;
int InputBSTree(BSTree *T,int *m);
int CreatBSTree(BSTree *T);
BSTree *FindBSTreeinsert(int num,BSTree *T,int *flag);
BSTree *FindBSTreeequal(int num,BSTree *T,int *flag);
int EditBSTree(BSTree *T);
BSTree *InsertBSTree(BSTree *T);
BSTree *DeleteBSTree(BSTree *T);
BSTree *DelBSTree(int num,BSTree *T,int *flag);
BSTree *Del(BSTree *T);
int SearchBSTree(BSTree *T);
int PrintBSTree(BSTree *T);
int Print(BSTree *T);
int Get_int(void);
int SaveBSTree(BSTree *T);
int Save(FILE *fp,BSTree *T);
void main(void)
{ BSTree *T=0;
int flag=0,m=0;
while(!(T=(BSTree *)malloc(sizeof(BSTree))))
     continue;
T->lchild=T->rchild=0;
printf("            ---------------------------------------------------------/n");
printf("            |                                                       |/n");
printf("            |             ^_^ 欢迎使用仓库管理系统                  |/n");
printf("            | 货物信息 商品号,名称,生产商,供应商,库存量，进货日期   |/n");
printf("            ---------------------------------------------------------/n");
do 
{ printf("/n1,读入 | 2,编辑 | 3,插入 | 4,删除 | 5,查找(以商品号)| 6,输出所有信息 | 0,退出/n操作=");
    flag=Get_int();
switch(flag)
{ case 1: InputBSTree(T,&m); if(m) PrintBSTree(T); break;
   case 2: EditBSTree(T); PrintBSTree(T);break;
      case 3: T=InsertBSTree(T); PrintBSTree(T);break;
      case 4: T=DeleteBSTree(T); PrintBSTree(T);break;
      case 5: SearchBSTree(T); break;
      case 6: PrintBSTree(T);break;
   case 0: break;
   default : printf("/n*********对不起，选择无效！*******/n");
}
}while(flag);
printf("/n您想保存吗？/n||1，保存|0,不保存||/n选择=");
flag=Get_int();
if(flag)
   SaveBSTree(T); 
printf("/n谢谢使用，按任意键继续/n");
getchar();
}
int InputBSTree(BSTree *T,int *m)
{ 
int flag=0;
char address[100];
FILE *fp=0;
BSTree *t=0,*S=0;
printf("你想用什么方式读入货物信息？ /n1，键盘输入/n2,从硬盘读取/n选择=");
flag=Get_int();
if(flag==1)
{ 
    printf("货物信息包括：货品号，货品名，生产商，供应商，库存量，进货日期!/n");
    
    printf("当货品号输入非数字时结束/n");
    printf("请输入货品号/n货品号=");
    if(scanf("%d",&T->id)!=1) 
{ while(getchar()!='/n')
    continue;
    return 0;
}
while(getchar()!='/n')
     continue;
if(T->id<0)
{ printf("/n货品号不能小于0!!!,读入失败!!!/n");
      return 0;
}
    printf("请输入商品名/n商品名=");
    gets(T->name);
    printf("请输入生产商/n生产商=");
    gets(T->factory);
    printf("请输入供应商/n供应商=");
    gets(T->transporter);
printf("请输入库存量/n库存量=");
    T->number=Get_int();
    printf("请输入进货时间/n进货时间=");
    T->entertime=Get_int();
    CreatBSTree(T);
}
else if(flag==2)
{ printf("请输入要读取文件的地址：/n地址=");
    gets(address);
if(!(fp=fopen(address,"r")))
{ printf("/n********读取失败，文件：%s打不开*********",address);
   return 0;
}
    fscanf(fp,"/t%d/t%s/t%s/t%s/t%d/t%d",&T->id,T->name,T->factory,T->transporter,&T->number,&T->entertime);
while(feof(fp)!=1)
{ while(!(t=(BSTree *)malloc(sizeof(BSTree))))
       continue;
   t->lchild=t->rchild=0;
   fscanf(fp,"/t%d/t%s/t%s/t%s/t%d/t%d",&t->id,t->name,t->factory,t->transporter,&t->number,&t->entertime);
   flag=0;
   S=FindBSTreeinsert(t->id,T,&flag);
   if(flag)
   { if(t->id<=0||t->id>=10000) break;
    
    else if(t->id<S->id&&!S->lchild)
     S->lchild=t;
      else if(t->id>S->id&&!S->rchild)
    S->rchild=t;
   }
}
fclose(fp); 
    printf("读取完毕");
}
*m=1; 
return 1;
}
int CreatBSTree(BSTree *T)
{ BSTree *t=0,*S=0;
int m=0,flag=0;
while(1)
{ 
printf("当货品号输入非数字时结束/n");
printf("请输入货品号/n货品号=");
if(scanf("%d",&m)!=1)
{ while(getchar()!='/n') 
    continue;
    return 0;
}
while(getchar()!='/n')
     continue;
if(m<0)
{ printf("/n货品号不能小于0!!!,请重新输入!!!/n");
    continue;
}
while(!(t=(BSTree *)malloc(sizeof(BSTree))))
   continue;
t->lchild=t->rchild=0;
t->id=m;
printf("请输入商品名/n商品名=");
gets(t->name);
printf("请输入生产商/n生产商=");
gets(t->factory);
printf("请输入供货商/n供货商=");
gets(t->transporter);
printf("请输入货物库存量/n货物库存量=");
t->number=Get_int();
printf("请输入进货时间/n进货时间（年）=");
t->entertime=Get_int();
S=FindBSTreeinsert(t->id,T,&flag);
if(flag==1)
   S->lchild=t;
   else if(flag==3)
    S->rchild=t;
   else 
   printf("/n*********输入失败（可能该货物已存在），请重新输入***************/n");
}
return 1;
}
BSTree *FindBSTreeinsert(int id,BSTree *T,int *flag) 
{ 
if(T)
{
   if(id<T->id&&!T->lchild)
   { *flag=1;
      return T;
   }
else if(id<T->id&&T->lchild)
    FindBSTreeinsert(id,T->lchild,flag);
else if(id>T->id&&!T->rchild)
   { *flag=3;
      return T;
   }
else if(id>T->id&&T->rchild)
     FindBSTreeinsert(id,T->rchild,flag);
}
}
BSTree *FindBSTreeequal(int id,BSTree *T,int *flag) 
{ 
if(T)
{
   if(id==T->id)
   { *flag=2;
      return T;
   }
else if(id<T->id&&T->lchild)
    FindBSTreeequal(id,T->lchild,flag);
else if(id>T->id&&T->rchild)
     FindBSTreeequal(id,T->rchild,flag);
}
}
int EditBSTree(BSTree *T)
{ BSTree *S=0,*t=0;
int id=0,flag=0;
if(!T)
{ printf("/n*******对不起，没有数据能够编辑，请首先输入！*******/n");
    return 0;
}
printf("请输入要编辑货物的号码：/n号码=");
id=Get_int();
S=FindBSTreeequal(id,T,&flag);
if(flag==2)
{ 
   printf("/n***********************货品号是%d的货物的信息如下：******************/n",id);
    printf("/n货物号%d 货物名称%s 生产厂家%s 供货商%s 库存量%d 进货时间%d/n",S->id,S->name,S->factory,S->transporter,S->number,S->entertime);
printf("/n************************************************************************/n");
printf("/n请输入货品名字/n货品名字=");
    gets(S->name);
    printf("请输入生产商/n生产商=");
    gets(S->factory);
    printf("请输入供货商/n供货商=");
    gets(S->transporter);
printf("请输入货物库存量/n库存量=");
    S->number=Get_int();
    printf("请输入进货时间/n进货时间=");
    S->entertime=Get_int();
return 1;
}
else 
{ printf("****对不起，没有货物号是%d的货物************",id);
    printf("/n你想插入此货物的信息吗？（1，添加，0不添加）/n选择=");
flag=Get_int();
if(flag)
{ T=InsertBSTree(T);
   return 1;
}
else return 0;
}
}
BSTree *InsertBSTree(BSTree *T) 
{ 
BSTree *S=0,*t=0;
int flag=0;
while(!(t=(BSTree *)malloc(sizeof(BSTree))))
   continue;
printf("请输入货物号/n货物号=");
t->id=Get_int();
if(t->id<0)
{ printf("/n插入失败!!!,货物号不能小于0!!!");
    return 0;
}
printf("请输入货物名称/n货物名称=");
gets(t->name);
printf("请输入生产厂家/n生产厂家=");
gets(t->factory);
printf("请输入供应商/n供应商=");
gets(t->transporter);
printf("请输入库存数量/n库存数量=");
t->number=Get_int();
printf("请输入进货时间/n进货时间=");
t->entertime=Get_int();
t->lchild=t->rchild=0;
if(!T)
{ T=t;
return T;
}
S=FindBSTreeinsert(t->id,T,&flag);
   if(flag==1)                                                       
    S->lchild=t;
    else if(flag==3)
    S->rchild=t;
   else printf("/n插入失败！可能插入的货物信息已经存在/n");
return T;
}
BSTree *DeleteBSTree(BSTree *T) ///删除操作主函数
{   int id,flag=0;
    BSTree *S=0;
printf("请输入要删除货物的货物好：/n货物号=");
id=Get_int();
    S=DelBSTree(id,T,&flag);
if(flag==0)
   printf("/n*******删除失败，没有货物号是%d的货物的信息********/n",id);
return S;
}
BSTree *DelBSTree(int id,BSTree *T,int *flag)//删除操作一级子函数
{ int m;
if(!T)
*flag=0;
else if(id==T->id)
{ printf("******货物号为%d货物的信息如下，确认要删除吗？********/n",id);
printf("/n货物号%d 货物名称%s 生产厂家%s 供货商%s 库存量%d 进货时间%d/n",T->id,T->name,T->factory,T->transporter,T->number,T->entertime);
printf("/n****************************************************/n");
printf("/n确认要删除吗？/n 1，删除 || 0，取消删除/n选择=");
m=Get_int();
if(m==0)
{ *flag=1; 
    return T;
}
T=Del(T);
*flag=1;
}
else if(id<T->id)
T->lchild=DelBSTree(id,T->lchild,flag);
else T->rchild=DelBSTree(id,T->rchild,flag);
return T;
}
BSTree *Del(BSTree *T) //删除操作二级子函数
{ BSTree *S=0,*Q;
if(T->lchild)
{ S=T->lchild;
    while(S->rchild)
S=S->rchild;
S->rchild=T->rchild;
Q=T->lchild;
free(T);
return Q;
}
else 
{ Q=T->rchild;
    free(T);
return Q;
}
}
int SearchBSTree(BSTree *T)
{ int id,flag=0;
BSTree *S=0;
printf("请输入要查找货物的货品号/n货品号=");
id=Get_int();
S=FindBSTreeequal(id,T,&flag);
   if(flag==2)
{ printf("***********货品号是%d的货物的信息如下：**************/n",id);
    printf("/n货物号%d 货物名称%s 生产厂家%s 供货商%s 库存量%d 进货时间%d/n",S->id,S->name,S->factory,S->transporter,S->number,S->entertime);
printf("/n**********************************************************/n");
return 1;
}
printf("/n******查找失败，没有货物号=%d 货物的信息*******/n",id);
return 0;
}
int PrintBSTree(BSTree *T)
{ if(!T)
{ printf("/n***********************没有货物的信息*************************/n");
return 0;
}
printf("/n***************************货物的信息如下：***************************/n");
Print(T);
printf("/n********************************************************************/n");
return 1;
}
int Print(BSTree *T)
{ 
if(T) 
{ Print(T->lchild);
printf("/n货物号%d 货物名称%s 生产厂家%s 供货商%s 库存量%d 进货时间%d/n",T->id,T->name,T->factory,T->transporter,T->number,T->entertime);
Print(T->rchild);
return 1;
}
return 0;
}
int Get_int(void)
{ int m;
while(scanf("%d",&m)!=1)
{ while(getchar()!='/n')
     continue;
    printf("/n请输入一个整数!/n输入=");
}
while(getchar()!='/n')
     continue;
return m;
}
int SaveBSTree(BSTree *T)
{ char address[100];
FILE *fp=0;
printf("请输入保存的地址/n地址=");
gets(address);
if(!(fp=fopen(address,"w")))
{ printf("/n对不起，打不开%s",address);
    return 0;
}
Save(fp,T);
printf("保存完毕，保存地址是：%s",address);
fclose(fp);
return 1;
}
int Save(FILE *fp,BSTree *T)
{ 
if(!T) return 0;
   Save(fp,T->lchild);
fprintf(fp,"/t%d/t%s/t%s/t%s/t%d/t%d/n",T->id,T->name,T->factory,T->transporter,T->number,T->entertime);
   Save(fp,T->rchild);
}
