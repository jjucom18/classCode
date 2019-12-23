#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct wat_customer /*等候订票乘客的信息*/
{  char name[20];
   char phone[15];
   int dpl;/*订票量*/
   struct wat_customer *next;
}qnode,*qptr;

typedef struct pqueue    //等待名单域运用队列先进先出的特点 
{  qptr front;
   qptr rear;
}linkqueue;

typedef struct customer
{  char name[20];/*客户姓名*/
   char IDnum[20];/*客户有效证件的编号*/
   char airnum[7];/*航班号*/
   int dpl;/*订票量*/
   char bianhao[50];//票的编号，由航班号起飞日期此航班订票前的余票量
   struct customer *next;
}Lnode ,*linklist;

typedef struct airline
{   char qdname[20];/*起点站名*/
	char zhname[20];/*终点站名 */
    char air_num[7];/*航班号*/
    char plane_num[10];/*飞机型号*/
    char year[5];
    char month[3];
    char day[3];/*飞行日期*/
	char qhour[3];
	char qminute[3];/*起飞时间*/
	char jhour[3];
	char jminute[3];/*降落时间*/
	float discount;/*没有折扣为十折*/
	float price;/*票价*/
    int Limited_number;/*乘员定额*/
    int Remainder_tickets;/*余票量*/
    Lnode *order;/*本航班乘客名单域，指向乘客名单链表的头指针*/
    linkqueue *wait;/*本航班等候替补的客户名单域，分别指向排队等候名单队头队尾的指针*/
    struct airline  *next;
}lineinfo,*lineair;

char nyear[5];
char nmonth[3];
char nday[3];/*今天日期*/
int y=0;  //全局变量，生命周期是整个函数运行时间，用于区别每个乘客的编号 
void Display(lineair H) /*浏览航线信息*/
{
	lineinfo *p;
	p=H->next;
	printf("航班号 起飞站 终点站 机型 飞行日期    起、降时间   票价  折扣 成员定额 余票量\n");
	while(p)
	{
		if((strcmp(nyear,p->year)<=0)&&(strcmp(nmonth,p->month)<=0)&&(strcmp(nday,p->day)<=0))
		{
			printf("%s  %s   %s  %s  %s/%s/%s %.2s:%.2s %.2s:%.2s  %5.1f  %3.1f   %d     %d\n",p->air_num,p->qdname,p->zhname,p->plane_num,p->year,p->month,p->day,p->qhour,p->qminute,p->jhour,p->jminute,p->price,p->discount,p->Limited_number,p->Remainder_tickets);
		}
		p=p->next;
	}
}

void Displaypas(lineair H) /*浏览乘客信息*/
{
	int t=0,flag=1;
	lineinfo *p;
	Lnode *q;
	p=H->next;
	while(p)
	{
		if(p->order->next)
		{
			q=p->order->next;
			while(q) 
			{
				if(flag==1)
				{
					printf("姓名\t证件号码\t航班号\t订票量\t编号");
					flag=0;
				}
			    t=1;	
			    printf("\n%s\t%s\t%s\t%d\t%s",q->name,q->IDnum,q->airnum,q->dpl,q->bianhao);
				q=q->next;
			}	
		}
		p=p->next;
	}
	if(t==0)  printf("暂无乘客信息\n");
}

int Greatelist(lineair&H,int n)   /*录入*/
{   char a;
	int i;
	lineinfo *p;
	if(!(H=(lineair)malloc(sizeof(lineinfo))))
	{
		printf("分配空间出错");
	    a=getchar();
	    return(0);
	}
	H->next=NULL;
	if(!(H->order=(linklist)malloc(sizeof(lineinfo))))
	{
		printf("分配空间出错");
	    a=getchar();
	    return 0;
	}
	H->order->next=NULL;
	if(!(H->wait=(linkqueue*)malloc(sizeof(lineinfo))))
	{
		printf("分配空间出错");
	    a=getchar();
	    return 0;
	}
	H->wait->rear=H->wait->front=NULL;
	printf("\n开始录入航班信息：\n");
	for(i=0;i<n;i++)
	{
		if(!(p=(lineair)malloc(sizeof(lineinfo))))
		{ printf("分配空间出错");
	       a=getchar();
	       return 0;
		}
		printf("\n请输入第%d条航线信息:\n",i+1);
		printf("起点: ");scanf("%s",p->qdname);
		printf("终点: ");scanf("%s",p->zhname);
		printf("航班号: ");scanf("%s",p->air_num);
		printf("机型: ");scanf("%s",p->plane_num);
		printf("年、月、日: ");scanf("%s%s%s",p->year,p->month,p->day);
		printf("起飞时间: ");scanf("%s %s",p->qhour,p->qminute);
		printf("降落时间: ");scanf("%s %s",p->jhour,p->jminute);
		printf("折扣: ");scanf("%f",&p->discount);
		printf("票价: ");scanf("%f",&p->price);
		printf("乘员定额: ");scanf("%d",&p->Limited_number);
		p->Remainder_tickets=p->Limited_number; 
		if(!(p->order=(linklist)malloc(sizeof(lineinfo))))
		{printf("分配空间出错");
	     a=getchar();
	     return 0;
		}
    	p->order->next=NULL;
    	if(!(p->wait=(linkqueue*)malloc(sizeof(lineinfo))))
		{printf("分配空间出错");
	     a=getchar();
	     return 0;
		}
    	p->wait->rear=p->wait->front=NULL;
		p->next=H->next;    //头插法录入 
		H->next=p;
	}
	return 1;
}
int Dinpiao(lineair H)  /*订票*/
{
	int m,k=0,x,c=1,d;    
    lineinfo *p,*t;
    Lnode *q;
	char a,*b;
    qnode *s;
    char year[5];
    char month[3];
    char day[3];/*飞行日期*/
    char air_num[7];/*航班号*/
	p=H->next;
	t=H->next;
	printf("请输入所定的航班号，票的年、月、日：\n");
	scanf("%s",air_num);
    scanf("%s",year);
	scanf("%s",month);
	scanf("%s",day);
	while(p)
	{
    	if(!(strcmp(air_num,p->air_num))&&!(strcmp(year,p->year))&&!(strcmp(month,p->month))&&!(strcmp(day,p->day)))
		{
			c=0;
			if(p->Remainder_tickets)    // 有票时 
			{
			 printf("此航班还有%d张票可订，请输入您要订票的张数：",p->Remainder_tickets);
			 scanf("%d",&m);
		    	if(m<=p->Remainder_tickets)  //票量充足 
				{
					for(int i=1;i<=m;i++){
							if(!(q=(linklist)malloc(sizeof(Lnode))))
							{
							   printf("分配空间出错");
							   a=getchar();
							   return 0;
							}
							printf("请输入您的姓名：");
					    	scanf("%s",q->name);
						    printf("请输入您的身份证号码：");
						    scanf("%s",q->IDnum);
							q->dpl=1;     //订票量m？1？ 
							if(!(b=(char*)malloc(sizeof(char))))
							{
								printf("分配空间出错");
								a=getchar();
								return 0;
							}
							y++;    
							strcpy(q->airnum,p->air_num);
							itoa(y,b,10);  //将y转换成字符 
						    strcpy(q->bianhao,p->air_num);   //生成票的编号 
						    strcat(q->bianhao,p->year);   
						    strcat(q->bianhao,p->month);
							strcat(q->bianhao,p->day);
							strcat(q->bianhao,nyear);
						    strcat(q->bianhao,nmonth);
							strcat(q->bianhao,nday);
						    strcat(q->bianhao,b);
						    printf("您已成功订票！\n");
							printf("您所订票的编号：%s\n",q->bianhao);
							p->Remainder_tickets-=1;   //更新余票量 
					    	q->next=p->order->next;  //用头插法更新乘客名单 
					    	p->order->next=q;
					} 
                    return 1;
				}
		    	else   //票量不足 
				{
			    	printf("对不起余票量不够，请选择其他航班！\n");
			    	k=1;
				}
			}
	    	if(!p->Remainder_tickets||k==1)    //余票不足，进入等待 
			{
			    if(!p->Remainder_tickets)
				      printf("航班已经满仓，您可以选择以下相关航班：\n");
			    while(t)
				{
			     	if((strcmp(t->year,p->year)>=0)&&(strcmp(t->month,p->month)>=0)&&(strcmp(t->day,p->day)>=0)&&!(strcmp(p->qdname,t->qdname))&&!(strcmp(p->zhname,t->zhname))&&(m<=t->Remainder_tickets && t->Remainder_tickets!=0))
					{
						printf("航班号 机型  飞行日期    起降时间  票价 折扣 余票量\n%s %s  %s/%s/%s   %s:%s   %s:%s %5.1f %3.1f  %d\n ",t->air_num,t->plane_num,t->year,t->month,t->day,t->qhour,t->qminute,t->jhour,t->jminute,t->price,t->discount,t->Remainder_tickets);
					}
				    t=t->next;
				}
				printf("有没有您可以乘坐的航班\t0  没有 \t 非0整数  有\t请选择：");
				scanf("%d",&x);
				if(!x)    //候补 
				{
					printf("请输入您的姓名、联系方式、订票量\n");
					if(!(s=(qptr)malloc(sizeof(qnode))))
					{
						printf("分配空间出错！");
						a=getchar();
						return 0;
					}
					scanf("%s",s->name);
					scanf("%s",s->phone);
					scanf("%d",&s->dpl); 
					s->next=NULL;
					if(p->wait->front==NULL&&p->wait->rear==NULL) //等候订票队列为空
					{
						p->wait->rear=p->wait->front=s;
						p->wait->rear->next=NULL;
					}
					else
					{
						s->next=p->wait->rear->next;  //类似尾插 
						p->wait->rear->next=s;
						p->wait->rear=s;
						p->wait->rear->next=NULL;
					}
					printf("如果有人退票，我们会在第一时间联系您！\n");
					return 0;
				}
				else 
					return Dinpiao(H);
			}
		}
		p=p->next;
	}
	if(c)
	{
		printf("没有您所指定的航班，0 菜单栏  非0数字 重新输入航班号，票的年、月、日\n");
		scanf("%d",&d);
		if(d)
			return Dinpiao(H);
		else
			return 0;
	}
	return 1;
}

int tongzhiwait(lineinfo *H,char air_num[],char year[],char month[],char day[])/*通知候等乘客*/
{
	int m=0;
	lineinfo *p;
	Lnode *q;
	qnode *s,*t;
	char a,*b;
	p=H->next;
    while(p)
	{
	    if(!(strcmp(air_num,p->air_num))&&!(strcmp(year,p->year))&&!(strcmp(month,p->month))&&!(strcmp(day,p->day)))
		{
			if(p->wait->front!=NULL)
			{
				printf("通知等候订票的乘客:\n");
				s=p->wait->front;
				while(s!=NULL)
				{
					if(s->dpl<=p->Remainder_tickets)
			     	{
			        	printf("\n%s您已成功订到%d张票！\n请输入您的姓名：",s->name,s->dpl);
			    	    if(!(q=(linklist)malloc(sizeof(Lnode))))
			    		{
			     		   printf("分配空间出错");
			     		   a=getchar();
			    		   return 0;
			    		}
			        	scanf("%s",q->name);
			    	    printf("请输入您的身份证号码：");
			    	    scanf("%s",q->IDnum);
			    		q->dpl=s->dpl;
		    			if(!(b=(char*)malloc(sizeof(char))))
			    		{
		    				printf("分配空间出错");
		    				a=getchar();
		    				return 0;
			    		}
			    		y++;
		 	    		strcpy(q->airnum,p->air_num);
		     			itoa(y,b,10);     //将y转成字符存入b 
		       		    strcpy(q->bianhao,p->air_num);
			    	    strcat(q->bianhao,p->year);
			    	    strcat(q->bianhao,p->month);
			    		strcat(q->bianhao,p->day);
			    		strcat(q->bianhao,nyear);
				        strcat(q->bianhao,nmonth);
				    	strcat(q->bianhao,nday);
			    	    strcat(q->bianhao,b);
			     		printf("您所订票的编号：%s",q->bianhao);
			    		p->Remainder_tickets-=s->dpl;
			        	q->next=p->order->next;
			        	p->order->next=q;
                        if(m==0)
                        {
                        	p->wait->front=s->next;
                        }
                        if(m==1)
                        {
                        	t->next=s->next;
                        }
			    	}
			    	t=s;
			    	s=s->next;
			    	m=1;
				}
		        
			}
			
		}
		p=p->next;
    }
    return 1;
}

int Searchair(lineair H)  /*查询*/
{
	int m,k=1,t;
    lineinfo *p;
    char qdname[20];/*起点站名*/
	char zhname[20];/*终点站名*/
    char air_num[7];/*航班号*/
    char year[5];
    char month[3];
    char day[3];/*飞行日期*/
	p=H->next;
	printf("输入0按航班号查询，输入1按起飞抵达城市查询，请输入您的选择：");
	scanf("%d",&m);
	while(m<0||m>1)
	{
		printf("请您重新选择,输入0按航班号查询，输入1按起飞抵达城市查询：");
	    scanf("%d",&m);
	}
	if(m)
	{
		printf("请分别输入起飞抵达城市：\n");
		scanf("%s",qdname);
		scanf("%s",zhname);
		printf("机型 航班号    飞行日期      起降时间   票价 折扣 余票量\n");
		while(p)
		{
			if(!(strcmp(p->qdname,qdname))&&!(strcmp(p->zhname,zhname)))
			{
				printf("%s %s  %s/%s/%s   %.2s:%.2s %.2s:%.2s %5.1f   %3.1f   %d\n ",p->plane_num,p->air_num,p->year,p->month,p->day,p->qhour,p->qminute,p->jhour,p->jminute,p->price,p->discount,p->Remainder_tickets);
				k=0;
			}
			p=p->next;
		}
	}
	else
	{
		printf("请输入要查询的航班号以及日期：");
		scanf("%s",air_num);
		scanf("%s",year);
    	scanf("%s",month);
    	scanf("%s",day);
		while(p)
		{
			if(!(strcmp(air_num,p->air_num))&&!(strcmp(year,p->year))&&!(strcmp(month,p->month))&&!(strcmp(day,p->day)))
			{
				printf("机型 航班号 起飞城市 抵达城市  飞行日期       起降时间 票价 折扣 余票量\n%s %s   %s    %s    %s /%s/%s   %.2s:%.2s %.2s:%.2s  %5.1f  %3.1f %d\n ",p->plane_num,p->air_num,p->qdname,p->zhname,p->year,p->month,p->day,p->qhour,p->qminute,p->jhour,p->jminute,p->price,p->discount,p->Remainder_tickets);
				k=0;
			}
			p=p->next;
		}	
	}
	if(k)
	{
		printf("没有您要查询的航线！\n");
		return 0;
	}
	else
	{
		printf("有没有您要订票的航班！\n");
		do
		{
			printf("1有 0没有 请选择：\n");
			scanf("%d",&t);
		}while(!(t==1)&&!(t==0));
		if(t)
			return	Dinpiao(H);
		else
			return 0;		
	}
}

//int Tuipiao(lineair H)  //退票
//{
//	lineinfo *p=H->next;
//	Lnode *q,*pre;
//	int flag=1;
//	char bianhao[100];
//	scanf("%s",bianhao);
//	char airnumber[6];
////	printf("%s\n",bianhao);
////	system("Pause"); 
//	for(int i=0;i<6;i++){    //提取所退票的航班号 
//		airnumber[i]=bianhao[i];
//	}
//	char year[5],month[3],day[3];
//	for(int i=6;i<10;i++){   //提取所退票的年
//		year[i-6]=bianhao[i];
//	} 
//	year[5]='\0';
//	for(int i=10;i<=11;i++){   //提取所退票的月
//		month[i-10]=bianhao[i];
//	} 
//	month[2]='\0';
//	for(int i=12;i<=13;i++){   //提取所退票的日 
//		day[i-12]=bianhao[i];
//	} 
//	day[2]='\0';
////	printf("%s%s%s%s\n",airnumber,year,month,day);
////	printf("%s\n",year);
////	printf("%s\n",month);
////	printf("%s\n",day);
////	system("Pause"); 
//	while(p)
//	{
//		if(!strcmp(p->air_num,airnumber)&&!strcmp(p->year,year)&&!strcmp(p->month,month)&&!strcmp(p->day,day)){
//			q=p->order->next;
//			pre=p->order;
//			if(!strcmp(q->bianhao,bianhao)){
//				flag=0;
//				printf("已找到您的订票信息，确认退票请按1，退出请按0。");
//				int choice;
//				do{
//					scanf("%d",&choice);
//				}while(choice!=1&&choice!=0);
//				switch(choice){
//					case 1: 
//					{
//						pre->next=q->next;
//						int dpl;
//						dpl=q->dpl;
//						free(q);
//						printf("退票成功！");
////						p->Remainder_tickets+=dpl;
////						if(p->wait->rear==p->wait->front&&p->wait->front==NULL)
////	        				return 1;
////						else
////						{//机场订票系统服务人员马上通知本次航班等候订票乘客
////							getchar();
////							return tongzhiwait(H,p->air_num,p->year,p->month,p->day);
////						}
////						//return 1; 
//						break;
//					}
//					case 0: 
//					{
//						printf("您已取消退票！");
//						return 0; 
//					}
//							
//				} 
//			}
//			else{
//				pre=q;
//				q=q->next;
//			}
//		}
//		else
//			p=p->next;
//		
//	}
//	if(flag){
//		printf("您输入的订单编号有误！请重新选择服务！");
//		return 0; 
//	} 
//} 
int Tuipiao(lineair H)  //退票
{
	lineinfo *p;
	int m=0,t;
	Lnode *q;
	char b[100];
	scanf("%s",b);
	p=H->next;
	while(p)
	{
		if(p->order->next)
		{
			q=p->order;
			while(q->next) 
			{
				if(!(strcmp(b,q->next->bianhao)))
				{
					m=1;
					t=q->next->dpl;
					q->next=q->next->next;
					break;
				}	
				q=q->next;
			}	
		}
		if(m)
			break;
		p=p->next;
	}
	if(!m)
	{
		printf("对不起没有搜索到您的订单，请重新输入订单编号！");
		Tuipiao(H);
	}
	else
	{
		printf("您已成功退票！\n");
		p->Remainder_tickets+=t;
		if(p->wait->rear==p->wait->front&&p->wait->front==NULL)
	        return 1;
		else
		{//机场订票系统服务人员马上通知本次航班等候订票乘客
			getchar();
			return tongzhiwait(H,p->air_num,p->year,p->month,p->day);
		}
	}
}

int Modify(lineair H)  /*修改航班*/
{
	lineinfo *p,*q;
    char year[5];
	char a;
    char month[3];
    char day[3];/*飞行日期*/
    char air_num[7];/*航班号*/
	int c,i,n,d,r=0,x;    
	
	do
	{
		printf("1 添加航线 0 对已有的航班信息进行改动（修改和删除），请选择：");
		scanf("%d",&c);
	}while(c!=1&&!(c==0));
	if(c)
	{
		printf("请输入您要添加航班的条数");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
		    if(!(p=(lineair)malloc(sizeof(lineinfo))))
			{
		          printf("分配空间出错！");
			      a=getchar();
			      return 0;
			}
		 	printf("\n请输入第%d条航线信息:\n",i+1);
			printf("起点: ");scanf("%s",p->qdname);
			printf("终点: ");scanf("%s",p->zhname);
			printf("航班号: ");scanf("%s",p->air_num);
			printf("机型: ");scanf("%s",p->plane_num);
			printf("年、月、日: ");scanf("%s%s%s",p->year,p->month,p->day);
			printf("起飞时间: ");scanf("%s %s",p->qhour,p->qminute);
			printf("降落时间: ");scanf("%s %s",p->jhour,p->jminute);
			printf("折扣: ");scanf("%f",&p->discount);
			printf("票价: ");scanf("%f",&p->price);
			printf("乘员定额: ");scanf("%d",&p->Limited_number);
		    if(!(p->order=(linklist)malloc(sizeof(lineinfo))))
			{
				printf("分配空间出错");
	            a=getchar();
	            return 0;
			}
        	p->order->next=NULL;
    	   if(!(p->wait=(linkqueue*)malloc(sizeof(lineinfo))))
		   {
			   printf("分配空间出错");
	           a=getchar();
	           return 0;
		   }
           p->Remainder_tickets=p->Limited_number;
		   p->wait->front=NULL;
		   p->wait->rear=p->wait->front;
		   p->next=H->next;
	       H->next=p;
		}
		printf("已成功添加%d条航线\n",n);
	}
	else
	{
		do
		{
			printf("1 删除航班 0 修改航班信息，请选择：");
			scanf("%d",&d);
		}while(d!=1&&d!=0);
		if(d)
		{
			printf("请输入要删除的航班条数：");
			scanf("%d",&n);
			for(i=1;i<=n;i++)
			{
				printf("请输入第%d条要删除航班的航班号和飞行日期（年、月、日）！\n",i);
				scanf("%s%s%s%s",air_num,year,month,day);
				p=H->next;
				q=H;
				while(p)
				{			if(!(strcmp(air_num,p->air_num))&&!(strcmp(year,p->year))&&!(strcmp(month,p->month))&&!(strcmp(day,p->day)))
						break;
					q=p;
					p=p->next;
				}
				if(!p)
				{
					printf("没有您要删除的航线，请核对后再进行删除！\n");
					r++;   // 
				}
				else
				{
					q->next=p->next;
					printf("已成功删除第%d条航线\n",i);
					free(p);
				}
			}
			if(r<n)
				return 1;
			else
				return 0;
		}
		else
		{
		    printf("请输入要修改航班要修改航班的条数：");
		    scanf("%d",&n);
		    for(i=1;i<=n;i++)
			{
				printf("请输入第%d条要修改航班的航班号和此航班的飞行日期（年、月、日）\n",i);
			    scanf("%s%s%s%s",air_num,year,month,day);
			    p=H->next;
			    while(p)
				{
				    if(!(strcmp(air_num,p->air_num))&&!(strcmp(year,p->year))&&!(strcmp(month,p->month))&&!(strcmp(day,p->day)))
					    break;
				    p=p->next;
				}
			    if(!p)
				{
				     printf("没有您要修改的航线，请核对后再进行修改！\n");
				     r++;
				}
			   else
			   {
			   	    x=p->Limited_number;
				    printf("请输入此修改航班的航班信息！\n");
					printf("起点: ");scanf("%s",p->qdname);
					printf("终点: ");scanf("%s",p->zhname);
					printf("航班号: ");scanf("%s",p->air_num);
					printf("机型: ");scanf("%s",p->plane_num);
					printf("年、月、日: ");scanf("%s%s%s",p->year,p->month,p->day);
					printf("起飞时间: ");scanf("%s %s",p->qhour,p->qminute);
					printf("降落时间: ");scanf("%s %s",p->jhour,p->jminute);
					printf("折扣: ");scanf("%f",&p->discount);
					printf("票价: ");scanf("%f",&p->price);
					printf("乘员定额: ");scanf("%d",&p->Limited_number);
				    p->Remainder_tickets+=p->Limited_number-x;
					printf("您已成功修改了第%d条航线\n",i);
			   }	
			}
			if(r<n)
			    return 1;
			else
				return 0;
		}
	}
}
int File(lineair H,int t,int j)   /*文件操作*/
{
	int a=1,b=1,c=0;
	FILE *fp;
    lineinfo *p;
	Lnode *q;		
	if(t)
	{
		c=1;
		p=H->next;
		fp=fopen("航班信息.txt","a+");
		fprintf(fp,"%s%c%s%c%s%c%c%s%c%s%c%s%c%s%c%s%s%c%s%s%c%s%c%s%c%s%c%s%c","航班号",32,"起点",32,"终点",32,32,"机型",32,"年",32,"月",32,"日",32,"起时","分",32,"降时","分",32,"票价",32,"折扣",32,"定员",32,"余票量",32);
		while(p)
		{	
		    if((strcmp(nyear,p->year)<=0)&&(strcmp(nmonth,p->month)<=0)&&(strcmp(nday,p->day)<=0))
		            fprintf(fp,"%c%s%c%s%c%s%c%s%c%s%c%s%c%s%c%.2s%c%.2s%c%.2s%c%.2s%c%5.1f%c%3.1f%c%c%d%c%c%c%d%c",'\n', p->air_num,32,p->qdname,32,p->zhname,32,p->plane_num,32,p->year,'\\',p->month,'\\',p->day,32,p->qhour,':',p->qminute,32,p->jhour,':',p->jminute,32,p->price,32,p->discount,32,32,p->Limited_number,32,32,32,p->Remainder_tickets,'\n');
			p=p->next;
		}
		a=ferror(fp);
		fclose(fp); 
	}
	if(j)
	{
		c=1;
		fp=fopen("订票信息.txt","a+");
		p=H->next;
		fprintf(fp,"%s%c%s%c%s%c%s%c%s%c","姓名",'\t',"证件号码",'\t',"航班号",'\t',"订票量",'\t',"编号",'\n');
		while(p)
		{
			if(p->order->next)
			{
				q=p->order->next;
				while(q)
				{		fprintf(fp,"%c%s%c%s%c%s%c%d%c%s%c",'\n',q->name,'\t',q->IDnum,'\t',q->airnum,'\t',q->dpl,'\t',q->bianhao,'\n');
					q=q->next;
				}	
			}
			p=p->next;
		}
		b=ferror(fp);
		fclose(fp); 
	}
	return (a&&b&&c);
}
int main()
{ 
	int i,n,j,k,m=0,t=1;
	lineair H;
	printf("\n\t\t\t************************欢迎进入订票系统************************");
	printf("\n\t\t\t\t\t请输入今天日期：");
	scanf("%s%s%s",nyear,nmonth,nday); 
	do
	{
		j=0;
		k=0;
		printf("\n\t\t\t\t\t============订票系统菜单=============\n");
        printf("\t\t\t\t\t*************************************\n");
        printf("\t\t\t\t\t\t1.录入航线信息\n");
        printf("\t\t\t\t\t\t2.浏览并清除过期航线信息\n");
        printf("\t\t\t\t\t\t3.修改航班信息\n");
        printf("\t\t\t\t\t\t4.查询航线\n");
        printf("\t\t\t\t\t\t5.查询乘客信息\n");
        printf("\t\t\t\t\t\t6.办理订票业务\n");
        printf("\t\t\t\t\t\t7.办理退票业务\n");
        printf("\t\t\t\t\t\t0.退出系统\n");
        printf("\t\t\t\t\t*************************************\n");
        printf("\t\t\t\t\t请在0-7中选择您需要的服务按回车键结束：\n\n");
		scanf("%d",&i);
		switch(i)
		{case 1:{
			        printf("请输入要录入航线的条数：");
			        scanf("%d",&n);
			        if(Greatelist(H, n)) 
			           m=1;
				    if(File(H,m,j))
						printf("航班信息数据存储出错，请检查程序后重新录入信息！\n");
					break;
				}
		 case 2:
			{
				if(m)
					Display(H);
				else
					printf("请录入航班信息！\n");
				break;
			}
         case 3:
			 {
				 if(m)
					 k=Modify(H);
				 else
					 printf("请录入航班信息！\n");
				if(File(H,k,j))
					 printf("航班信息数据存储出错，请检查程序后重新录入信息！\n");
				 break;
			 }
         case 4:
			 {
				 if(m)
					 j=Searchair(H);
				 else
					 printf("请录入航班信息！\n");
				 if(File(H,m,j))
					 printf("数据存储出错，请检查程序！\n");
				 break;
			 }
	     case 5:
		     {
		     	if(m)
					Displaypas(H);
				else
					printf("无乘客信息\n");
				break;
		     } 
         case 6:
			 {
				 if(m)
					 j=Dinpiao(H);
				 else
					 printf("请录入航班信息！\n");
				 if(File(H,m,j))
					 printf("数据存储出错，请检查程序！\n");
				 break;
			 }
         case 7:
			 {
				 if(m)
				 {
					 printf("请输入您所退票的订单编号：");
					 j=Tuipiao(H);
				 }
				 else
					 printf("请录入航班信息！\n");
				 if(File(H,m,j))
					 printf("数据存储出错，请检查程序！\n");
				 break;
			 }
         case 0:t=0;break;
		 default:printf("对不起，没有您需要的服务，请重新选择！\n");
		}
	}while(t);
	printf("\n谢谢使用本系统，欢迎您下次再次使用！\n");
	free(H);
}

