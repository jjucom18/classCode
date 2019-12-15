#include"student.h"
#include"display.h"

Student *CreatNode(Student *pH)//创建一个新结点
{
    int id;
    char name;
    float score[3];
    Student *new = (Student *)malloc(sizeof(Student));
    system("clear");
    printf("*************************************************************************\n");
    printf("*\t\t\t学生成绩管理系统\t\t\t\t*\n");
    printf("*************************************************************************\n");
    printf("*\t\t请输入学生学号，姓名和英语，语文，数据结构的成绩\t*\n");
    printf("*************************************************************************\n");
    scanf("%d%s%f%f%f",&new->id,new->name,&new->score[0],&new->score[1],&new->score[2]);   
    return new;

}

Student *initlist()
{
    Student *pH = (Student *)malloc(sizeof(Student));
    if(  pH == NULL ) printf("内存分配失败\n");
    pH->next=NULL;
    return pH;
}

void addtail(Student *pH)
{   
    Student *newnew = CreatNode(pH);
    while(NULL != pH->next )
    {
        pH=pH->next;
    }
    pH->next = newnew;
    printf("\n**学生信息录入成功**\n\n");
    sleep(1);//程序挂起1s
}



void SaveInf(Student *pH)
{
    FILE* file = fopen("./StudentInf.dat","w");
    if( !file )
    {
        printf("打开文件失败!\n");
        return;
    }
    Student *p = pH->next;
    while( p != NULL)                     //遍历链表
    {
        fwrite(&p,1,sizeof(Student),file);
        p=p->next;
    }
    fclose(file);
    printf("\n文件保存成功!\n");
    sleep(3);
}

void ReadInf()
{
    Student *pH;
    Student *Pmove = (Student *)malloc(sizeof(Student));
    FILE *file = fopen("./StudentInf.dat","r");
    if( !file)
    {
        printf("文件打开失败!\n");
        return;
    }   
    while( !feof(file))
    {    
        fread(&Pmove,1,sizeof(Student),file);
        while(NULL != pH->next )
        {
            pH=pH->next;
        }
        pH->next = Pmove;
    }
    Pmove->next = NULL;
    fclose(file);
    printf("加载数据成功!\n");
    sleep(1);
}

void PrintfStudent(Student *pH)
{
    system("clear");
    Student *Pmove = (Student *)malloc(sizeof(Student));
    Pmove = pH->next;
    printf("*****************************************************************\n");   
    printf("*\t学号\t姓名\t英语\t语文\t数据结构\t\t*\n");
    printf("*****************************************************************\n");
    while(Pmove != NULL)
    {
        printf("*\t%d\t%s\t%.1f\t%.1f\t%.1f\t\t\t*\n",Pmove->id,Pmove->name,Pmove->score[0],Pmove->score[1],Pmove->score[2]);
        Pmove = Pmove->next;
    }
    printf("*****************************************************************\n");
    sleep(3);
    return;
}


int main()
{
    Student *list = initlist();
    char a;
    int n;
    while(1)
    {  
        menu();
        scanf("%d",&n);      
        switch(n)
        {
            case 1:addtail(list);break;
            case 2:PrintfStudent(list);break;
            case 3:SaveInf(list);break;
            case 4:ReadInf(list);break;
        }
    } 
return 0;
}
    