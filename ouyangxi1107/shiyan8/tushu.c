#include "tushu.h"
//个人图书管理 系统的主要功能
void   Interface();                                                            //主界面
void   f_new();                                                                //新建图书文件操作
void   edit();                                                                 //对图书的显示  删除  更新  查找 操作
void   e_insert();                                                             //图书的插入
void   e_delete();                                                             //图书的删除
void   e_update();                                                             //图书的更新
void   display();                                                              //图书的显示
void   sort();                                                                 //排序
void   all();                                                                  //统计图书
void   search();                                                               //查找
void    swatch(BOOK  *p,BOOK  *q);                                             //交换日期 函数
void    select()                                                               //选择函数
{
  int    i;
  printf("        请选择你要执行的操作：1主界面   2退出系统\n");
  scanf("%d",&i);
  switch(i)
  {
   case  1:     system("cls");   Interface();break;
   case  2:        exit(0);    break;
   default :   printf("输入有误");
  }
}    //选择函数
//交换日期 函数
void    swatch(BOOK  *p,BOOK  *q)
{
 BOOK   temp;
 temp=*p;
 *p=*q;
 *p=temp;
}//交换日期 函数
    //主界面
void    Interface()
{
   int    i;
   printf("\n");
  printf("\n");
  printf("\n"); 
  printf("\n");
  printf("                       ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
   printf("                       &   个人图书管理系统主界面   &  \n");
   printf("                       &      1新建文件操作         &  \n");
   printf("                       &      2编辑图书信息         &  \n");
   printf("                       &      3显示图书信息         &  \n");
   printf("                       &      4图书排序             &  \n");
   printf("                       &      5统计图书             &  \n");
   printf("                       ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
   printf("                          选择你要执行的操作\n");
   scanf("%d",&i);
   switch(i)
   {
   case  1:  f_new();   system("cls");    break;
   case  2:  edit();    system("cls");    break;
   case  3:  display(); system("cls");    break;
   case  4:  sort();    system("cls");    break;
   case  5:  all();system("cls");  break;
   default:   printf("错误输入程序结束\n");system("pause"); //  break;
  }
}    //主界面
 //新建图书文件操作
void      f_new()
{
   int     n,i;
   int     m=0;
   FILE*fp;
   if((fp=fopen("E:\\课程设计\\01.txt","a+"))==NULL)                        //一读的方式打开文件
   {
    printf("cannot  open   01.txt\n");
 
   }
   while(!feof(fp))
   if(fread(&book[m],sizeof(BOOK),1,fp))                                   //读出文件的数据
   m++; 
   fclose(fp);
   printf("本人总共有书：%d\n",m);
   printf("图书的类型type：1自然科学类   2小说杂志类  3生活健康类   4音乐艺术类\n");
 /*  for(i=0;i<m;i++)
   {
    printf("输出买书的日期时间：例如11   2   2012\n");
    printf("%4d%4d%4d\n",book[i].date.day,book[i].date.month,book[i].date.year);
    printf("输出书的名字\n");
    printf("  %s\n",book[i].name);
    printf("输出的书的作者\n");
  printf("  %s\n",book[i].author);
  printf("输出书的类型\n");
  printf("  %d\n",book[i].type);
  printf("输出书的价格\n");
  printf("  %d\n",book[i].price);
   }
   printf("\n");
  printf("\n");
  printf("\n");*/ 
   printf("输出想要新建几本图书信息\n");
   scanf("%d",&n);
   i=m;
   while(i<n+m)
   {
     printf("买书的 年  月  日 \n");
     scanf("%d,%d,%d",&book[i].date.day,&book[i].date.month,&book[i].date.year);
     printf("书的名字\n");
     scanf("%s",book[i].name);
     printf("书的作者\n");
     scanf("%s",book[i].author);
     printf("书的类型\n");
     scanf("%d",&book[i].type);
     printf("书的价格\n");  
     scanf("%d",&book[i].price);
     i++; 
     }
  if((fp=fopen("E:\\课程设计\\01.txt","w"))==NULL)                         //文件以写的方式打开
    {
        printf("cannot open file\n");
        exit(0);
    }
  for(i=0;i<n+m;i++)
  {
  if(fwrite(&book[i],sizeof(BOOK),1,fp)!=1)                                //写进文件
  printf("没有写进文件\n");
 
  }
  fclose(fp);
  printf("新建成功");
  printf("\n");
  printf("\n");
  printf("\n");
  select();
} //新建图书文件操作
//对图书的显示  删除  更新  查找 操作
void    edit()
{
  int    i;
  printf("                         ^^^^^^^^^^^^^^^^\n");
  printf("                           6图书信息的插入                       \n");
  printf("                           7图书信息的删除                       \n");
  printf("                           8图书信息的更新                       \n"); 
  printf("                           9查找图书                       \n");    
  printf("                         ^^^^^^^^^^^^^^^^^\n");  
  scanf("%d",&i);
  switch(i)
  {
   case   6:     e_insert();
     system("cls");
      break;
    case   7:    e_delete();
     system("cls");   
      break;
    case   8:    e_update();
     system("cls");  
      break;
  case   9:    search();
     system("cls");
     break;
  default : printf("输入错误程序结束");system("pause");     
  }
} //对图书的显示  删除  更新  查找 操作 
//图书的插入
void      e_insert()
{
  BOOK    book1[200];
  BOOK    n;
  int     j,i;
  int     m=0;
  printf("买书的日   月   年   \n");
    scanf("%d%d%d",&n.date.year,&n.date.month,&n.date.day);
    printf("书的名字\n");
    scanf("%s",n.name);
    printf("书的作者\n");
    scanf("%s",n.author);
    printf("书的类型\n");
    scanf("%d",&n.type);
 printf("书的价格\n");  
    scanf("%d",&n.price);
  FILE   *fp;
  if((fp=fopen("E:\\课程设计\\01.txt","ab+"))==NULL)
  {
    printf("cannot   open   file");
  }
  else 
  {
     while(!feof(fp))
     if(fread(&book1[m],sizeof(BOOK),1,fp))
     m++;
     m=m+1;                                                                   //插入后图书数目加1
     book1[m-1]=n;
   for(j=0;i<m;j++)                                      
   for(i=0;i<m;i++)                                                      //进行排序按日期
   {
    if(book1[i].date.year<book1[i+1].date.year)
    swatch(&book1[i],&book1[i+1]);
    else  if((book1[i].date.year=book1[i+1].date.year)&&(book1[i].date.month<book1[i+1].date.month))
    swatch(&book1[i],&book1[i+1]);
    else   if((book1[i].date.year=book1[i+1].date.year)&&(book1[i].date.month=book1[i+1].date.month)&&(book1[i].date.day<book1[i+1].date.day))
    swatch(&book1[i],&book1[i+1]);
    }
    if((fp=fopen("E:\\课程设计\\01.txt","wb"))==NULL)
   {
     printf("cannot   open   file");
   }
   for(i=0;i<m;i++)
   {
     fwrite(&book1[i],sizeof(BOOK),1,fp); 
   }
/*   printf("插入后的所有书籍为\n");
    for(j=0;j<m;j++)
   {
   printf("买书的日   月   年   \n");
     printf("%4d%4d%4d   \n",book1[j].date.day,book1[j].date.month,book1[j].date.year);
     printf("书的名字\n");
        printf("%s",book1[j].name);
  printf("书的作者\n");
  printf("%s",book1[j].author);
  printf("书的类型\n");
  printf("%d",book1[j].type);
  printf("书的价格\n");
   printf("%d",book1[j].price);
  }*/
  printf("插入成功");
 fclose(fp);
  }
    printf("\n");
    printf("\n");
    printf("\n");
    select();
}
void   e_delete()                                                     //图书的删除
{
  BOOK    book1[200];
  int     i,j,m;
  char    n[20];
  i=m=0;
  FILE   *fp;
  if((fp=fopen("E:\\课程设计\\01.txt","rb"))==NULL)
 {
    printf("cannot   open   file");
  }
    while(!feof(fp))
    if(fread(&book1[m],sizeof(BOOK),1,fp))
    m++;
     fclose(fp);
   printf("要删除的书籍名称：\n");
    scanf("%s",n);    
  for(i=0;i<m;i++)
       {
          if(strcmp(book1[i].name,n)==0)
            {
                j++;
                break;                    
            }         
       }
    if(j==0)
    {
     printf("没有找到此书\n");
    }
    for(j=i;j<m;j++)
    book1[j]=book1[j+1];
    m=m-1;                                                                //图书数目减1
   if((fp=fopen("E:\\课程设计\\01.txt","wb"))==NULL)
   {
    printf("cannot   open   file");
   }
  for(i=0;i<m;i++)
     {
      if(fwrite(&book1[i],sizeof(BOOK),1,fp)!=1)
      printf("没有写进文件\n");
 
    }
  

    printf("\n");
   printf("\n");
   printf("\n");
   select();
}
void    e_update()                                                      //图书的更新
{
  BOOK    book1[200];
  int     j,m,n,i;
  char    q[20];
  m=i=n=0;
  printf("请输入要更新书的名称\n");
  scanf("%s",q);
  FILE  *fp;
  if((fp=fopen("E:\\课程设计\\01.txt","ab+"))==NULL)
 {
    printf("cannot   open   file\n");

  }
  else
  {
    while(!feof(fp))
     if(fread(&book1[m],sizeof(BOOK),1,fp))
     m++;
   while(n!=book1[i].type)
   {
     i++;
  
   }
   j=i;
 }
   printf("请输入要更改的书的相关信息\n");
   printf("输出买书的日期时间：例如11   2   2012\n");
  scanf("%d%d%d",&book1[j].date.day,&book1[j].date.month,&book1[j].date.year);
     printf("书的名字\n");
  scanf("%s",book1[j].name);
  printf("书的作者\n");
   scanf("%s",book1[j].author);
   printf("书的类型\n");
   scanf("%d",&book1[j].type);
   printf("书的价格\n");
   scanf("%d",&book1[j].price);
     if((fp=fopen("E:\\课程设计\\01.txt","wb"))==NULL)
  {
     printf("cannot   open   file\n");
   }
    for(i=0;i<n+m;i++)
    {
     if(fwrite(&book1[i],sizeof(BOOK),1,fp)!=1)
     printf("没有写进文件\n");
    }
   printf("更新成功");
     printf("\n");
 printf("\n");
 printf("\n");
 select();
 
}
void    display()                                                     //图书的显示
{
  printf("本人的所有图书：\n");
     printf("\n");
  printf("\n");
  printf("\n");
 
  FILE  *fp;
  BOOK    book1[200];
  int     j,i,m;
  m=i=0;
  if((fp=fopen("E:\\课程设计\\01.txt","rb"))==NULL)
  {
    printf("cannot   open   file\n");
  }
   while(!feof(fp))
     if(fread(&book1[m],sizeof(BOOK),1,fp))
     m++;
  
  for(i=0;i<m;i++)
  {
   printf("买书的日   月   年   \n");
     printf("%d   %d   %d   \n",book1[i].date.day,book1[i].date.month,book1[i].date.year);
     printf("书的名字\n");
     printf("%s\n",book1[i].name);
  printf("书的作者\n");
  printf("%s\n",book1[i].author);
  printf("书的类型\n");
  printf("%d\n",book1[i].type);
  printf("书的价格\n");
   printf("%d\n",book1[i].price);
    printf("\n");
  printf("\n");
  printf("\n");
  }  
  printf("显示成功\n");
   printf("\n");
   printf("\n");
   printf("\n");
   select();
}
void      sort()                                                                   //排序
{
 FILE   *fp;
 BOOK    book1[200];
  int     j,s,i;
  int     m=0;
  if((fp=fopen("E:\\课程设计\\01.txt","rb"))==NULL)
  {
    printf("cannot   open   file\n");

   }
  else
  {
 while(!feof(fp))
   if(fread(&book1[m],sizeof(BOOK),1,fp))
    m++;
  }
  for(j=0;i<m;j++)
   for(i=0;i<m;i++)
   {
    if(book1[i].date.year<book1[i+1].date.year)
    swatch(&book1[i],&book1[i+1]);
    else  if((book1[i].date.year=book1[i+1].date.year)&&(book1[i].date.month<book1[i+1].date.month))
    swatch(&book1[i],&book1[i+1]);
    else   if((book1[i].date.year=book1[i+1].date.year)&&(book1[i].date.month=book1[i+1].date.month)&&(book1[i].date.day<book1[i+1].date.day))
    swatch(&book1[i],&book1[i+1]);
    }
   printf("输出排序后的图书为：\n");
   printf("\n");
  printf("\n");
  printf("\n");
   for(i=0;i<m;i++)
   {
    printf("输出买书的日期时间：例如11   2   2012\n");
    printf("%4d%4d%4d   \n",book1[i].date.day,book1[i].date.month,book1[i].date.year);
    printf("输出书的名字\n");
    printf("%s\n",book1[i].name);
    printf("输出的书的作者\n");
  printf("%s\n",book1[i].author);
  printf("输出书的类型\n");
  printf("%d\n",book1[i].type);
  printf("输出书的价格\n");
  printf("%d\n",book1[i].price);
     printf("\n");
   printf("\n");
   printf("\n");
   }
   printf("\n");
   printf("\n");
   printf("\n");
   printf("排序成功\n");
  
   select();
}

void      all()                                           //图书信息的整理
{
 FILE    *fp;
  BOOK    book1[200];
  int     i,a,b,c,d,m;
  a=b=c=d=m=0;
    if ((fp = fopen("E:\\课程设计\\01.txt", "r")) == NULL) /*以只读方式打开指定文件*/
    {
        printf("cannot open file\n");
        exit(0);
    }
    while(!feof(fp))
    if(fread(&book1[m], sizeof( BOOK), 1, fp)==1)
       m++;
    fclose(fp);
    for(i=0;i<m;i++)
  {
   if(book1[i].type==1)
   {
    a++;
   }
   else   if(book1[i].type==2)
   b++;
   else   if(book1[i].type==3)
   c++;
   else   if(book1[i].type==4)
   d++;
  }
  printf("总共有书：%d\n",m);
  printf("本人的图书有：\n");
  printf("1自然科学类: %d\n",a);
  printf("2小说杂志类：%d\n",b);
  printf("3生活健康类：%d\n",c);
  printf("4音乐艺术类：%d\n",d);
  printf("\n");
  printf("\n");
  printf("\n");
  printf("图书信息整理成功\n");
  select();
}
void   search()
{
 FILE    *fp;
  BOOK    book1[200];
  int     i,m;
  char    n[20];
  printf("想要查找的书名");
  scanf("%s",n);
 if((fp=fopen("E:\\课程设计\\01.txt","rb"))==NULL)
  {
    printf("cannot   open   file\n");

  }
  else
  {
    while(!feof(fp))
     if(fread(&book1[m],sizeof(BOOK),1,fp))
     m++;
  } 
  for(i=0;i<m;i++)
  {
   if(strcmp(n,book1[i].name)==0)
   break;
  }
  printf("查找成功");
 printf("输出所查找图书的信息");
  printf("\n");
  printf("\n");
  printf("\n");
 printf("输出买书的日期时间：例如11   2   2012\n");
 printf("%d   %d   %d       \n",book1[i].date.day,book1[i].date.month,book1[i].date.year);
 printf("输出书的名字\n");
 printf("%s\n",book1[i].name);
 printf("输出的书的作者\n");
 printf("%s\n",book1[i].author);
 printf("输出书的类型\n");
 printf("%d\n",book1[i].type);
 printf("输出书的价格\n");
 printf("%d\n",book1[i].price);
  printf("\n");
 printf("\n");
 printf("\n");
 select();
}


