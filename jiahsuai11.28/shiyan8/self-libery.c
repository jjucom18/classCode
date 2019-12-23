#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct link *AppendNode(struct link *head);
void DisplyNode(struct link *head);
void DeleteMemory(struct link *head);
struct link * hu(struct link *head);
void jia(struct link *head);
void shuai(struct link *head);
void jiashuai(struct link *head);
void  nice(int a);
struct link * ww(int b);
struct link *  you(int a);
struct link{	int data;
char book[10];
char writer[10];
char publisher[20];
int time;
struct link *next;
}CLASS;
int main()
{
int i=0,k=0,nodeData=0;
char c;
struct link *head=NULL;
char m[10];	
printf("*********欢迎进入您的个人图书管理系统***********\n");
printf("********************由于本系统内暂无数据请先执行录入功能****************\n");
printf("%d new nodes have been apended!\n",i);
printf("*         1：信息查找              *\n");
printf("*         2：修改数据              *\n");
printf("*         3：删除数据              *\n");
printf("*         4：数据排序              *\n");
printf("*         5：录入功能              *\n"); 
printf("*         6：浏览功能              *\n");
printf("*         0：程序结束              *\n");
scanf("%d",&k);	while(k!=0&&k<=6)	
{
switch(k)	
{	   
case 1:
printf("请输入编号\n");
hai(head);		
break;		
case 2:
printf("请输入修改的数据\n");
hui(head);
DisplyNode(head);	
break;	
case 3:
printf("请输入删除的数据\n");
head=liu(head);
DisplyNode(head);
break;      
case 4:
printf("请输入数据排序\n");
liuliu(head);		
break;	
case 5:
printf("请输入录入功能\n");
head=you(2);		
break;    
case 6:
printf("请输入浏览功能\n");
head=ww(2);
DisplyNode(head);	
break;	
}
printf("*        1：信息查找              *\n");
printf("*         2：修改数据              *\n");	
printf("*         3：删除数据              *\n");	
printf("*         4：数据排序              *\n");	
printf("*         5：录入功能              *\n");	
printf("*         6：浏览功能              *\n");	
printf("*         0：程序结束              *\n");	
scanf("%d",&k);	
}
DeleteMemory(head);
}
struct link * ww(int b)
{   
struct link *head=NULL,*pr=head,*newbook;  
FILE *fp=fopen("d:\\liuhuihai.txt","r");  
if(fp==NULL)
{	
printf("文件打开失败！\n");
exit(0);	
}		

while(!feof(fp))
{	
struct link *newbook=(struct link *)malloc(sizeof(struct link ));
fscanf(fp,"%d%d%d%d%s%s%s",&newbook->data,	
&newbook->time,	
newbook->book,		
newbook->writer,	
newbook->publisher);
if(head==NULL)	
{		
head=newbook;	
newbook->next=NULL;	
pr=newbook;	
}	  
else	
{		
pr->next=newbook;	
pr=newbook;	
newbook->next=NULL;	
}	  	
}
fclose(fp);
pr=head;
return head;
}
struct link *  you(int a)
{
char c;
int i=0;
struct link *head=NULL;
printf("是否录入图书信息(Y/N)?\n");
scanf(" %c",&c);	
while(c=='Y'||c=='y')	
{	
head=AppendNode(head);
printf("Do you want to append a new node(Y/N)?\n");	
scanf(" %c",&c);i++;
}	
return head;
}	
struct link *AppendNode(struct link *head)
{	
struct link *p=NULL,*pr=head;
int data,c,e,f;
char a[10],b[10],d[20];
p=(struct link *)malloc(sizeof(struct link));	
FILE*fp;
if((fp=fopen("d:\\hu.txt","a+"))==NULL)
{	
printf("Failure to open hu.bin!\n");
exit(0);
}	
int j=1;
if(p==NULL)	
{	
printf("No enough memory to allocate!\n");	
exit(0);
}	
if(head==NULL)
{	
head=p;
}	
else
{	
while
(pr->next!=NULL)
{		
pr=pr->next;	
}	
pr->next=p;	
}	
printf("请输入编号\n");
scanf("%d",&data);
fflush(stdin);
p->data=data;
printf("请输入书名\n");
scanf("%s",p->book);
printf("请输入作者\n");
scanf("%s",p->writer);
printf("请输入出版时间\n");
scanf("%d",&e);
fflush(stdin);
p->time=e;	
fputs("\n",fp);
fprintf(fp,"%d\t%d\t%d\t\t%d\t",p->data,p->kindofnumber,p->time,p->price); 
fputs(p->book,fp);
fputs("\t",fp);
fputs(p->writer,fp);
fputs("\t",fp);
fputs(p->publisher,fp);
fclose(fp);	
p->next=NULL; 
return head;
}
void DisplyNode(struct link *head)
{	
struct link *p=head,*pr=NULL;
int tem,*i;
FILE*fp;
if((fp=fopen("d:\\hu.txt","w+"))==NULL)
{		
printf("Failure to open hu.bin!\n");	
exit(0);
}
int j=1;
printf("   编号   出版时间    书名     作者  \n");
while(p!=NULL)
{  
fputs("\n",fp);
fprintf(fp,"%d\t%d\t%d\t\t%d\t",p->data,p->kindofnumber,p->time,p->price);	
fputs(p->book,fp);
fputs("\t",fp);
fputs(p->writer,fp);
fputs("\t",fp);
fputs(p->publisher,fp); 
printf("%6d%8d%8d%8d",p->data,p->kindofnumber,p->time,p->price);	
printf("      ");	  
printf("%s",p->book);
printf("\t");	  
printf("%s",p->writer);
printf("\t");	   
printf("%s",p->publisher);
printf("\n");     
p=p->next;	
j++;	
}
fclose(fp);
}
void DeleteMemory(struct link *head)
{	
struct link *p=head,*pr=NULL;
while(p!=NULL)	
{	
pr=p;
p=p->next;	
free(pr);	
}
}
void hai(struct link *head)
{	
struct link *p=head;  
int j=1,i=0;
char b[10]={'\0'};
printf("请输入书名以便进行查找\n");	
scanf("%s",b);
while(p!=NULL)
{   	
if(strcmp(p->book,b)==0)	
{ 
printf("     编号    出版时间      书名     作者  \n");	
printf("      ");	
printf("%d%6d%8d%8d%8d",j,p->data,p->kindofnumber,p->time,p->price);	 
printf("%s",p->book); printf("\t");	 
printf("%s",p->writer);printf("\t");	
printf("%s",p->publisher);printf("\n");
break;	
}	
else	
{   
p=p->next;	
j++;
}
}
}
void hui(struct link *head)
{	
struct link *pr=head,*p=head,*tem=NULL; 
int j=1,i=2,t=1,x,sum;
char b[10]={'\0'};
printf("请输入书名以便进行查找\n");
scanf("%s",b);
while(p!=NULL)	
{   	
if(strcmp(p->book,b)==0)	
{ 		
printf("*         1：编号                    *\n");	
printf("*         2：出版时间                *\n");
printf("*         3：书名                    *\n");
printf("*         4：作者                    *\n");
printf("*         0: 结束修改                *\n");
while(t<8&&t>=1)		
{		
printf("请输入\n");	
scanf("%d",&x);	
switch(x)		
{	
case 0: 
break;	
case 1:
printf("请输入新的编号\n");
scanf("%d",&sum);
p->data=sum;
break;		
case 2:
printf("请输入新的出版时间\n");
scanf("%d",&sum);
p->time=sum;
break;					
case 3:
printf("请输入新的书名\n");
scanf("%s",p->book);
break;		
case 4:
printf("请输入新的作者\n");
scanf("%s",p->writer);
break;		
}		
t=x;   
if(t==0)	
{			 
i=t;	
break;	  
}		
}		
}	
else
{	 
tem=p;
p=p->next;	
j++;
}	
if(i==0)
{		
break;
}		
}	
}
struct link * hu(struct link *head)
{	
struct link *pr=head,*p=head;	
if(head==NULL)	
{		
printf("链表为空\n");	
exit(0);
}	
char b[10]={'\0'};
printf("请输入要删除的书名\n");	
scanf("%s",b);
fflush(stdin);	
while(p!=NULL)
{   	
if(strcmp(p->book,b)==0)	
{		 
if(p==head)
{printf("     编号    出版时间     书名     作者  \n");
printf("      ");	
printf("%6d%8d%8d%8d",p->data,p->kindofnumber,p->time,p->price);
printf("%s",p->book); printf("\t");	 
printf("%s",p->writer);printf("\t");	
printf("%s",p->publisher);printf("\n");	
head=p->next;		 free(p);break;
}		
else	
{		
pr->next=p->next;
free(p);break;		
}	
}	
pr=p;	
p=p->next;
}	
return (head);
}
void shu(struct link *head)
{	
struct link *pr=head,*p=head;int term;	
char a[10],*g;g=a;
while(p!=NULL)	
{		
while(pr!=NULL)	
{		
if(p->time>pr->time)	
{	      
term=p->time;
p->time=pr->time;
pr->time=term;
term=p->data;
p->data=pr->data;
pr->data=term;	
strcpy(a,pr->book);
strcpy(pr->book,p->book);
strcpy(p->book,a);		
strcpy(a,pr->writer);
strcpy(pr->writer,p->writer);
strcpy(p->writer,a);    
}
pr=pr->next;
}p=p->next;
}	
DisplyNode(head);
}
