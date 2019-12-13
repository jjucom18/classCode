#include<stdio.h>
#include<stdlib.h> 
#include<conio.h>

struct BOOK
{
int id,usr[10],total,store,days[10];
char name[31],author[21];
}books[100];
/*上面是结构体的定义，用于存放书籍及借书的信息。*/

void page_title(char *menu_item)
{
clrscr();
printf(">>> 图 书 管 理 系 统 <<<\n\n- %s -\n\n",menu_item);
}

void return_confirm(void)
{
printf("\n按任意键返回……\n");
getch();
}
/*上面是返回前请求确认的函数，以便在返回前观察结果*/

int search_book(void)
{
int n,i;
printf("请输入图书序号:");
scanf("%d",&i);
for(n=0;n<100;n++)
{
if(books[n].id==i)
{
printf("书名:%s\n",books[n].name);
printf("作者:%s\n",books[n].author);

