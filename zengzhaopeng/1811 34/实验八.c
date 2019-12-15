#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct link *AppendNode(struct link *head);//创建链表，输入数据
void DisplyNode(struct link *head);//将链表中的数据在屏幕上显示出来
void DeleteMemory(struct link *head);//释放链表中的占用内存
struct link * liu(struct link *head);//链表中的数据删除
void hui(struct link *head);//链表中的数据修改
void hai(struct link *head);//链表中的数据查找
void liuliu(struct link *head);
void  xiongdi(int a);
struct link * ww(int b);
struct link *  you(int a);
struct link{	int data;
	char book[10];
	char writer[10];
	int kindofnumber;
	char publisher[20];
	int time;
	int price;
	struct link *next;
}CLASS;
int main()
{
	int i=0,k=0,nodeData=0;
	char c;
	struct link *head=NULL;
	char m[10];	
	printf("*********欢迎进入图书管理系统***********\n");
	printf("******系统内暂无图书信息，请先添加图书信息*******\n");
	printf("%d new nodes have been apended!\n",i);
	printf("*         1：图书查找              *\n");
	printf("*         2：修改图书              *\n");
	printf("*         3：删除图书              *\n");
	printf("*         4：图书排序              *\n");
	printf("*         5：添加功能              *\n"); 
	printf("*         6：浏览功能              *\n");
	printf("*         0：程序结束              *\n");
	scanf("%d",&k);	while(k!=0&&k<=6)	
	{
		switch(k)	
		{	   
			case 1:
				printf("请输入图书编号\n");
				hai(head);		
				break;		
			case 2:
				printf("请输入修改的数据\n");
				hui(head);
				DisplyNode(head);	
				break;	
			case 3:
				printf("请输入删除的图书\n");
				head=liu(head);
				DisplyNode(head);
				break;      
			case 4:
				printf("请输入图书排序\n");
				liuliu(head);		
				break;	
			case 5:
				printf("请输入添加功能\n");
				head=you(2);		
				break;    
			case 6:
				printf("请输入浏览功能\n");
				head=ww(2);
				DisplyNode(head);	
				break;	
		}
		printf("*        1：图书查找              *\n");
		printf("*         2：修改图书              *\n");	
		printf("*         3：删除图书              *\n");	
		printf("*         4：图书排序              *\n");	
		printf("*         5：添加功能              *\n");	
		printf("*         6：浏览功能              *\n");	
		printf("*         0：程序结束              *\n");	
		scanf("%d",&k);	
	}
	DeleteMemory(head);
}
struct link * ww(int b)
{
	struct link *head=NULL,*pr=head,*newbook;  
	FILE *fp=fopen("d:\\tushu.txt","r");  
	if(fp==NULL)
	{	
		printf("文件打开失败！\n");
		exit(0);	
	}
	while(!feof(fp))
	{	
		struct link *newbook=(struct link *)malloc(sizeof(struct link ));
		fscanf(fp,"%d%d%d%d%s%s%s",&newbook->data,	
				&newbook->kindofnumber,		
				&newbook->time,	
				&newbook->price,	
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
	printf("是否添加图书信息(Y/N)?\n");
	scanf(" %c",&c);	
	while(c=='Y'||c=='y')	
	{	
		head=AppendNode(head);
		printf("是否继续添加图书(Y/N)?\n");	
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
	if((fp=fopen("d:\\tushu.txt","a+"))==NULL)
	{
		printf("Failure to open tushu.bin!\n");
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
	scanf("%s",p->book);//fgets(p->book,10,stdin);	
	printf("请输入作者名\n");
	scanf("%s",p->writer);//fgets(p->writer,10,stdin);	
	printf("请输入出版单位\n");
	scanf("%s",p->publisher);//fgets(p->publisher,20,stdin);   
	printf("请输入出版时间\n");
	scanf("%d",&e);
	fflush(stdin);
	p->time=e;	
	printf("请输入价格\n");
	scanf("%d",&f);
	fflush(stdin);
	p->price=f;	
	printf("请输入分类号\n");
	scanf("%d",&c);
	fflush(stdin);
	p->kindofnumber=c;	
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
	FILE*fp;//char w[80]="\t编号\t分类号\t出版时间\t价格\t书名\t作者名\t出版单位\n";
	if((fp=fopen("d:\\tushu.txt","w+"))==NULL)
	{
		printf("Failure to open tushu.bin!\n");	
		exit(0);
	}
	int j=1; 
	printf("   编号  分类号  出版时间  价格    书名     作者名   出版单位\n");
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
			printf("     编号  分类号  出版时间  价格    书名     作者名   出版单位\n");	
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
			printf("*         1：编号              *\n");	
			printf("*         2：分类号              *\n");
			printf("*         3：出版时间            *\n");
			printf("*         4：价格                *\n");
			printf("*         5：书名                *\n");
			printf("*         6：作者名              *\n");
			printf("*         7：出版单位            *\n");
			printf("*         0: 结束修改            *\n");
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
						printf("请输入新的分类号\n");
						scanf("%d",&sum);
						p->kindofnumber=sum;	
						break;		
					case 3:
						printf("请输入新的出版时间\n");
						scanf("%d",&sum);
						p->time=sum;	
						break;			
					case 4:
						printf("请输入新的价格\n");
						scanf("%d",&sum);
						p->price=sum;
						break;		
					case 5:
						printf("请输入新的书名\n");
						scanf("%s",p->book);//fgets(p->book,10,stdin);			
						break;		
					case 6:
						printf("请输入新的作者名\n");
						scanf("%s",p->writer);//fgets(p->writer,10,stdin);	
						break;		
					case 7:
						printf("请输入新的出版单位\n");
						scanf("%s",p->publisher);//fgets(p->publisher,20,stdin);		
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
struct link * liu(struct link *head)
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
			{printf("     编号  分类号  出版时间  价格    书名     作者名   出版单位\n");
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
void liuliu(struct link *head)
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
				term=p->price;
				p->price=pr->price;
				pr->price=term;		
				term=p->kindofnumber;
				p->kindofnumber=pr->kindofnumber;
				pr->kindofnumber=term;
				strcpy(a,pr->book);
				strcpy(pr->book,p->book);
				strcpy(p->book,a);		
				strcpy(a,pr->writer);
				strcpy(pr->writer,p->writer);
				strcpy(p->writer,a);    
				strcpy(a,pr->publisher);
				strcpy(pr->publisher,p->publisher);
				strcpy(p->publisher,a);			
			}
			pr=pr->next;
		}p=p->next;
	}	
	DisplyNode(head);
}
