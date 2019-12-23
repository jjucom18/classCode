#include "chaoshi.h"
#include <time.h>
 
int main()
{   goods x;
    int sel;
    LNode *L,*p;
    L=(LNode *)malloc(sizeof(LNode));
    do
    {   menu();
        printf("请输入您的选择:\n");
        scanf("%d",&sel);
        switch(sel)
        {   case 1:
                   printf("\n您选择了录入商品信息功能!\n");
                   input(L);
                   break;
            case 2:
                   printf("\n您选择了浏览商品清单功能!\n");
                   run_over(L);
                   break;
            case 3:
                   printf("\n您选择了查找商品信息功能!\n");
                   printf("请输入要查找的商品的编号：\n");
                   printf("您输入的编号为：");
                   scanf("%s",x.no);
                   p=search(L,x);
                   if(p==NULL)
                   {
                       printf("\n该商品不存在。\n");
                   }
                   else
                   {
                       printf("\n商品名称    商品编号    商品数量\n");
                       printf("%5s%10s%12d\n",p->data.name,p->data.no,p->data.num);
                   }
                   break;
            case 4:
                   printf("\n您选择了修改商品信息功能!\n");
                   printf("\n请输入要修改的商品的编号:\n");
                   printf("商品编号： ");
                   scanf("%s",x.no);
                   goodsChange(L,x);
                   break;
            case 5:
                   goodspai(L);
                   printf("\n已完成排序，若要查看排序后的结果，请回到初始界面。 \n");
                   break;
            case 6:
                   printf("\n您选择了商品入库功能!\n");
                   printf("请输入要入库的商品的名称、编号及数量:\n");
                   printf("商品名称： ");
                   scanf("%s",x.name);
                   printf("商品编号： ");
                   scanf("%s",x.no);
                   printf("商品数量： ");
                   scanf("%d",&x.num);
                   storage(L,x);
                   printf("\n入库成功!\n"); 
                   break;
            case 7:
                  printf("\n您选择了商品出库功能!");
                  printf("\n请输入要出库的商品的编号、数量:\n");
                  printf("商品编号： ");
                  scanf("%s",x.no);
                  printf("商品数量： ");
                  scanf("%d",&x.num);
                  out(L,x);
                  break;
            case 8:
                  printf("\n您选择了商品删除功能!");
                  printf("\n请输入要出库的商品的编号:\n");
                  printf("商品编号： ");
                  scanf("%s",x.no);
                  del(L,x);
                  printf("\n成功删除！\n");
                  break;
            case 9:
                  printf("\n您选择了保存操作功能!\n");
                  save(L);
                  printf("\n保存成功！\n");
                  break;
        }
    }
    while(sel!=0);
	return 0;
}
