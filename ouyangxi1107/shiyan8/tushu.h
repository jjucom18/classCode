#ifndef tushu_h
#define tushu_h
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<string.h>

typedef struct
{
 int year, month,day;       
}DATE;
 
typedef struct book
{
  DATE date;                                                        //购买日期 
  char name[20];                                                    //书名
  char author[8];                                                   //作者
  int type;                                                         //书籍类别编号
  int price;                                                        //价格 
}BOOK;
BOOK book[200];

#endif
