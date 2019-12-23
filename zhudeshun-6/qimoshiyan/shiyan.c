#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#define M 3000

char a[2][5]={{"男"},{"女"}};      //存储性别的二维数组 
typedef struct scholar
{
	int  number;
	char  name[20];
	int  sex;  //'0'代表男，'1'代表女 
	int  direction;
	char  production[50];
	struct scholar *next;
}sch;

sch *L;
typedef struct vexsinfo     //存放顶点信息的结构体
{
	int park;//访问的标志,park=0是未被访问过
	int num;     //文学体裁的编号
	char name[32];      //文学体裁的名称
	char introduction[256]; //文学体裁的介绍
}vexsinfo;

typedef struct MGraph       
{  
	int r;                  //记录最短路径访问过的体裁数目   
	int minrude;            //记录最短路径的长度 
	int min[50];            //记录最短路径经过的顶点信息    
	int a[50];              //记录路线的数目    
	vexsinfo vexs[50];      //存放顶点编号的数组，用vexsinfo结构体的变量vexsinfo定义                           
	int arc[50][50];        //存放两点之间权值的邻接矩阵
	int v,e;                //定点数和边数
} MGraph;

MGraph *T;
MGraph* CreateGraph()
{    
	MGraph *G;
	int i,j,k;
	G=(MGraph*)malloc(sizeof(MGraph));//初始化访问标志
	for(i=0;i<5;i++){
		G->vexs[i].park=0;
	}     //初始化顶点数目和路线数目
	G->v=5;
	G->e=6;//给体裁数组编号
	for(i=1;i<=G->v;i++)
		G->vexs[i].num=i;
	for(j=1;j<=5;j++)
		for(k=1;k<=5;k++)
		{
			G->arc[j][k]=M;
		} //初始化矩阵,赋予每条边权值,初始化顶点信息
	G->arc[1][2]=G->arc[2][1]=2;
	G->arc[2][3]=G->arc[3][2]=2;
	G->arc[2][4]=G->arc[4][2]=2;
	G->arc[3][4]=G->arc[4][3]=1;		
	G->arc[5][3]=G->arc[3][5]=1;
	G->arc[4][5]=G->arc[5][4]=3;			
	strcpy(G->vexs[1].name ,"诗歌");
	strcpy(G->vexs[2].name ,"散文");
	strcpy(G->vexs[3].name ,"剧小说");
	strcpy(G->vexs[4].name ,"小说");
	strcpy(G->vexs[5].name ,"戏剧");
	strcpy(G->vexs[1].introduction ,"诗歌是最早的出现的一种文学体裁，源于原始人的劳动呼声，是一种有声韵的文学。");
	strcpy(G->vexs[2].introduction ,"散文是指以文字为创作，审美对象的文学艺术体裁。注重表现作者的生活感受，抒情性强，感情真挚。");
	strcpy(G->vexs[3].introduction ,"剧小说结合了小说的自由叙述和剧本的排布严谨，两者的结合使其自由度高而且剧情严谨简便明了。");
	strcpy(G->vexs[4].introduction ,"小说是以塑造人物形象为中心，通过完整的故事情节和具体的环境描写，展示人物的思想情感和性格特征，从而广泛而深刻地反映社会生活的一种文学体裁。");
	strcpy(G->vexs[5].introduction ,"戏剧是一种综合性舞台艺术，是借助文学和音乐等艺术手段塑造舞台艺术形象，揭示社会矛盾，反应社会生活的一种文学体裁。");
	return G;
	getchar();
	getchar();

} //一共5种文学体裁，6条路径
void RudeGraph(MGraph *G,int b,int w,int k,int sum)
{
	system("clear");
	G->minrude=1000; 
	int p,j,n;
	if(b==w) {
		for(p=0;p<k;p++){
			printf("%d->",G->a[p]);
		}
		printf("%d  ",G->a[k]);
		printf("关系长度为：%d\n",sum);
		if(sum<G->minrude){
			G->r=k;
			G->minrude=sum;
			for(p=0;p<=k;p++){
				G->min[p]=G->a[p];
			}
		}
		return ;

	}
	else{
		for(j=1;j<=5;j++){
			if(G->arc[b][j]<3000&&G->vexs[j].park==0)
			{
				k++;
				G->a[k]=j;
				sum+=G->arc[b][j];             
				G->vexs[j].park=1;
				RudeGraph(G,j,w,k,sum);    //通过递归对所有路径进行深度搜索
				k--;                       //递归返回这一层后对顶点信息进行重新初始化
				G->vexs[j].park=0; 
				sum-=G->arc[b][j];
			}
		}
	}
	return; 
}

void menu1()
{
	system("clear");
	printf("**************************\n");
	printf("***    文学研究系统    ***\n");
	printf("**************************\n");
	printf("1.文学体裁查询\n");
	printf("2.文学体裁接近度查询\n");
	printf("3.退出\n");
	printf("4.输入学者信息\n");
	printf("5.按学者编号查询学者信息\n");
	printf("6.按学者编号删除学者信息\n");
	printf("7.按学者编号修改学者信息\n");
	printf("8.显示所有学者信息\n");
}

void menu2()
{
	system("clear");
	printf("1.修改编号\n");
	printf("2.修改姓名\n");
	printf("3.修改性别\n");
	printf("4.修改研究方向\n");
	printf("5.修改作品\n"); 
}

void relation()
{
	system("clear");
	int i;
	printf("**********************************\n");
	printf("            5种文学体裁关系如下图                          \n");
	printf("                   [诗歌]                                  \n");
	printf("                     ||                                    \n");
	printf("                   [散文]                                  \n");
	printf("                 //      \\                                \n");
	printf("          [剧小说]   ==   [小说]                           \n");
	printf("                 \\      //                                \n");
	printf("                   [戏剧]                                  \n");
	printf("*********************************\n");
	printf("文学研究里共有以下五种体裁：\n");
	for(i=1;i<=5;i++){
		printf("%d.",T->vexs[i].num);
		printf("%s:    ",T->vexs[i].name);
		printf("%s\n",T->vexs[i].introduction);
	}
	getchar();
	getchar();
}

void short_path()
{
	system("clear");
	int i,p;
	printf("**********************************\n");
	printf("请分别输入你想查询的两种文学体裁的编号，系统会给出两者之间不同的关系及最接近的关系：\n");
	printf("1.诗歌 2.散文 3.剧小说 4.小说 5.戏剧\n");
	int b,w;//初始化访问标志
	for(i=0;i<5;i++)
	{
		T->vexs[i].park=0;
	}
	scanf("%d %d",&b,&w);
	while(b<1||b>5||w<1||w>5){			 
		printf("输入错误，请重新输入:\n");
		scanf("%d %d",&b,&w);
	}
	if(b==w){
		printf("请重新输入：\n");
		scanf("%d %d",&b,&w);
	}
	else{
		T->a[0]=b;
		T->vexs[b].park=1;
		printf("从体裁%d到体裁%d共有如下关系：\n",b,w);
		RudeGraph(T,b,w,0,0);
		printf("最接近关系为：\n");
		for(p=0;p<T->r;p++)
		{         
			printf("%d->",T->min[p]);
		}
		printf("%d  ",T->min[T->r]);
		printf("关系长度：%d\n",T->minrude);
		T->minrude=100;     //重新初始化最短路径长度
	}
	getchar();
	getchar();
}

void  input()
{
	int n;
	sch *p=NULL,*a=NULL;
	p=(struct scholar *)malloc(sizeof(struct scholar));
	p->next=NULL;
	L=p;
	printf("请输入学者数量\n"); 
	scanf("%d",&n);
	while(n--)
	{
		a=(struct scholar *)malloc(sizeof(struct scholar));
		printf("请输入学者编号：");
		scanf("%d",&a->number);
		getchar();
		printf("请输入学者姓名：");
		gets(a->name);
		printf("请输入学者性别(0为男，1为女)：");
		scanf("%d",&a->sex);
		printf("请输入学者主要研究方向(1为诗歌，2为散文，3为剧小说，4为小说，5为戏剧)：");
		scanf("%d",&a->direction);
		getchar();
		printf("请输入学者作品：");
		scanf("%s",&a->production);
		p->next=a;
		p=a;
	}
	p->next=NULL;
}

void output()
{
	system("clear");
	sch *p;
	p=L->next;
	printf("学者编号\t姓名\t\t性别\t研究方向\t作品\n");
	while(p!=NULL)
	{
		printf("%d\t\t%s\t\t%s\t%s\t\t%s\n",p->number,p->name,a[p->sex],T->vexs[p->direction].name,p->production);
		p=p->next;
	}
	getchar();
	getchar();
}

void check()
{
	system("clear");
	int num,flag=0;
	sch *p;
	printf("请输入需要查询的学者编号：\n");
	scanf("%d",&num);
	p=L->next;
	while(p!=NULL)
	{
		if(p->number==num)
		{
			flag=1;
			break;
		}
		p=p->next;
	}
	if(flag!=0)
	{
		printf("学者编号\t姓名\t\t性别\t研究方向\t作品\n");
		printf("%d\t\t%s\t\t%d\t%s\t\t%s\n",p->number,p->name,p->sex,T->vexs[p->direction].name,p->production);
	}
	else
		printf("查找失败！无此学者!\n");
	getchar();
	getchar();
}

void  change()
{
	system("clear");
	sch *p;
	int num;
	printf("请输入要修改的学者编号:\n");
	scanf("%d",&num);
	getchar();
	p=L->next;
	while(p!=NULL)
	{
		if(p->number==num)
		{
			menu2();
			char c;
			c=getchar();
			switch(c)
			{
				case '1':
					printf("请输入新的学者编号:");
					scanf("%d",&p->number);
					break;
				case '2':
					printf("请输入新的学者姓名:");
					scanf("%s",&p->name);
					break;
				case '3':
					printf("请输入新的学者性别:");
					scanf("%d",&p->sex);
					break;
				case '4':
					printf("请输入新的学者研究方向:");
					scanf("%d",&p->direction);
					break;
				case '5':
					printf("请输入新的学者作品:");
					scanf("%s",&p->production);
					break;
			}
			printf("修改成功");
			break;
		}
		p=p->next;
	}
	getchar();
	getchar();
}

void del()
{
	system("clear");
	sch *p,*a=NULL;
	int num;
	p=L;
	a=p->next;
	printf("请输入要删除信息的学者的学者编号：");
	scanf("%d",&num);
	while(a)
	{
		if(a->number==num)
		{
			p->next=a->next;
			printf("删除成功!");
			break;
		}
		p=a;
		a=p->next;
	}
	getchar();
	getchar();
}

int main() //主函数
{
	T=CreateGraph();
	while(1)   //系统界面
	{
		char c;
		menu1();
		printf("请选择你需要的功能：\n");
		c=getchar();
		switch(c)
		{
			case '1':
				relation();
				break;
			case '2':
				short_path();
				break;
			case '3':
				printf("感谢使用本系统，欢迎您下次使用！\n");
				exit(0);
			case '4':
				input();
				break;
			case '5':
				check();
				break;
			case '6':
				del();
				break;
			case '7':
				change();
				break;
			case '8':
				output();
				break;
		}
	}
	return 0;
}
