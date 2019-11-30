#include<stdio.h>
#include<malloc.h>
 
/*
 
  这个程序主要是用来实现建立哈夫曼，以及遍历哈夫曼,
  关于哈夫曼建立的原理，以及应用请参考《大话数据结构》第200页，6.12 赫夫曼树以及应用
  1 背景假设有一串英文字符
    "ABBCCCCDDDDDDEEEEEEEEFFFFFFFFFGGGGGGGGGGHHHHHHHHHHH"
    从这里看每个字符频率出现都不一样,用哈夫曼来进行优化,其中次数分别为:
    A : 1 , B : 2 , C : 4,D : 6,E : 8,F : 9,G : 10 ,H : 11
*/
 
 
 
//定义哈夫曼结构体
typedef struct HaFuManTree{
  char letter; //字母
  int number ; //出现次数
  int used; //是否用过
  struct HaFuManTree *pLeft ;//左孩子
  struct HaFuManTree *pRight ;//右孩子
  struct HaFuManTree *next; //下一个节点
}HaFuManTree ,*PHaFuManTree;
 
//函数申明
PHaFuManTree add(PHaFuManTree pNode2,PHaFuManTree newNode);
PHaFuManTree initHanFuMan(PHaFuManTree pNode);
PHaFuManTree getSmalleast(PHaFuManTree pNode);
void inorderTraversal(PHaFuManTree pNode);
PHaFuManTree ininLinked();
 
int main(){
printf("初始化链表\n");
PHaFuManTree pNode = ininLinked();
 
printf("初始化哈夫曼树\n");
pNode = initHanFuMan(pNode);
 
printf("中序遍历哈夫曼树\n");
inorderTraversal(pNode);
 
return 1;
}
 
//初始化单链表
PHaFuManTree ininLinked(){
int A =1,B=2,C=4,D=6,E=8,F=9,G=10,H=11;
PHaFuManTree pHead =  (HaFuManTree *)malloc(sizeof(HaFuManTree)*1);
pHead->next = NULL;
PHaFuManTree pTail = pHead;
 
PHaFuManTree nodeA =  (HaFuManTree *)malloc(sizeof(HaFuManTree)*1);
nodeA->letter = 'A';
nodeA->number = A;
nodeA->used = 0;
nodeA->pLeft = NULL;
nodeA->pRight = NULL;
pTail->next = nodeA;
pTail = nodeA;
 
PHaFuManTree nodeB =  (HaFuManTree *)malloc(sizeof(HaFuManTree)*1);
nodeB->letter = 'B';
nodeB->number = B;
nodeB->used = 0;
nodeB->pLeft = NULL;
nodeB->pRight = NULL;
nodeB->next = NULL;
pTail->next = nodeB;
pTail = nodeB;
 
PHaFuManTree nodeC =  (HaFuManTree *)malloc(sizeof(HaFuManTree)*1);
nodeC->letter = 'C';
nodeC->number = C;
nodeC->used = 0;
nodeC->pLeft = NULL;
nodeC->pRight = NULL;
nodeC->next = NULL;
pTail->next = nodeC;
pTail = nodeC;
 
PHaFuManTree nodeD =  (HaFuManTree *)malloc(sizeof(HaFuManTree)*1);
nodeD->letter = 'D';
nodeD->number = D;
nodeD->used = 0;
nodeD->pLeft = NULL;
nodeD->pRight = NULL;
nodeD->next = NULL;
pTail->next = nodeD;
pTail = nodeD;
 
PHaFuManTree nodeE =  (HaFuManTree *)malloc(sizeof(HaFuManTree)*1);
nodeE->letter = 'E';
nodeE->number = E;
nodeE->used = 0;
nodeE->pLeft = NULL;
nodeE->pRight = NULL;
nodeE->next = NULL;
pTail->next = nodeE;
pTail = nodeE;
 
PHaFuManTree nodeF =  (HaFuManTree *)malloc(sizeof(HaFuManTree)*1);
nodeF->letter = 'F';
nodeF->number = F;
nodeF->used = 0;
nodeF->pLeft = NULL;
nodeF->pRight = NULL;
nodeF->next = NULL;
pTail->next = nodeF;
pTail = nodeF;
 
PHaFuManTree nodeG =  (HaFuManTree *)malloc(sizeof(HaFuManTree)*1);
nodeG->letter = 'G';
nodeG->number = G;
nodeG->used = 0;
nodeG->pLeft = NULL;
nodeG->pRight = NULL;
nodeG->next = NULL;
pTail->next = nodeG;
pTail = nodeG;
 
PHaFuManTree nodeH =  (HaFuManTree *)malloc(sizeof(HaFuManTree)*1);
nodeH->letter = 'H';
nodeH->number = H;
nodeH->used = 0;
nodeH->pLeft = NULL;
nodeH->pRight = NULL;
nodeH->next = NULL;
pTail->next = nodeH;
pTail = nodeH;
return pHead;
 
};
//在链表后面添加元素
PHaFuManTree add(PHaFuManTree pNode2,PHaFuManTree newNode){
 PHaFuManTree pNode = pNode2;
 while(pNode->next != NULL){
      pNode = pNode->next;
 }
 pNode->next = newNode;
 return pNode2;
};
 
//初始化哈夫曼树
PHaFuManTree initHanFuMan(PHaFuManTree pNode){
 
    // 1 从链表中取出两个最小的元素 small_1 ,small_2;
      PHaFuManTree small_1 = getSmalleast(pNode);
   // 2 如果small_1为NULL,结束程序.
      if(!small_1){
        printf("哈夫曼树为NULL,程序退出");
        exit(1);
     }else{
   // 3 如果small_1不为NULL,small_2为NULL,结束递归
       small_1->used = 1;
       PHaFuManTree small_2 = getSmalleast(pNode);
       if(!small_2){
        return small_1;
    }else{
   // 4 如果small_1,small_2都不为NULL,循环递归.
      //4.1 将small_2标志为已用
       small_2->used = 1 ;
      //4.2 创建一个新节点 newNode
        PHaFuManTree newNode =  (HaFuManTree *)malloc(sizeof(HaFuManTree)*1);
        newNode->used = 0;
        newNode->letter = 'N';
        newNode->pLeft = NULL;
        newNode->pRight = NULL;
        newNode->next = NULL;
        newNode->number = NULL;
      //4.3 将newNode指向small_1,small_2
        if(small_1->number < small_2->number){
          newNode->pLeft = small_1;
          newNode->pRight = small_2;
        }else{
          newNode->pLeft = small_2;
          newNode->pRight = small_1;
        }
        newNode->number = small_1->number + small_2->number;
     //4.4 将newNode加入到链表的尾部
        pNode = add(pNode,newNode);
     //4.5再次递归
        initHanFuMan(pNode);
       }
     }
 
 
};
//得到链表中最小元素
PHaFuManTree getSmalleast(PHaFuManTree pNode){
    pNode = pNode->next;
    while(pNode!=NULL && pNode->used){
        pNode = pNode->next;
    };
    if(pNode != NULL){
      PHaFuManTree small = pNode;
      pNode = pNode->next;
       while(pNode != NULL){
          if(small->number > pNode->number  && !pNode->used){
            small = pNode;
          }
          pNode = pNode->next;
      };
     return small;
    }else{
    return NULL;
    }
 
};
//中序遍历哈夫曼树
 void inorderTraversal(PHaFuManTree pNode){
    if(pNode == NULL) return;
     if(pNode->pLeft != NULL){
       inorderTraversal(pNode->pLeft);
     };
    if(pNode->pLeft == NULL && pNode->pRight == NULL){
        printf("letter = %c , number = %d\n",pNode->letter,pNode->number);
    }
    if(pNode->pRight != NULL){
      inorderTraversal(pNode->pRight );
     };
 
 };

