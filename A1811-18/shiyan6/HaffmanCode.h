#ifndef HaffmanCode_h
#define HaffmanCode_h
#include<stdio.h>                                                                                                 
#define n 8                                        //叶子结点数目
#define m (2*n-1)                                  //总结点数目，可证明
#define MAXVALUE 10000                             //最大权值
#define MAXBIT 20                                  //哈夫曼编码最大长度
 typedef struct                                     
   {
        char ch;
		int weight;                                    
		int parent;        
		int Lchild, Rchild;
}Htreetype;
typedef struct
 {
     int bit[n];                                   //位串
     int start;                                    //编码在位串中的起始位置
     char ch;
}Hcodetype;


#endif
