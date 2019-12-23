#ifndef chaoshi_h
#define chaoshi_h
 
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
 
 
#define MAXSIZE 100
 
typedef struct                         //数据域定义为一个结构体
{
    char name[30];                     //商品名称
    char no[30];                       //商品编号
    int  num;                          //商品数量
}goods;                                //商品结构体
 
typedef struct node                    //定义单链表节点类型
{
    goods data;                        //数据域
    struct node *next;                 //指针域，指向后继结点
}LNode;
 
LNode *Init_G();                       //初始化链表
void input(LNode *L);                  //创建链表（尾插法）
void run_over(LNode *L);               //浏览商品信息
LNode* search(LNode *L,goods x);       //查找商品
void goodspai(LNode *L);               //商品信息排序
void insert(LNode *L,goods x);         //插入商品
void storage(LNode *L,goods x);        //商品入库
void goodsChange(LNode *L,goods x);    //以商品编号进行修改
int del(LNode *L,goods x);             //删除
void out(LNode *L,goods x);            //商品出库
void save(LNode *L);                   //保存操作
void menu();                           //功能选择窗口  
 
 
 
#endif 
