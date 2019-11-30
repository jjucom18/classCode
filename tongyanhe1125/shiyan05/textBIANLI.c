#include <stdio.h>
#include <malloc.h>
#define MaxSize 100

typedef char dataType;
typedef struct TreeNode{
    dataType data;
    struct TreeNode *left, *right;
}TreeNode;

void CreateTree(struct TreeNode *t,dataType  x){
    dataType d;
    scanf("%c,&d");
    if(d == x){
        t == NULL;
    }
    else {
        t = (TreeNode *)malloc(sizeof(TreeNode));
        t->data = d;
        CreateTree(t->left, x);
        CreateTree(t->right, x);
    }
}

void PreOrder(TreeNode *t){
    if (t){
        printf("%c",t->data);
        PreOrder(t->left);
        PreOrder(t->right);
    }
}

void InOrder(TreeNode *t){
    if(t){
        InOrder(t->left);
        printf("%c",t->data);
        InOrder(t->right);
    }
}

void PostOrder(TreeNode *t){
    if(t){
        PostOrder(t->left);
        PostOrder(t->right);
        printf("%c",t->data);
    }
}

void LevelOrder(TreeNode  *t){
    TreeNode *q[MaxSize];
    int front=0, rear=0;
    TreeNode *p;
    if(t == NULL)  return;
    q[rear] = t;
    rear = (rear+1) % MaxSize;
    while (front != rear){
        p = q[front];
        front = (front+1) % MaxSize;
        printf("%c",p->data);
        if(p->left){
            q[rear] = p->left;
            rear = (rear+1)% MaxSize;
        }
        if(p->right){
            q[rear] = p->right;
            rear = (rear+1) % MaxSize;
        }
    }    
}

int main (int argc,char **argv){
    TreeNode *t;
    printf("input:");
    printf("like:ABD#G###CE##F##\n");
    CreateTree(&t,'#');
    printf("First:");
    PreOrder(t);
    printf("second:");
    InOrder(t);
    printf("\n");
    printf("Last:");
    PostOrder(t);
    printf("\n");
    printf(":");
    LevelOrder(t);
    printf("\n");
}
