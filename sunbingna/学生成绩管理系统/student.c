#include"student.h"

Node *CreatNode()//创建一个新结点
{
    Node *new = (Node *)malloc(sizeof(Node));
    system("clear");
    printf("*************************************************************************\n");
    printf("*\t\t\t学生成绩管理系统\t\t\t\t*\n");
    printf("*************************************************************************\n");
    printf("*\t\t请输入学生学号，姓名和英语，语文，数据结构的成绩\t*\n");
    printf("*************************************************************************\n");
    scanf("%d%s%f%f%f",&new->data.id,new->data.name,&new->data.score[0],&new->data.score[1],&new->data.score[2]);   
    return new;
}

Node*initlist()
{
    Node *pH = (Node *)malloc(sizeof(Node));
    if(  pH == NULL ) printf("内存分配失败\n");
    pH->next=NULL;
    return pH;
}

void addtail()//尾插法
{   
    Node *newnew = CreatNode();
    Node *p = pH;
    while(NULL != p->next )
    {
        p=p->next;
    }
    p->next = newnew; 
    printf("\n**学生信息录入成功**\n\n");
    sleep(1);//程序挂起1s
}

void SaveInf()
{
    Node *p = pH->next;  
    FILE* file = fopen("./StudentInf.dat","wb");
    if( !file )
    {
        printf("打开文件失败!\n");
        return;
    }   
    while( p != NULL)                     //遍历链表
    {
        fwrite(p,sizeof(Node),1,file);
        p=p->next;
    }
    fclose(file);
    printf("\n文件保存成功!\n");
    sleep(2);
}

void ReadInf()
{
    Node *p = pH;
    Node *Pmove;//临时变量
    FILE *file = fopen("./StudentInf.dat","rb");
    if( file == NULL)
    {
        printf("文件打开失败!\n");
        sleep(1);
        return;
    }
    Pmove = (Node *)malloc(sizeof(Node));
    fread(Pmove,sizeof(Node),1,file);
    while ( !feof(file))  //一直读到文件末尾，尾插法
    {
        p->next = Pmove;
        p = Pmove;
/*         while(NULL != p->next )
        {
            p=p->next;
        }
        p->next = Pmove;   */
        Pmove = (Node *)malloc(sizeof(Node));//重新分配内存
        fread(Pmove, sizeof(Node), 1, file);
    } //while循环结束
    p->next = NULL; 
    printf("加载数据成功!\n");
    
    fclose(file);  
    sleep(2);
}

void PrintfStudent()
{
    system("clear");
    SortId();
    Node *Pmove = (Node *)malloc(sizeof(Node));
    Pmove = pH->next;
    printf("*****************************************************************\n");   
    printf("*\t学号\t姓名\t英语\t语文\t数据结构\t\t*\n");
    printf("*****************************************************************\n");
    if(Pmove == NULL)
    {
        printf("请先录入信息!\n");
        return;
    }
    while(Pmove != NULL)
    {
        printf("*\t%d\t%s\t%.1f\t%.1f\t%.1f\t\t\t*\n",Pmove->data.id,Pmove->data.name,Pmove->data.score[0],Pmove->data.score[1],Pmove->data.score[2]);
        Pmove = Pmove->next;
    }
    printf("*****************************************************************\n");
    sleep(3);
    return;
}

void SearchId()
{
    Node *p = (Node *)malloc(sizeof(Node));
    p = pH->next;
    printf("请输入要查找学生学号: ");
    int id;
    scanf("%d",&id);
    while(p != NULL)
    {
        if(p->data.id == id)
        {
            system("clear");
            printf("*****************************************************************\n");   
            printf("*\t学号\t姓名\t英语\t语文\t数据结构\t\t*\n");
            printf("*****************************************************************\n");
            printf("*\t%d\t%s\t%.1f\t%.1f\t%.1f\t\t\t*\n",p->data.id,p->data.name,p->data.score[0],p->data.score[1],p->data.score[2]);
            printf("*****************************************************************\n");
            sleep(2);
            return;
        }
        else
        {
            if(p->next == NULL){
                printf("\n查无此人!\n");
                sleep(2);
                return;
            }
            else{
            p = p->next;
            }
        }
    }
}

void SearchName()
{
    Node *p = (Node *)malloc(sizeof(Node));
    p = pH->next;
    char name[20];
    printf("请输入查找学生姓名:");
    scanf("%s",name);
    while(p != NULL)
    {
       
        if(strcmp(p->data.name,name) == 0)
        {
            system("clear");
            printf("*****************************************************************\n");   
            printf("*\t学号\t姓名\t英语\t语文\t数据结构\t\t*\n");
            printf("*****************************************************************\n");
            printf("*\t%d\t%s\t%.1f\t%.1f\t%.1f\t\t\t*\n",p->data.id,p->data.name,p->data.score[0],p->data.score[1],p->data.score[2]);
            printf("*****************************************************************\n");
            sleep(2);
            return;
        }
        else
        {
            if(p->next == NULL){
                printf("查无此人!\n");
                sleep(2);
                return;
            }
            else{
            p = p->next;
            }
        }       
    }
}

void SearchChoice()
{
    int a;
    system("clear");
    printf("*****************************************************************\n");
    printf("*\t\t\t学生成绩管理系统\t\t\t*\n");
    printf("*****************************************************************\n");
    printf("*\t\t\t请选择\t\t\t\t\t*\n");
    printf("*****************************************************************\n");
    printf("*\t\t\t1.按学号进行查找\t\t\t*\n");
    printf("*\t\t\t2.按姓名进行查找\t\t\t*\n");
    printf("*****************************************************************\n");
    scanf("%d",&a);
    switch (a)
    {
    case 1:
        SearchId();
        break;
    case 2:
        SearchName();
        break;
    
    default:
        break;
    }
}

void Change()
{
    char name[20];
    int id;
    float Chinese,English,data;
    Node *p = pH->next;
    printf("请输入要修改的学生姓名:");
    scanf("%s",name);
    while(p != NULL)
    {
       
        if(strcmp(p->data.name,name) == 0)
        {
            system("clear");
            printf("*****************************************************************\n");   
            printf("*\t学号\t姓名\t英语\t语文\t数据结构\t\t*\n");
            printf("*****************************************************************\n");
            printf("*\t%d\t%s\t%.1f\t%.1f\t%.1f\t\t\t*\n",p->data.id,p->data.name,p->data.score[0],p->data.score[1],p->data.score[2]);
            printf("*****************************************************************\n");
            printf("请输入修改后的学生信息:\n");
            printf("*************************************************************************\n");
            printf("*\t\t请输入学生学号，姓名和英语，语文，数据结构的成绩\t*\n");
            printf("*************************************************************************\n");
            scanf("%d%s%f%f%f",&id,name,&Chinese,&English,&data);   
            p->data.id = id;
            memcpy(p->data.name,name,sizeof(Student));
            p->data.score[0] = Chinese;
            p->data.score[1] = English;
            p->data.score[2] = data;
            //sleep(2);
            break;
        }
        else
        {
            if(p->next == NULL){
                printf("查无此人!\n");
                sleep(2);
                return;
            }
            else{
            p = p->next;
            }
        } 
    }         
    printf("学生信息修改成功!\n");
    sleep(2);
}

void Delete()
{
    char name[20];
    int flag;
    Node *pfront = pH;
    Node *p = pH->next; 
    printf("请输入要删除的学生姓名:");
    scanf("%s",name);
     while(p != NULL)
    {
        if(strcmp(p->data.name,name) == 0)
        {
            system("clear");
            printf("\t\t学生原信息如下\t\t\n");
            printf("*****************************************************************\n");   
            printf("*\t学号\t姓名\t英语\t语文\t数据结构\t\t*\n");
            printf("*****************************************************************\n");
            printf("*\t%d\t%s\t%.1f\t%.1f\t%.1f\t\t\t*\n",p->data.id,p->data.name,p->data.score[0],p->data.score[1],p->data.score[2]);
            printf("*****************************************************************\n");
            printf("\t\t\t请选择\t\t\t\t\t\n");
            printf("\t\t1.确认删除\t2.取消删除\t\t\t\n");
            scanf("%d",&flag);
            switch (flag)
            {
            case 1:
                pfront->next = p->next;
                free(p);
                printf("删除成功!\n");
                sleep(2);
                return;break;
            case 2:
                return;break;
            default:
                break;
            }
        }
        else{
            if(p->next == NULL){
                printf("查无此人!\n");
                sleep(2);
                return;
            }
            else{
                p = p->next;
                pfront = pfront->next;
            }           
        }  
    }
} 

void SortId()//冒泡排序法
{
	Node *tail=pH,*p;
	Student t;
	while(tail->next != NULL)//让tail指针指向链表结尾
		tail=tail->next;
	while(pH->next!=tail)//控制冒泡的次数
	{
		p=pH->next;
		while(p->next != tail)//每一次的循环比较
		{
			if(p->data.id> p->next->data.id)
			{
				t=p->data;
				p->data=p->next->data;
				p->next->data=t;
			}
			p=p->next;
		}
		if(p->data.id> p->next->data.id)//尾结点的比较
		{
				t=p->data;
				p->data=p->next->data;
				p->next->data=t;
		}
		tail=p;//尾指针前移一个
	}
     
	printf("已排序完成!\n");
    sleep(1);
}

void Quit()
{
    SaveInf();
    exit(0);
}


void Choice()
{
    int n;
    while(1)
    {  
        menu();
        scanf("%d",&n);      
        switch(n)
        {
            case 1:addtail();break;
            case 2:PrintfStudent();break;
            case 3:SaveInf();break;
            case 4:ReadInf();break;
            case 5:SearchChoice();break;
            case 6:Change();break;
            case 7:Delete();break;
            case 8:Quit();break;
            default: break;
        }
    } 
}

int main()
{
    pH = initlist();
    char a;
    int n,m;
    
    while(1)
    {
        stackmenu();
        scanf("%d",&m); 
        switch (m)
        {
            case 1:stackchoice();
                break;
            case 2:queuechoice();
                break;
            
            default:
                break;
        }
    }
    return 0;
}
    