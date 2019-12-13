#include"book.c"


int main()
{
int i;
do
{
     printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n\n");
     printf("★☆---欢迎来到九江学院图书馆管理系统---★☆\n\n");
     printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n\n");
     printf("★☆★☆-----请问你要进行什么操作呢?----★☆★☆\n\n");
     printf("          ★☆★☆★☆★☆★☆★☆★\n");
     printf("          ★☆1:<添加图书信息>--★☆\n");
     printf("          ★☆2:<输出统计图书>--★☆\n");
     printf("          ★☆3:<修改图书信息>--★☆\n");
     printf("          ★☆4:<删除图书信息>--★☆\n");
     printf("          ★☆5:<图书信息检索>--★☆\n");
     printf("          ★☆0:<退出管理程序>--★☆\n");
     printf("          ★☆★☆★☆★☆★☆★☆★\n\n");
    BOOK *book;
    book=Read();
    printf("\n");
    printf("  输入0-5，其他操作无效！\n");
    scanf("%d",&i);

     if(i==1)
     {
       if(book==NULL)
       {
           book=HeadCreate();
        }
            addbook(book);
     }
     else if(i==2)
     countbook(book);
     else if(i==3)
     Changebook(book);
     else if(i==4)
     Deletebook(book);
     else if(i==5)
     Searchbook(book);
     else if(i==0)
     exit(0);
}while(getchar()!='0');
    return 0;
}
