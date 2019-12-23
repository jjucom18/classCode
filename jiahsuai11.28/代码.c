#include<stdio.h>
#include<string.h>
void qiuchangxinxi();
void shiyongzhe();
void shiyong();
void add();
void add1();
void xiugai();
void xiugai1();
void shanchu();
void shanchu1(); 
void xianshi();
void xianshi1();
void chazhao();
void chazhao1(); 
void guanli();
void cha1();
void cha2();
struct basketball{
		int bianma;
			char dizhi[10];
				int changdihao;
					double price;
						int AN;
							char name[10];
}a[10];
struct yong{
	int id;
	char name[10];
	char dianhuahao[10];
	int shijian;
	int fangbian;
}b[10];
int n=0;
int k=0;
int main()
{
	int no=1;
	int num;
	while(no)
	{
		printf("*************************************\n");
		printf("           篮球场管理系统         *\n");
		printf("*************************************\n");
		printf("          1.球场信息                 \n\n");
		printf("          2.使用者信息               \n\n");
		printf("          3.使用管理                 \n\n");
		printf("          4.退出系统                 \n\n");
		scanf("%d",&num);
		switch(num)
		{
			case 1:qiuchangxinxi();
			       break;
			case 2:shiyongzhe();
			       break;
			case 3:guanli();
			       break;
			case 4:
			       {
				       printf("欢迎下次继续使用");
				       no=0;
				       return 0;
			       }
		}
	}
}
void qiuchangxinxi(){
	int no=1;
	int f;
	while(no)
	{printf("**************************************\n");
		printf("             球场信息                 \n");
		printf("**************************************\n");
		printf("            1.添加球场信息            \n\n");
		printf("            2.修改球场信息            \n\n");
		printf("            3.删除球场信息            \n\n");
		printf("            4.显示球场信息            \n\n");
		printf("            5.查找球场信息            \n\n");
		printf("            6.返回上一界面            \n\n");
		scanf("%d",&f);
		switch(f)
		{
			case 1:add();
			       		break;
			case 2:xiugai();
			       		break;
			case 3:shanchu();
			       		break;
			case 4:xianshi();
			       		break;
			case 5:chazhao();
			       		break;
			case 6:no=0;
			               break;
			       	}
			}
}
void add()//添加 
{
	int m;
	int b=1;
	char c;
	printf("现在录入数据\n\n");
	while(b)
			{
						
						for(m=n;m<10;m++)
						{printf("请输入你想录入的球场编码：\n");
							scanf("%d",&a[m].bianma);
							printf("请输入球场地址：\n\n");
							scanf("%s",a[m].dizhi);
							printf("请输入球场的号码：\n\n");
							scanf("%d",&a[m].changdihao);
							printf("请输入球场的使用价格：\n\n");
							scanf("%lf",&a[m].price);
							printf("请输入球场是否能够使用(是为1，否为0)\n\n");
							scanf("%d",&a[m].AN);
							printf("请输入使用者姓名，没有的话输入无：\n\n");
							scanf("%s",a[m].name); 
								n++;
								printf("是否继续录入？\n\n");
								scanf(" %c",&c);
								if(c=='Y')
								{b=1;
									break; 
								}
								else(c=='N');
								{	b=0;
									printf("输入完成！\n");
									break;
								}
						}
			}
}
void xiugai()//修改 
{int i,z;
	char x[20],c[20];
	printf("请输入您想修改的球场编码：\n");
	scanf("%d",&z);
	if(n<=0)
	{printf("没有任何使用信息，无法修改\n");
		return; 
	}
		else
				{
					for(i=0;i<n;i++)
					{
						if(z==a[i].bianma)
						{
							printf("请输入你想录入的球场编码：\n");
							scanf("%d",&a[i].bianma);
							printf("请输入球场地址：\n\n");
							scanf("%s",x);
							strcpy(a[i].dizhi,x);
							printf("请输入球场的号码：\n\n");
							scanf("%d",&a[i].changdihao);
							printf("请输入球场的使用价格：\n\n");
							scanf("%lf",&a[i].price);
							printf("请输入球场是否能够使用：(是为1，否为0)\n\n");
							scanf("%d",&a[i].AN);
							printf("请输入使用者姓名，没有的话输入无：\n\n");
							scanf("%s",c); 
							strcpy(a[i].name,c);
						}
						else
						{
							 printf("没有找到您要修改的球场信息\n");
						}
					}
				}
}
void shanchu()//删除 
{
		int i,s;
			int j;
				for(i=0;i<n;i++)
						{
									printf("请输入您想删除的球场编码：\n");
											scanf("%d",&s);
													if(s==a[i].bianma)
																{
																	printf("已经成功删除\n\n");
																	for(j=i;j<n;j++)
																	{
																		a[j]=a[j+1];
																		n--;
																	}
																	break;
																}else
																{
																	printf("没有该球场的具体信息\n\n");
																}
						}
				 
}
void xianshi()//显示 
{
	int i;
	printf("球场编码	球场地址    	球场号码   	使用价格     	 是否使用    	使用者姓名\n");
	printf("------------------------------------------------------------------------------------------\n");
	for(i=0;i<n;i++){
		printf("%d		%s		%d		%lf  		%d		%s\n\n",a[i].bianma,a[i].dizhi,a[i].changdihao,a[i].price,a[i].AN,a[i].name);	
	}
	return;
	 } 
void chazhao()//查找 
{
	int g,i;
	printf("请输入您想查看的球场编码：\n\n");
	scanf("%d",&g);
	for(i=0;i<n;i++)
	{
		if(g==a[i].bianma)
		{
			printf("球场编码	球场地址    	球场号码   	使用价格     	 是否使用    	使用者姓名\n");
			printf("------------------------------------------------------------------------------------------\n");
			printf("%d		%s		%d		%lf  		%d		%s\n\n",a[i].bianma,a[i].dizhi,a[i].changdihao,a[i].price,a[i].AN,a[i].name);
			return;	
		}
	}
		printf("没有查到球场的相关信息") ;
}
void shiyongzhe()
{
	int z;
	int no=1;
	while(no)
	{
		printf("************************************************\n");
		printf("*                使用者信息                    *\n");
		printf("************************************************\n\n");
		printf(" 1.添加使用者信息        2.修改使用者信息  \n\n");
		printf(" 3.删除使用者信息        4.显示使用者信息  \n\n");
		printf(" 5.查找使用者信息        6.返回主界面    \n");
		scanf("%d",&z);
		switch(z)
		{
			case 1:add1();
			       	break;
			case 2:xiugai1();
			       	break;
			case 3:shanchu1();
			       	break;
			case 4:xianshi1();
			       	break;
			case 5:chazhao1();
			       	break;
			case 6:no=0;
			       	break;
		}
	}
		
}
void add1()//添加 
{
		int m;
			int p=1;
				char c;
					printf("现在录入数据\n\n");
						while(p)
						{
							for(m=k;m<10;m++)
							{
								printf("请输入你想录入的使用者ID：\n");
								scanf("%d",&b[m].id);
								printf("请输入使用者姓名：\n\n");
								scanf("%s",b[m].name);
								printf("请输入使用者的电话号码：\n\n");
								scanf("%s",b[m].dianhuahao);
								printf("请输入使用者使用开始的时间：\n\n");
								scanf("%d",&b[m].shijian);
								printf("请输入使用者使用的球场的球场编码,没有请输入0\n\n");
								scanf("%d",&b[m].fangbian); 
								k++;
								printf("是否继续录入？\n\n");
								scanf(" %c",&c);
								if(c=='Y')
								{p=1;
									break; 
								}
								else(c=='N');
								{
									p=0;
									printf("输入完成！\n");
									break;
								}
							}
						}
}
void xiugai1()//修改 
{
	int m,z;
	char x[20],c[20];
	printf("请输入您想修改的使用者id：\n");
	scanf("%d",&z);
	if(k<=0)
	{
		printf("没有任何使用者信息，无法修改\n");
		return; 
	}
	else
	{
		for(m=0;m<k;m++)
		{
			if(z==b[m].id)
			{
				printf("请输入你想录入的使用者ID：\n");
				scanf("%d",&b[m].id);
				printf("请输入使用者姓名：\n\n");
				scanf("%s",x);
				strcpy(b[m].name,x);
				printf("请输入使用者的电话号码：\n\n");
				scanf("%s",c);
				strcpy(b[m].dianhuahao,c);
				printf("请输入使用者使用开始的时间：\n\n");
				scanf("%d",&b[m].shijian);
				printf("请输入使用者使用的球场的球场编码,没有请输入0\n\n");
				scanf("%d",&b[m].fangbian); 
			}
			else
			{
				printf("没有找到您要修改的球场信息\n");
			}
		}
	}
	 
}
void shanchu1()//删除
{
	int i,s;
	int j;
	for(i=0;i<k;i++)
	{
		printf("请输入您想删除的使用者的id：\n");
		scanf("%d",&s);
		if(s==b[i].id)
		{
			printf("已经成功删除\n\n");
			for(j=i;j<n;j++)
			{
				b[j]=b[j+1];
				k--;
			}
			break;
		}else
		{
			printf("没有该使用者的具体信息\n\n");
		}
	}
} 
void xianshi1()//显示 
{
	int i;
	printf("使用者id		使用者姓名    	使用者电话号码  	 使用者开始使用时间    	球场编号     \n");
	printf("------------------------------------------------------------------------------------------\n");
	for(i=0;i<k;i++){
		printf("%d		%s		%s		%d  		%d		\n\n",b[i].id,b[i].name,b[i].dianhuahao,b[i].shijian,b[i].fangbian);	
	}
	return;
} 
 
void chazhao1()//查找 
{
	int g,i;
	printf("请输入使用者的id：\n\n");
	scanf("%d",&g);
	for(i=0;i<k;i++)
	{
		if(g==b[i].id)
		{
			printf("使用者id		使用者姓名    	使用者电话号码  	 使用者开始使用时间    	球场编号     \n");
			printf("------------------------------------------------------------------------------------------\n");
			printf("%d		%s		%s		%d  		%d		\n\n",b[i].id,b[i].name,b[i].dianhuahao,b[i].shijian,b[i].fangbian);	
			return;	
		}
	}
	printf("没有查到使用者的信息\n\n") ;
}//void ruzu()
void guanli()
{
	int r;
	int no=1;
	while(no)
	{
		printf("************************************************\n");
		printf("*               使用管理                       *\n");
		printf("************************************************\n");
		printf("  1.输入球场编号查询         2.输入使用者ID查询  \n");
		printf("  3.返回主页面\n");
		scanf("%d",&r);
		switch(r)
		{
			case 1:cha1();
			       break;
			case 2:cha2();
			       break;
			case 3:no=0;
			       break;
		}
	}
		
}
void cha1()
{
	int g,i;
	printf("请输入您想查看的球场编码：\n\n");
	scanf("%d",&g);
	for(i=0;i<n;i++)
	{
		if(g==a[i].bianma)
		{
			if(a[i].AN==1)
			{
				printf("球场编号		使用者\n\n");
				printf("%d		%s\n\n",a[i].bianma,a[i].name);
				return; 
			}
			else
			{
				printf("没有任何使用信息\n\n");
			}
			return;	
		}
	}
	printf("没有查到球场的相关信息\n\n") ;
		 
}
void cha2()
{
	int g,i;
	printf("请输入使用者的id：\n\n");
	scanf("%d",&g);
	for(i=0;i<k;i++)
	{
		if(g==b[i].id)
		{
			if(b[i].fangbian!=0)
			{
				printf("球场编号		使用者\n\n");
				printf("%d		%s\n\n",b[i].fangbian,b[i].name);
				return; 
			}
			else
			{
				printf("没有任何使用信息\n\n");
							}
			return;	
		}
	}
	printf("没有查到使用者的信息\n\n") ;
}
