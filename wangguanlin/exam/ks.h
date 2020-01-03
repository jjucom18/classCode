#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include<fstream>
using namespace std;
typedef struct student
{
    int   num;
    char  sex[20];
    char  name[20];
    int   age;
    char  address[20];
    int   type;
}ElemType;
 
typedef struct LNode  //定义单链表节点类型
{
    ElemType data;   //存放元素值
    struct LNode *next;  //指向后继节点
} LinkList;
 
void InitList(LinkList *&L); //初始化线性表
void DestroyList(LinkList *&L); //销毁线性表 释放空间
void CreateListR(LinkList *&L);   // 采用尾插法创建链表  输入信息
void DispList(LinkList *L);  //输出信息
int LocateElem(LinkList *L);//查找信息
int ListDelete(LinkList *&L); //删除信息
int Create(LinkList *&L);//修改信息
void sort(LinkList *&L);    //排序信息
void sumList(LinkList *&L);    //统计信息
void InsertList(LinkList *L);   //插入信息
void Display(LinkList *L);//输出信息
void import(LinkList*&L);//读文件
void save(LinkList*&L);//存文件
void DispListKH(LinkList *L);//输出信息
void ListInsert(LinkList *&L,LinkList *p);//插入新的节点

