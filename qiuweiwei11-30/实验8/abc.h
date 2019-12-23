#ifndef abc_h
#define abc_h

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



#endif
