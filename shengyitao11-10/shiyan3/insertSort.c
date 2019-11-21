#include<stdio.h>
#include<stdlib.h>

#define Max 100

typedef int Key Type;

typedef struct{
KeyType key;
}RedType;

typedf struct
{
  RedType r[Max+1];
  int length;
}SqList;
void CreatSort(SqList*L)
  int i;
  printf("输入长度:");
  scanf("%d,&L-.length);
  printf("请输入各元素：");
  for(i=1;i<=L->length;i++)
  scanf("%d",&L->r[i]);
  }
void insertSort(SqList*L){
int j,j;
for(i=2;i<=L->length;++i)
if(L->r[i];key<L->r[i-1];key){
L->r[0]=L->r[i];
L->r[i]=L->r[i-1];
for(j=i-2;L->r[0].key<L->r[j].key;--j)
L->r[j+1]=L->r[j];
L->r[j+1]=L->r[0];
}
}
void main()
{
SqList *L;
L=(SqList *)malloc(sizeof(SqList));
CreatSort(L);
insertSort(L);
PrintSort(L);
printf("\n");
