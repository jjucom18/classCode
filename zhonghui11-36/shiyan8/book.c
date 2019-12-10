#include "book.h"
BOOK *HeadCreate()
{
    BOOK *head;
    head=(BOOK*)malloc(sizeof(BOOK));
    head->next=NULL;
    return head;

}

BOOK *Read()
{
    FILE *fp;
    BOOK *p,*q;
    BOOK *head=HeadCreate();

    int i=0;
    if((fp=fopen("book.txt","r+"))==NULL)
    {
      return head;
    }

    while(1){
    if(!feof(fp))
    {
        p=HeadCreate();
        fscanf(fp,"%s%s%s%s%s%s",p->bookISBN,p->bookname,p->bookauthor,p->bookpublisher,p->bookdate,p->bookprice);
        if(feof(fp))
            break;
        if(i==0)
        {
            head->next=p;
            i=1;
        }
        else
        {
            q->next=p;

        }
        q=p;
    }
    }
    fclose(fp);
    return head;
}

void Save(BOOK *head)
{
    FILE *fp;
    BOOK *p;
    p=head;
    fp=fopen("book.txt","w+");

    while(p->next!=NULL)
    {
        p=p->next;
        fprintf(fp,"%s\n%s\n%s\n%s\n%s\n%s\n",p->bookISBN,p->bookname,p->bookauthor,p->bookpublisher,p->bookdate,p->bookprice);

    }
    fclose(fp);
}




void addbook(BOOK*head)
{
system("cls");
printf("----欢迎来到添加图书界面！-----\n\n");
 BOOK*q, *p;
 int s=0;
 char choice='Y';
 p=head;

 while(p->next!= NULL)
    {
     p=p->next;
 }

 while(choice=='Y'||choice=='y')
 {
     s++;
  q=(BOOK *)malloc(sizeof(BOOK));
  printf("输入图书ISBN编号: ");
  scanf("%s",q->bookISBN);

   printf("输入图书书名: ");
  scanf("%s",q->bookname);

  printf("输入图书作者: ");
  scanf("%s",q->bookauthor);

  printf("输入图书出版社: ");
  scanf("%s",q->bookpublisher);

  printf("输入图书出版日期: ");
  scanf("%s",q->bookdate);

  printf("输入图书价格: ");
  scanf("%s",q->bookprice);

  printf("\n");
    p->next=q;
    p=q;
    q->next=NULL;
  printf("已成功添加%d本图书\n",s);
  printf("要继续添加新的书籍吗？(Y/N):");
  getchar();
  choice=getchar();
  printf("\n");
  if(choice=='Y'||choice=='y')
  {continue;}
  else if(choice=='N'||choice=='n')
  {break;}
  else
  {
      printf("输入错误！\n");
      printf("要继续添加新的书籍吗？(Y/N):");
      getchar();
      choice=getchar();
      if(choice=='Y'||choice=='y')
     {continue;}
      else if(choice=='N'||choice=='n')
     {break;}
  }
 }
            Save(head);
            printf("按任意键返回\n");
            //getch();
            system("cls");
 return;
}




void countbook(BOOK *head)
{
    system("cls");
    printf("----欢迎来到统计图书界面！-----\n\n");
    printf("书库中的图书如下：\n\n");
    BOOK *p;
    p=head;
    int s=0;
    if(head==NULL||head->next==NULL)
    {
        printf("书库中无图书！\n");
        printf("按任意键返回\n");
        //getch();
        system("cls");

        return ;
    }
    while(p->next!=NULL){
    s++;
    p=p->next;
    printf("ISBN号： %s\n",p->bookISBN);
    printf("书名： %s\n",p->bookname);
    printf("作者： %s\n",p->bookauthor);
    printf("出 版 社： %s\n",p->bookpublisher);
    printf("出版日期： %s\n",p->bookdate);
    printf("价格： %s 元\n",p->bookprice);

    printf("\n");
    }
    printf("书库中有%d本图书\n",s);
    printf("\n");
    printf("按任意键返回\n");
    //getch();
    system("cls");
}




void Searchbook(BOOK *head)
{
    BOOK *p;
    p=head;
    char s[20];
    int t=0;
    char ch2;
do
{  system("cls");
   printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n\n");
   printf("★☆---------欢迎来到图书检索界面！---------★☆\n\n");
   printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n\n");
   printf("   |★☆★☆★☆★☆★☆★☆★☆★☆★☆|\n");
   printf("   |----1：<按图书ISBN编号查询>---------|\n");
   printf("   |----2：<根据出版社名称查询>---------|\n");
   printf("   |----3：<根据书目关键字查询>---------|\n");
   printf("   |----4：<根据图书作者名查询>---------|\n");
   printf("   |----0：<离开界面>-------------------|\n");
   printf("   |★☆★☆★☆★☆★☆★☆★☆★☆★☆|\n");
    printf("     < 请输入0--4，其他输入无效！>\n\n");
		printf("  选择菜单: ");

   scanf("%s",&ch2); printf("\n");
   switch(ch2)
   {
    case '1':{
        printf("\n");
        printf("请输入要查询的图书的ISBN号：");
        scanf("%s",s);
        while(p->next!=NULL)
       {
           p=p->next;
           if(strcmp(s,p->bookISBN)==0)
          {
              t++;
              printf("ISBN号:   %s\n",p->bookISBN);
              printf("书名： %s\n",p->bookname);
              printf("作者： %s\n",p->bookauthor);
              printf("出版社： %s\n",p->bookpublisher);
              printf("出版日期： %s\n",p->bookdate);
              printf("价格： %s元 \n",p->bookprice);
              printf("\n");
           }
       }
       if(t==0)
           printf("查找失败！书库中暂时没有你要的书籍\n");
       else
           printf("搜索到%d个结果\n",t);
           printf("按任意键返回\n");
           //getch();

   };break;
    case '2':{
        printf("\n");
        printf("请输入要查询的图书的出版社：");
        scanf("%s",s);
        while(p->next!=NULL)
       {
           p=p->next;
           if(strcmp(s,p->bookpublisher)==0)
          {
              t++;
              printf("ISBN号： %s\n",p->bookISBN);
              printf("书名： %s\n",p->bookname);
              printf("作者： %s\n",p->bookauthor);
              printf("出版社： %s\n",p->bookpublisher);
              printf("出版日期： %s\n",p->bookdate);
              printf("价格： %s元 \n",p->bookprice);
              printf("\n");
           }
       }
        if(t==0)
           printf("查找失败！书库中暂时没有你要的书籍\n");
       else
           printf("搜索到%d个结果\n",t);
           printf("按任意键返回\n");
         //  getch();
       };break;
    case '3':{
            printf("\n");
            printf("请输入要查询的书名：");
            scanf("%s",s);
        while(p->next!=NULL)
       {
           p=p->next;
           if(strcmp(s,p->bookname)==0)
          {
              t++;
              printf("ISBN号： %s\n",p->bookISBN);
              printf("书名： %s\n",p->bookname);
              printf("作者： %s\n",p->bookauthor);
              printf("出 版 社： %s\n",p->bookpublisher);
              printf("出版日期： %s\n",p->bookdate);
              printf("价格： %s元 \n",p->bookprice);
              printf("\n");
           }
       }
        if(t==0)
           printf("查找失败！书库中暂时没有你要的书籍\n");
       else
           printf("搜索到%d个结果\n",t);
           printf("按任意键返回\n");
           //getch();
     };break;
    case '4':{
        printf("\n");
        printf("请输入要查询的图书的作者：");
        scanf("%s",s);
        while(p->next!=NULL)
       {
           p=p->next;
           if(strcmp(s,p->bookauthor)==0)
          {
               t++;
              printf("ISBN  号： %s\n",p->bookISBN);
              printf("书名： %s\n",p->bookname);
              printf("作者： %s\n",p->bookauthor);
              printf("出 版 社： %s\n",p->bookpublisher);
              printf("出版日期：%s\n",p->bookdate);
              printf("价格： %s元 \n",p->bookprice);
              printf("\n");
           }
       }
       if(t==0)
           printf("查找失败！书库中暂时没有你要的书籍\n");
       else
           printf("搜索到%d个结果\n",t);
           printf("按任意键返回\n");
           //getch();
     };break;
    case '0':break;
    default:printf("ERROR，按任意键返回");
	//getch();
	break;
   }
}while(ch2!='0');

system("cls");
}





void Changebook(BOOK *head)
{
    system("cls");
    printf("----欢迎来到修改图书界面！-----\n\n");
    BOOK *p;
    p=head;
    char s[20],c;
    c='Y';
    char choice;
    printf("请输入要修改图书的ISBN号：");scanf("%s",s);
        while(p->next!=NULL)
       {
           p=p->next;
           if(strcmp(s,p->bookISBN)==0)
          {
              while(c=='Y'||c=='y'){
              printf("你所要修改的书的资料如下，请选择你要修改的内容\n");
              printf("      ISBN编号： %s\n",p->bookISBN);
              printf("      书名： %s\n",p->bookname);
              printf("      作者： %s\n",p->bookauthor);
              printf("      出版社： %s\n",p->bookpublisher);
              printf("      出版日期： %s\n",p->bookdate);
              printf("      价格： %s元\n",p->bookprice);
              printf("      1：修改书的ISBN号\n");
              printf("      2：修改书名\n");
              printf("      3：修改作者\n");
              printf("      4：修改出版社\n");
              printf("      5：修改出版日期\n");
              printf("      6：修改价格\n");
              printf("     请输入1-6，其他输入无效:");
              scanf("%s",&choice);
              switch(choice)
    {
     case '1':
		 {
      printf("请输入新的ISBN号\n");
      scanf("%s",p->bookISBN);
     }break;
     case '2':
		 {
      printf("请输入新的书名\n");
      scanf("%s",p->bookname);
     }break;
     case '3':
		 {
      printf("请输入新的作者\n");
      scanf("%s",p->bookauthor);
     }break;
     case '4':
		 {
      printf("请输入新的出版社\n");
      scanf("%s",p->bookpublisher);
     }break;
     case '5':
		 {
      printf("请输入新的出版日期\n");
      scanf("%s",p->bookdate);
     }break;
     case '6':
     {

      printf("请输入新的价格\n");
      scanf("%s",p->bookprice);
     }break;
     default:printf("没有这样的操作");break;
    }
        printf("\n");
        printf("已成功修改图书信息\n");
        printf("要继续修改图书信息吗？(Y/N):");
        getchar();c=getchar();
        printf("\n");
         if(c=='Y'||c=='y'){continue;}
        else if(c=='N'||c=='n'){break;}

   }
}
    }
       Save(head);
        printf("按任意键返回\n");
        //getch();
        system("cls");
}



void Deletebook(BOOK *head)
{
    system("cls");
    printf("----欢迎来到删除图书界面！-----\n\n");
    BOOK *p,*q;
    p=head;
    int i=0;
    char s[20],choice;
    printf("请输入你所要删除图书的ISBN号：");
    scanf("%s",s);
        while(p->next!=NULL)
       {
           q=p;
           p=p->next;
           if(strcmp(s,p->bookISBN)==0)
          {
              i=1;
              printf("以下是你所要删除图书的图书信息，是否删除(Y/N)：\n");
              printf("      ISBN号：%s\n",p->bookISBN);
              printf("      书名： %s\n",p->bookname);
              printf("      作者： %s\n",p->bookauthor);
              printf("      出版社： %s\n",p->bookpublisher);
              printf("      出版日期： %s\n",p->bookdate);
              printf("      价格： %s元\n",p->bookprice);
               getchar();
               choice=getchar();
                if(choice=='Y'||choice=='y')
                {
                    q->next=p->next;
                    free(p);
                }
               else if(choice=='N'||choice=='n'){printf("已取消删除操作！\n");break;}
              printf("操作成功！\n");
              Save(head);
              }
           }
           if(i==0)
            printf("目录中没有该图书！\n");
            printf("按任意键返回\n");
           // getch();
            system("cls");
       }
