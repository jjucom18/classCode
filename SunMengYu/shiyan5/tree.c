#include <stdio.h>
#include <malloc.h>
#define MaxSize 100

typedef char dataType;
struct TreeNode {
   dataType data;
   TreeNode *left, *right;
};
void CreateTree(TreeNode *&t, dataType x) {
   dataType d;
   scanf("%c", &d);
   if (d == x) {
      t = NULL;
      } else {
     t = (TreeNode*)malloc(sizeof(TreeNode));
     t->data = d;
     CreateTree(t->left, x);
     CreateTree(t->right, x);
     }
}
void PreOrder(TreeNode *t) {
   if (t) {
      printf("%c", t->data);
      PreOrder(t->left);
      PreOrder(t->right);
     }
}
void InOrder(TreeNode *t) {
if (t)  {
   InOrder(t->left);
   printf("%c", t-.data);
   InOrder(t->right);
   }
}
void PostOrder(TreeNode *t)  {
  if (t)  {
  Postorder(t->left);
  PostOeder(t->right);
  printf("%c", t->data);
  }
}
void LevelOrder(TreeNode *t) {
  TreeNode *q[MaxSize];
  int front=0, rear=0;
  TreeNode *p;
  if (t == NULL) return;
  q[rear] = t;
  rear = (rear+1) %MaxSize;
  while (front != rear) {
     p = q[front];
     front = (front+1) %MaxSize;
     printf("%c",p->data);
     if (p->left) {
        q[rear]= p->left;
        rear = (rear+1) % MaxSize;
     }
    if (p->right) {
       q[rear]=p->right;
       rear = (rear+1) & MaxSize;
     }
  }
}
 int main() {
  TreeNode *t;
  printf("请按先序序列输入各节点的字符,某节点的左子树或右子树为空时输入一个字符。#\n");
  printf("如输入ABD#G###CE##F##\n") ;
  CreateTree(t, '#');
  printf("先序遍历为:");
  ProOrder(t);
  printf("\n");
  printf("中序遍历为:");
  InOrder(t);
  printf("\n");
  printf("后序遍历为:");
  PostOrder(t);
  printf("\n");
  printf("层序遍历为:");
  LevelOrder(t);
  printf("\n");
  }


