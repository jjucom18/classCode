#include <stdio.h>

#include <stdlib.h>

typedef struct

{

    int weight,parent,lchild,rchild;

} HNode;

void HuffTree(HNode Huff[],int n)

{

    int i,j,m1,m2,x1,x2;   //m1,m2代表的是每次集合中最小的两个权重，x1,x2即为他们的下标.

    for(i=0; i<2*n-1; i++)

    {

        Huff[i].weight=0;

        Huff[i].parent=-1;

        Huff[i].lchild=-1;

        Huff[i].rchild=-1;

    }

    printf("Input 1~n value of leaf:\n");

    for(i=0; i<n; i++)

        scanf("%d",&Huff[i].weight);

    for(i=0; i<n-1; i++)              //这里n-1不是很理解

    {

        m1=m2=32767;

        x1=x2=0;

        for(j=0; j<n+i; j++)

        {

            if(Huff[j].parent==-1 && Huff[j].weight<m1)

            {

                m2=m1;

                x2=x1;

                m1=Huff[j].weight;

                x1=j;

            }

            else if(Huff[j].parent==-1 && Huff[j].weight<m2)

            {

                m2=Huff[j].weight;

                x2=j;

            }

        }

        Huff[x1].parent=n+i;

        Huff[x2].parent=n+i;

        Huff[n+i].weight=Huff[x1].weight+

                            Huff[x2].weight;

        Huff[n+i].lchild=x1;

        Huff[n+i].rchild=x2;

    }

    printf("Huff weight   lchild   rchild   parent\n");

    for(i=0;i<2*n-1;i++)

        printf("%3d%5d%10d%10d%10d\n",i,

                Huff[i].weight,Huff[i].lchild,

                Huff[i].rchild,Huff[i].parent);

}

int main()

{

    HNode Huff[100]={};//空间要足够大，至少要大于2n-1

    HuffTree(Huff,4);

    printf("Hello world!\n");

    return 0;

}
