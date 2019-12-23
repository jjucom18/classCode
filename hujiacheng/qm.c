#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 4 						//定义航线量的最大值 

typedef struct link						//等候替补的客户 
{  
   char name[10];						//姓名 
   int ticket;							//订票量 
   struct link *next;
}qnode,*qptr;

typedef struct pqueue 				 	//定义单链队列 
{  qptr front;							//等候替补客户名单域的头指针 
   qptr rear;							//等候替补客户名单域的尾指针 
}linkqueue;

typedef struct custom					//定义名为 custom的结构体 用来表示客户信息 
{  
   char name[10];						//客户姓名 
   int ord_amt;							//订票量 
   int grade;							//舱位等级 
   struct custom *next;
}linklist;

struct airline
{   char ter_name[20];					//终点站名  
    char air_num[20];					//航班号 
    char plane_num[20];					//飞机号 
    char day[20];						//飞行周日（星期几） 
    int tic_amt;						//乘员定额 
    int tic_sur;						//余票量 
    linklist *order;					//乘员名单域，指向乘员名单链表的头指针 
    linkqueue wait;						//等候替补的客户名单域，分别指向排队等候名单队头队尾的指针 
}lineinfo,*start;

void display(struct airline *info)		//定义函数，作用为打印每条航线的基本信息 
{
	printf("%8s\t%3s\t%2s\t%4s\t\t%3d\t%10d\n",info->ter_name,info->air_num,info->plane_num,info->day,info->tic_amt,info->tic_sur);
}

void list()								//打印全部航线信息  by：肖佳龙 
{  
   struct airline *info;				//定义一个保存所有信息的节点 
   int i = 0;
   info = start;						//将start指针变量赋给info 
   printf("终点站名\t航班号\t飞机号\t飞行周日\t乘员定额\t余票量\n");
   while(i<MAXSIZE)
   {
     display(info);
     info++;
     i++;
   }
   printf("\n");
}


void search()			    							//根据客户提出的终点站名输出航线信息 by：李俊杰 
{
   struct airline *info; 
   char name[10];
   int i = 0;
   info = start;
   printf("请输入终点站名:");
   scanf("%s",name);
   while(i<MAXSIZE)
   {
    if(!strcmp(name,info->ter_name)) break;				//将info中的终点站名字与输入的终点站名字name进行比较 ，若为不相同则退出循环  
    info++;
    i++;
   }
   if(i >= MAXSIZE)
    printf("对不起，该航线未找到!\n");
   else{
    printf("终点站名\t航班号\t飞机号\t飞行周日\t乘员定额\t余票量\n");
    display(info);
   }
}

struct airline *find()										//struct类型的函数，根据系统提出的航班号查询并以指针形式返回 by:陈厚华 
{ 
   struct airline *info;
   char number[10];
   int i  =  0;
   info = start;
   printf("请输入航班号:");
   scanf("%s",number);
   while(i<MAXSIZE) {
     if(!strcmp(number,info->air_num)) return info; 		//将info中的航班号与输入的航班号number进行比较 ，若为不相同则退出循环 
     info++;
     i++;
   }
   printf("对不起，该航线末找到!\n");
   return NULL;
}

linklist *insertlink(linklist *head,int amount,char name[],int grade)	//增加订票乘员名单域的客户信息 by:陈厚华
{  
   linklist *p1,*NEW;
   p1 = head;
   NEW = (linklist *)malloc(sizeof(linklist));     					  	//为节点新分配空间 
   if(!NEW) 
   {
   printf("\n没有多余存储空间!!\n");
   return NULL;
    }
   strcpy(NEW->name,name);										//将新加入的姓名复制到新节点的 name中 
   NEW->ord_amt = amount;										//将订票量赋值给新节点的 ord_amt中 
   NEW->grade = grade;											//将舱位等级赋值给新节点的 grade中 
   NEW->next = NULL;									  		//新节点的后继指针指向空 
   if(head == NULL)												//若原无订票客户信息 
   {
	head = NEW;
	NEW->next = NULL;
	}
   else
   { 
    head = NEW;
    NEW->next = p1;
	} 
   return head;
}

linkqueue appendqueue(linkqueue q,char name[],int amount)		//增加排队等候的客户名单域  by:肖佳龙
{ 
  qptr NEW;
  NEW = (qptr)malloc(sizeof(qnode));							//为节点新分配空间 
  strcpy(NEW->name,name);										//将姓名赋值给新节点的 name中
  NEW->ticket = amount;											//将订票量赋值给新节点的 amount中
  NEW->next = NULL;												//新节点的后继指针指向空 
  if(q.front == NULL)											//若原排队等候客户名单域为空 
    q.front = NEW;												//对头指向新队列 
  else
    {
	q.rear->next = NEW;											//将新节点接在队尾 
  	q.rear = NEW;
  	} 
  return q;
}

void order()											//办理订票业务    by：李俊杰 
{  struct airline *info;
   int amount,grade;
   char name[10];
   info = start;
   if(!(info = find())) return;//根据客户提供的航班号进行查询，如为空，退出该模块 
   printf("请输入您订票的数量:");
   scanf("%d",&amount);
   if(amount>info->tic_amt)//若客户订票额超过乘员定票总额，退出 
   {  printf("\n对不起，您输入订票的数量已经超过乘员定额!");
      return;
   }
   if(amount <= info->tic_sur)//若客户订票额末超过余票量，订票成功并等记信息 
   {
     int i;
  printf("请输入您的姓名（订票客户）:");
     scanf("%s",name);
  printf("请输入%s票的舱位等级:",name);
     scanf("%d",&grade);
     info->order = insertlink(info->order,amount,name,grade);	//在订票乘员名单域中添加客户信息 
     for(i = 0;i<amount;i++)							    	//依次输出该订票客户的座位号 
       printf("%s的座位号是:%d\n",name,info->tic_amt - info->tic_sur + i + 1); 
     info->tic_sur-= amount;									//该航线的余票量应减掉该客户的订票量 
  printf("\n订票成功，祝您旅途愉快！\n");
   }
   else      													 //若满员或余票额少于订票额，询问客户是否需要进行排队等候 
   {  char r;
   printf("\n已经没有更多的票，您需要排队等候吗?(需要请按'Y'，若不需要请按'N')");
   fflush(stdin);
   scanf("%c", &r);
   if(r == 'Y'||r == 'y')
   {  printf("\n请输入您的姓名（排队订票客户）:");
         scanf("%s",name);
      info->wait = appendqueue(info->wait,name,amount);			//在排队等候乘员名单域中添加客户信息 
      printf("\n注册成功!\n");
   }
   else printf("\n欢迎您下次再次订购！\n");
    }
}

void return_tic() 											//退票模块    by：陈厚华 
{  struct airline *info;
   qnode *t,*back,*f,*r;
   int grade,num;
   linklist *p1,*p2,*head;
   char cusname[10];
   if(!(info = find())) return;								//调用查询函数，根据客户提供的航线进行搜索 
   head = info->order;
   p1 = head;
   printf("请输入你的姓名（退票客户）:");
   scanf("%s",cusname);
   while(p1 != NULL) 
   {														//根据客户提供的姓名到订票客户名单域进行查询 
     if(!strcmp(cusname,p1->name)) break;
     p2 = p1;
	 p1 = p1->next;
   }
	if(p1 == NULL)
	{ 
	  printf("对不起，你没有订过票!\n");
	  return;
	}															//若未找到，退出本模块 
   else{													//若信息查询成功，删除订票客户名单域中的信息 
        printf("您的订票量为：%d\n",p1->ord_amt);
        printf("请输入您的退票数量：");
        scanf("%d",&num);
        if(p1 == head)
        {    
		  grade = p1->grade;
          if(p1->ord_amt == num) 
		  {
		  head = p1->next;free(p1);
		  }
          else
          {
            if(p1->ord_amt>num)
			 head->ord_amt-= num;
          }
        }
        else
        {
           if(p1->ord_amt == num) 
		   {
		   p2->next = p1->next;
		   free(p1);
		   }
           else
           {
            if(p1->ord_amt>num)
			 p1->ord_amt-= num;
           }
        }
        info->tic_sur+= num;
        printf("\n成功退票！\n");


   }
   info->order = head;															//重新将航线名单域指向订票单链表的头指针  
   f = (info->wait).front;														//f指向排队等候名单队列的头结点 
   r = (info->wait).rear;														//r指向排队等候名单队列的尾结点 
   t = f;																		//t为当前满点条件的排队候补名单域 
   while(t)
   {
    if(info->tic_sur >= info->wait.front->ticket)
	{																			//若满足条件者为头结点 
    int i;
    info->wait.front = t->next;
    printf("%s订票成功！\n",t->name);
    for(i = 0;i<t->ticket;i++)													//输出座位号 
         printf("%s的座位号是:%d\n",t->name,(info->tic_sur)-i);
    info->tic_sur-= t->ticket;
    info->order = insertlink(info->order,t->ticket,t->name,grade);				//插入到订票客户名单链表中 
    free(t);
    break;
    }
      back = t;t = t->next;
    if((info->tic_sur) >= (t->ticket)&&t!=NULL)									//若满足条件者不为头结点 
    {
	int i;
    back->next = t->next;
    printf("\n\t%s订票成功！\n",t->name);
    for(i = 0;i<t->ticket;i++)													//输出座位号 
        printf("<%s>座位号是:%d\n",t->name,(info->tic_sur)-i);
    info->tic_sur-= t->ticket;
    info->order = insertlink(info->order,t->ticket,t->name,grade);				//插入到订票客户名单链表中 
    free(t);
	break;
   }
   if(f == r) 
   	break;
   }
}

int menu_select()					//菜单界面 
{
   int c;
   char s[20];
   puts(	"******************************************************************************** \n"
            "-----------------------    欢迎使用航空客运订票系统     ----------------------   \n"
            "******************************************************************************** \n"
            "                                                             \n"
            "                                                             \n"
            "                              1.浏览航线信息                 \n"                        
            "                              2.查询航线         	          \n"
            "                              3.办理订票业务                 \n"
            "                              4.办理退票业务                 \n"
	    	"                              5.退出系统                     \n"
            "                                                             \n"
            "******************************************************************************** ");
   do{
     printf("\t\t\t    请选择并按回车键结束:");
     scanf("%s",s);
     c = atoi(s);
   }while(c<0||c>7);
   return c;
}

int main(void)

{  
	int i;	
	struct airline air[MAXSIZE] = {{"beijing","1","B8571","Sunday",3,3},
	{"nanjing","2","J3845","Thursday",4,4},
    {"shanghai","2","F1402","Monday",2,2},
    {"tianjing","3","Y4203","Wednesday",1,1}}; 		//初始化航线信息 
	FILE* fp;										//定义文件指针fp，fp有文件名、文件状态和文件当前位置 
	fp = fopen( "D:\\exam.txt", "a");				//以追加方式打开文件 并将文件保存在 D 盘 
	if (fp == NULL)
	{
		printf("文件打开错误");
	}
	for(i = 0; i <= 2;i++ )
	{
		
	fprintf(fp,"终点站名：%s\n航班号：%s\n飞机号：%s\n飞行周日：%s\n乘员定额：%d\n余票量: %d\n",air[i].ter_name,air[i].air_num,air[i].plane_num,air[i].day,air[i].tic_amt,air[i].tic_sur);
	
	}
	fclose(fp);
 	start = air;    					     		//将指针 star 指向数组 air 
 	for(;;)
	{
	    switch(menu_select())
		{
	       case 1:list();break;
	       case 2:search();break;
	       case 3:order();break;
	       case 4:return_tic();break;
	       case 5: exit(0);
	    }
    
	}
}


