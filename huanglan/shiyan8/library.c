#include<stdio.h> 
#include<math.h> 
#include<string.h> 
#include<stdlib.h> 
  
  
struct books_list 
{ 
   
 char author[20];    /*作者名*/
 char bookname[20];   /*书名*/
 char publisher[20];   /*出版单位*/
 char pbtime[15];    /*出版时间*/
 char loginnum[10];   /*登陆号*/
 float price;     /*价格*/
 char classfy[10];    /*分类号*/
 struct books_list * next; /*链表的指针域*/
}; 
   
struct books_list * Create_Books_Doc();  /*新建链表*/
void InsertDoc(struct books_list * head); /*插入*/
void DeleteDoc(struct books_list * head , int num);/*删除*/
void Print_Book_Doc(struct books_list * head);/*浏览*/
void search_book(struct books_list * head); /*查询*/
void save(struct books_list * head);/*保存数据至文件*/
  
/*新建链表头节点*/
struct books_list * Create_Books_Doc() 
{ 
 struct books_list * head; 
 head=(struct books_list *)malloc(sizeof(struct books_list)); /*分配头节点空间*/
 head->next=NULL; /*头节点指针域初始化，定为空*/
 return head; 
} 
  
/*保存数据至文件*/
void save(struct books_list * head) 
{ 
 struct books_list *p; 
 FILE *fp; 
 p=head; 
 fp=fopen("data.txt","w+"); /*以写方式新建并打开 data.txt文件*/
 fprintf(fp,"┏━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━━┳\n"); 
 fprintf(fp,"┃登录号┃ 书 名 ┃ 作  者┃ 出版单位 ┃ 出版时间 ┃分类号┃ 价\n"); 
 fprintf(fp,"┣━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━━╋━━\n"); 
 /*指针从头节点开始移动，遍历至尾结点，依次输出图书信息*/
 while(p->next!= NULL) 
 { 
 p=p->next; 
 fprintf(fp,"┃%-6.6s┃%-10.10s┃%-10.10s┃%-10.10s┃%-12.12s┃%-6.6s┃%.2f ┃\n",p->loginnum,p->bookname,p->author,p->publisher,p->pbtime,p->classfy,p->price); 
 } 
 fprintf(fp,"┗━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━━┻━━━┻━━━━┛\n"); 
 fclose(fp); 
 printf("     已将图书数据保存到 data.txt 文件\n"); 
} 
  
/*插入*/
void InsertDoc(struct books_list *head) 
{ 
 /*定义结构体指针变量 s指向开辟的新结点首地址 p为中间变量*/
 struct books_list *s, *p; 
 char flag='Y'; /*定义flag,方便用户选择重复输入*/
 p=head; 
 /*遍历到尾结点，p指向尾结点*/
 while(p->next!= NULL) 
 { 
 p=p->next; 
 }  
 /*开辟新空间,存入数据,添加进链表*/
 while(flag=='Y'||flag=='y') 
 { 
 s=(struct books_list *)malloc(sizeof(struct books_list)); 
 printf("\n     请输入图书登陆号:"); 
 fflush(stdin); 
 scanf("%s",s->loginnum); 
 printf("\n     请输入图书书名:"); 
 fflush(stdin); 
 scanf("%s",s->bookname); 
 printf("\n     请输入图书作者名:"); 
 fflush(stdin); 
 scanf("%s",s->author); 
 printf("\n     请输入图书出版社:"); 
 fflush(stdin); 
 scanf("%s",s->publisher); 
 printf("\n     请输入图书出版时间:"); 
 fflush(stdin); 
 scanf("%s",s->pbtime); 
 printf("\n     请输入图书分类号:"); 
 fflush(stdin); 
 scanf("%s",s->classfy); 
 printf("\n     请输入图书价格:"); 
 fflush(stdin); 
 scanf("%f",&s->price); 
 printf("\n"); 
 p->next=s; /*将新增加的节点添加进链表*/
  p=s; /*p指向尾节点，向后移*/
 s->next=NULL; 
 printf("     ━━━━ 添加成功！━━━━"); 
 printf("\n       继续添加？(Y/N):"); 
 fflush(stdin); 
 scanf("%c",&flag); 
 printf("\n"); 
 if(flag=='N'||flag=='n') 
 {break;} 
 else if(flag=='Y'||flag=='y') 
 {continue;} 
 } 
 save(head); /*保存数据至文件*/
 return; 
} 
  
/*查询操作*/
  
void search_book(struct books_list *head) 
{ 
 struct books_list * p; 
 char temp[20]; 
 p=head; 
 if(head==NULL || head->next==NULL) /*判断数据库是否为空*/
 { 
 printf(" ━━━━ 图书库为空！━━━━\n"); 
 } 
 else
 { 
 printf("请输入您要查找的书名: "); 
 fflush(stdin); 
 scanf("%s",temp); 
 /*指针从头节点开始移动，遍历至尾结点，查找书目信息*/
 while(p->next!= NULL) 
 { 
 p=p->next; 
 if(strcmp(p->bookname,temp)==0) 
 { 
 printf("\n图书已找到!\n"); 
 printf("\n"); 
 printf("登录号: %s\t\n",p->loginnum); 
 printf("书名: %s\t\n",p->bookname); 
 printf("作者名: %s\t\n",p->author); 
 printf("出版单位: %s\t\n",p->publisher); 
 printf("出版时间: %s\t\n",p->pbtime); 
 printf("分类号: %s\t\n",p->classfy); 
 printf("价格: %.2f\t\n",p->price); 
 } 
 if(p->next==NULL) 
 { 
 printf("\n查询完毕!\n"); 
 } 
 } 
 } 
 return; 
} 
  
 /*浏览操作*/
   
void Print_Book_Doc(struct books_list * head) 
{ 
 struct books_list * p; 
 if(head==NULL || head->next==NULL) /*判断数据库是否为空*/
 { 
 printf("\n      ━━━━ 没有图书记录! ━━━━\n\n"); 
 return; 
 } 
 p=head; 
 printf("┏━━━┳━━━━━┳━━━━━┳━━━━━┳━━━━━━┳━━━┳━━━━┓\n"); 
 printf("┃登录号┃ 书 名 ┃ 作  者┃ 出版单位 ┃ 出版时间 ┃分类号┃ 价格 ┃\n"); 
 printf("┣━━━╋━━━━━╋━━━━━╋━━━━━╋━━━━━━╋━━━╋━━━━┫\n"); 
 /*指针从头节点开始移动，遍历至尾结点，依次输出图书信息*/
 while(p->next!= NULL) 
 { 
 p=p->next; 
 printf("┃%-6.6s┃%-10.10s┃%-10.10s┃%-10.10s┃%-12.12s┃%-6.6s┃%.2f ┃\n",p->loginnum,p->bookname,p->author,p->publisher,p->pbtime,p->classfy,p->price); 
 } 
 printf("┗━━━┻━━━━━┻━━━━━┻━━━━━┻━━━━━━┻━━━┻━━━━┛\n"); 
 printf("\n"); 
} 
  
int main() 
{ 
 struct books_list * head; 
 char choice; 
 head=NULL; 
 for(;;) /*实现反复输入选择*/
 { 
 printf("    ┏━┓━━━━━━━━━━━━━━━━━━━┏━┓\n"); 
 printf("    ┃  ┃   黄兰个人图书馆管理系统  ┃ ┃\n"); 
 printf("    ┃  ┗━━━━━━━━━━━━━━━━━━━┛  ┃\n"); 
 printf("    ┃    [1]图书信息录入    ┃\n"); 
 printf("    ┃            ┃\n"); 
 printf("    ┃    [2]图书信息浏览    ┃\n"); 
 printf("    ┃            ┃\n"); 
 printf("    ┃    [3]图书信息查询    ┃\n"); 
 printf("    ┃            ┃\n"); 
 printf("    ┃    [4]退出系统     ┃\n"); 
 printf("    ┃            ┃\n"); 
 printf("    ┃            ┃\n"); 
 printf("    ┗━━━━━━━━━━━━━━━━━━━━━━━┛\n"); 
 printf("        请选择:"); 
 fflush(stdin); 
 scanf("%c",&choice); 
 if(choice=='1') 
 { 
 if(head==NULL) 
 { 
 head=Create_Books_Doc(); 
 } 
 InsertDoc(head); 
   
 } 
 else if(choice=='2') 
 { 
 Print_Book_Doc(head); 
 } 
 else if(choice=='3') 
 { 
 search_book(head); 
 } 
  
 else if(choice=='4') 
 { 
 printf("\n"); 
 printf("   ━━━━━━━━ 感谢使用图书管理系统 ━━━━━━━━\n"); 
 break; 
 } 
 //else
 //{ 
// printf("     ━━━━ 输入错误，请重新输入！━━━━\n"); 
  
// } 
 } 
  
 return 0; 
} 

