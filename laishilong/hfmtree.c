#include <math.h>
#include <stdio.h>
#include <time.h>
#include<string.h> 
#define MAX 200 

typedef struct{ 
    char data;
    int weight; 
    int parent;
    int lchild; 
    int rchild; 
  }huffmannode;

typedef struct{ 
    char bits[50];
    int start;
  }huffmancode ;

void main() {
     huffmannode ht[100]; 
     huffmancode cd[100];
    char string[100]; 
    char hcd[100];
    int i,j,x,y,s1,s2,m1,m2,n,c,f,k;
    printf("请输入字符个数n="); 
    scanf("%d",&n);

for(i=0;i<n;i++) {
    getchar(); 
    printf("请输入第%d字符变量和权值大小:",i+1);
    scanf("%c %d",&ht[i].data,&ht[i].weight);
}

for(i=0;i<2*n-1;i++) {
     ht[i].parent=ht[i].lchild=ht[i].rchild=0; 
}

for (i=n;i<2*n-1;i++) {
     s1=s2=0; 
     m1=m2=MAX;

for (j=0;j<i;j++) {

if (ht[j].weight<m1 &&ht[j].parent==0) {
     m2=m1;
     s2=s1;
     m1=ht[j].weight;
     s1=j; 
}

else if(ht[j].weight<m2 &&ht[j].parent==0 ) {
     m2=ht[j].weight;
     s2=j;
   } 
}

   ht[s1].parent=i; 
   ht[s2].parent=i;
   ht[i].weight=m1+m2; 
   ht[i].lchild=s1; 
   ht[i].rchild=s2; 
}

for(i=0;i<n;i++) {
     cd[i].start=n;
     cd[i].bits[cd[i].start]='\0';

for(c=i,f=ht[i].parent;f!=0;c=f,f=ht[f].parent)

if(ht[f].lchild==c) cd[i].bits[--cd[i].start]='0';

else cd[i].bits[--cd[i].start]='1';
}
    printf("\n输出哈夫曼译码:\n");

for (i=0;i<n;i++) {
    printf("%c:",ht[i].data); 

for(j=cd[i].start;j<=n;j++) {
    printf("%c",cd[i].bits[j]); 
}
    printf("\n");
}
    printf("\n请输入字符串信息:\n");
    scanf("%s",string); 

for(i=0;string[i]!='\0';i++) {

for(c=0;c<=n;c++)

if(string[i]==ht[c].data) {

for(j=cd[c].start;j<=n;j++)
    printf("%c",cd[c].bits[j]); 

break;
     }
}
    printf("请输入哈夫曼译码:\n");
    scanf("%s",hcd); 
       f=2*n-2;

for(i=0;hcd[i]!='\0';i++) {

if(hcd[i]=='0') 
       f=ht[f].lchild;
else if(hcd[i]=='1')
       f=ht[f].rchild; 
if(f<n) {
    printf("%c",ht[f].data); 
       f=2*n-2;
     }
}
    printf("\n");
}


