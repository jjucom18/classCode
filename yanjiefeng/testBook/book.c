#include "book.h"

void   Interface();                                                            
void   f_new();                                                               
void   edit();                                                            
void   e_insert();                                                     
void   e_delete();                                                      
void   e_update();                                                        
void   display();                                                      
void   sort();                                                          
void   all();                                                               
void   search();                                                            
void    swatch(BOOK  *p,BOOK  *q);                                          
void    select()                                                            
{
system("cls");
Interface();break;

}    
//选择函数
void swatch(BOOK  *p,BOOK  *q)
{
 BOOK temp;
 temp=*p;
 *p=*q;
 *p=temp;
}
//主界面
void Interface()
{
   int i;
   printf("\n");
   printf("\n");
   printf("\n"); 
   printf("\n");
   printf("                       ****************************** \n");
   printf("                       *    个人图书管理系统        * \n");
   printf("                       *      1新建文件操作         * \n");
   printf("                       *      2编辑图书信息         * \n");
   printf("                       *      3显示图书信息         * \n");
   printf("                       *      4图书排序             * \n");
   printf("                       *      5统计图书             * \n");
   printf("                       ****************************** \n");
   printf("                          请选择你要执行的操作\n");
   scanf("%d",&i);
   switch(i)
   {
   case  1:  f_new();   system("cls");    break;
   case  2:  edit();    system("cls");    break;
   case  3:  display(); system("cls");    break;
   case  4:  sort();    system("cls");    break;
   case  5:  all();system("cls");  break;
   default:  printf("请输入1~5\n");system("pause"); 
  }
}
//新建图书文件操作
void f_new()
{
   int n,i;
   int m=0;
   FILE*fp;
   if((fp=fopen("C:\Users\01.txt","a+"))==NULL)          //打开文件
   {
    printf("cannot  open   01.txt\n"); 
   }
   while(!feof(fp))
   if(fread(&book[m],sizeof(BOOK),1,fp))              
   m++; 
   fclose(fp);
   printf("图书数目：%d\n",m);
   scanf("%d",&n);
   i=m;
   while(i<n+m)
   {
     printf("购买日期\n");
     scanf("%d,%d,%d",&book[i].date.day,&book[i].date.month,&book[i].date.year);
     printf("书名\n");
     scanf("%s",book[i].name);
     printf("ISBN\n");
     scanf("%s",book[i].isbn);
     printf("作者\n");
     scanf("%s",book[i].author);
     printf("isbn\n");
     scanf("%d",&book[i].type);
     printf("价格\n");  
     scanf("%d",&book[i].price);
     i++; 
     }
//打开文件  
if((fp=fopen("C:\Users\01.txt","w"))==NULL)            
    {
        printf("cannot open file\n");
        exit(0);
    }
  for(i=0;i<n+m;i++)
  {
//写进文件  
if(fwrite(&book[i],sizeof(BOOK),1,fp)!=1)             
  printf("没有写进文件\n"); 
  }
  fclose(fp);
  printf("新建成功");
  printf("\n");
  printf("\n");
  printf("\n");
  select();
}
//图书显示  删除  更新  查找 操作
void edit()
{
  int i;
  printf("                       ****************************** \n");
  printf("                       *      6插入图书             * \n");
  printf("                       *      7删除图书             * \n");
  printf("                       *      8更新图书             * \n"); 
  printf("                       *      9查找图书             * \n");    
  printf("                       ****************************** \n");  
  scanf("%d",&i);
  switch(i)
  {
    case 6:e_insert();
     system("cls");
      break;
    case 7:e_delete();
     system("cls");   
      break;
    case 8:e_update();
     system("cls");  
      break;
    case 9:search();
     system("cls");
     break;
  default : printf("请输入6~9");system("pause");     
  }
}
//插入图书
void e_insert()
{
  BOOK book1[200];
  BOOK n;
  int j,i;
  int m=0;
    printf("购书日期\n");
    scanf("%d%d%d",&n.date.year,&n.date.month,&n.date.day);
    printf("书名\n");
    scanf("%s",n.name);
    printf("作者\n");
    scanf("%s",n.author);
    printf("isbn\n");
    scanf("%d",&n.type);
    printf("价格\n");  
    scanf("%d",&n.price);
  FILE *fp;
  if((fp=fopen("C:\Users\01.txt","ab+"))==NULL)
  {
    printf("cannot open file");
  }
  else 
  {
     while(!feof(fp))
     if(fread(&book1[m],sizeof(BOOK),1,fp))
     m++;
     m=m+1;                               //插入后图书数目加1
     book1[m-1]=n;
   for(j=0;i<m;j++)                                      
   for(i=0;i<m;i++)                       //按日期进行排序
   {
    if(book1[i].date.year<book1[i+1].date.year)
    swatch(&book1[i],&book1[i+1]);
    else if((book1[i].date.year=book1[i+1].date.year)&&(book1[i].date.month<book1[i+1].date.month))
    swatch(&book1[i],&book1[i+1]);
    else if((book1[i].date.year=book1[i+1].date.year)&&(book1[i].date.month=book1[i+1].date.month)&&(book1[i].date.day<book1[i+1].date.day))
    swatch(&book1[i],&book1[i+1]);
    }
    if((fp=fopen("C:\Users\01.txt","wb"))==NULL)
   {
     printf("cannot open file");
   }
   for(i=0;i<m;i++)
   {
     fwrite(&book1[i],sizeof(BOOK),1,fp); 
   }
    printf("插入后的所有书籍为\n");
    for(j=0;j<m;j++)
   {
  printf("购书日期\n");
  printf("%4d%4d%4d   \n",book1[j].date.day,book1[j].date.month,book1[j].date.year);
  printf("书名\n");
  printf("%s",book1[j].name);
  printf("作者\n");
  printf("%s",book1[j].author);
  printf("isbn\n");
  printf("%d",book1[j].type);
  printf("价格\n");
  printf("%d",book1[j].price);
  }
  printf("插入成功");
 fclose(fp);
  }
    printf("\n");
    printf("\n");
    printf("\n");
    select();
}
//显示图书
void display()                 
{
  printf("本人的所有图书：\n");
  printf("\n");
  printf("\n");
  printf("\n");
  FILE *fp;
  BOOK book1[200];
  int j,i,m;
  m=i=0;
  if((fp=fopen("C:\Users\01.txt","rb"))==NULL)
  {
    printf("cannot open file\n");
  }
   while(!feof(fp))
     if(fread(&book1[m],sizeof(BOOK),1,fp))
     m++;  
  for(i=0;i<m;i++)
  {
   printf("购书日期\n");
   printf("%d   %d   %d   \n",book1[i].date.day,book1[i].date.month,book1[i].date.year);
   printf("书名\n");
   printf("%s\n",book1[i].name);
   printf("作者\n");
   printf("%s\n",book1[i].author);
   printf("isbn\n");
   printf("%d\n",book1[i].type);
   printf("价格\n");
   printf("%d\n",book1[i].price);
   printf("\n");
   printf("\n");
   printf("\n");
  }  
}
//排序
void sort()                                                                   
{
 FILE *fp;
 BOOK book1[200];
  int j,s,i;
  int m=0;
  if((fp=fopen("C:\Users\01.txt","rb"))==NULL)
  {
    printf("cannot open file\n");
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
    printf("购书日期\n");
    printf("%4d%4d%4d   \n",book1[i].date.day,book1[i].date.month,book1[i].date.year);
    printf("书名\n");
    printf("%s\n",book1[i].name);
    printf("作者\n");
    printf("%s\n",book1[i].author);
    printf("isbn\n");
    printf("%d\n",book1[i].type);
    printf("价格\n");
    printf("%d\n",book1[i].price);
    printf("\n");
    printf("\n");
    printf("\n");
    }
   select();
}
//图书统计
void all()                                           
{
 FILE *fp;
  BOOK book1[200];
  int i,a,b,c,d,m;
  a=b=c=d=m=0;
    if ((fp = fopen("C:\Users\01.txt","r")) == NULL) 
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
   else if(book1[i].type==2)
   b++;
   else if(book1[i].type==3)
   c++;
   else if(book1[i].type==4)
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
}
图书查找
void search()
{
 FILE *fp;
  BOOK book1[200];
  int i,m;
  char n[20];
  printf("想要查找的书名");
  scanf("%s",n);
 if((fp=fopen("C:\Users\01.txt","rb"))==NULL)
  {
    printf("cannot open file\n");
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
 printf("购书日期\n");
 printf("%d   %d   %d       \n",book1[i].date.day,book1[i].date.month,book1[i].date.year);
 printf("书名\n");
 printf("%s\n",book1[i].name);
 printf("作者\n");
 printf("%s\n",book1[i].author);
 printf("isbn\n");
 printf("%d\n",book1[i].type);
 printf("价格\n");
 printf("%d\n",book1[i].price);
 select();
}
