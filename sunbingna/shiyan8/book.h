#ifndef _BOOK_H
#define _BOOK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>
#define AVAILABLE 0
#define UNAVAILABLE 1
#define MAXNAME 30

typedef struct book
{
    char *name;
    int id;
    int count;
    int status;
    struct book *next;
}Book;


int viewbook();               // 查看图书
int addbook();                // 添加图书
int modbook();                // 修改图书
int choice();
int delbook();                // 删除图书
void printbook(Book *);       // 打印图书
Book *lookup(char *, int);    // 搜索图书


#endif