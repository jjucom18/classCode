#include<stdio.h>
#include<stdlib.h>
typedef char DataType;
#define MAXNUM 50
typedef struct{
	DataType data;
	int weight;
	int parent;
	int left;
	int right;
}HuffNode;

int HuffNodeCreate(HuffNode *ht) {
	int i,k,n,m1,m2,p1,p2;
	printf("请输入元素个数:");
	scanf("%d",&n);
	for(i=1;1<=n;i++) {
		getchar();
		printf("第%d个元素的=>\n\t 节点值：",i);
		scanf("%c",&ht[i].data);
		printf("\t权 重：");
		scanf("%d",&ht[i].weight);
	}
	for(i=1;i<=2*n-1;i++)
		ht[i].parent=ht[i].left=ht[i].right=0;
	for(i=n+1;i<=2*n-1;i++) {
		m1=m2=32767;
		p1=p2=1;
		for(k=1;k<=i-1;k++)
			if(ht[k].weight<m1) {
				m2=m1;
				p2=p1;
				m1=ht[k].weight;
				p1=k;
			}else if(ht[k].weight<m2) {
				m2=ht[k].weight;
				p2=k;
			}
		ht[p1].parent=i;
		ht[p2].parent=i;
		ht[i].weight=m1+m2;
		ht[i].left=p1;
		ht[i].right=p2;
	}
	printf("哈夫曼树以成功建立！\n");
	return n;
}

int main(int argc,char *argv[]) {
	int n,select,flag=0;
	HuffNode ht[2*MAXNUM];
	while(1) {
		printf("\t 请选择您所要实现的功能：\n");
		printf("\t1---建立哈夫曼树\n");
		printf("\t2---退出系统\n");
		scanf("%d",&select);
		if(select!=1 && select!=2 && flag==0) {
			printf("请先建立哈夫曼树再选择其他功能！\n");
			continue;
		}
	flag=1;
	switch(select) {
		case 1:
			n=HuffNodeCreate(ht);
			   break;
		case 2:
			   exit(0);
	  }
   } 
}
