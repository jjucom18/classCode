#include<stdio.h>
#include<string.h>                                      /*头文件。*/
int SIZE;                                               /*宏定义。*/
int CLASS;

struct student                /*定义一个结构体数组，包含学生信息。*/
 {

char name[9] ;
char sex[4] ;
int number;
int count;
int score;
 } stu[300] ;
void main()                                    /*主函数，选择界面。*/
{

void start() ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
printf("######################################\n") ;
printf("#             学生考勤系统           #\n") ;
printf("#               欢 迎 您             #\n") ;
printf("######################################\n") ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
printf("######################################\n") ;
printf("\t请输入班级人数：\n") ;
printf("######################################\n") ;
scanf("%d",&SIZE) ;
printf("\n") ;
printf("######################################\n") ;
printf("\t请输入课程节数：\n") ;
printf("######################################\n") ;
scanf("%d",&CLASS) ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
start() ;
	  } 
void start()                     /*主函数的辅助函数——start函数。*/
{

char x;
void found() ;
void search() ;
void add() ;
void mark() ;
printf("######################################\n") ;
printf("#   请选择所需功能，输入对应数字：   #\n") ;
printf("#           1.建立学生列表           #\n") ;
printf("#           2.查找学生信息           #\n") ;      
printf("#           3.模拟考勤过程           #\n") ;
printf("#           4.计算考勤分数           #\n") ;
printf("#           5.退出                   #\n") ;
printf("#                                    #\n") ;
printf("######################################\n") ;
scanf("%S",&x) ;
switch(x)            /*利用switch函数实现子函数的选择功能。*/
{

case'1':found() ;break;
case'2':search() ;break;
case'3':add() ;break;
case'4':mark() ;break;
case'5':break;
default :printf("****输入有误，请重输:\n") ;start() ;
 } 
} 
void found()        /*第一个子函数——found函数，用于建立学生列表。*/
{

int a;
printf("####################\n") ;
printf("      开始建表。\n") ;
printf("####################\n") ;
FILE *fp;
for(a=0;a<SIZE;a++)          /*运用for循环，逐次输入学生信息。*/
{

printf("请输入第%d个学生的个人信息：\n",a+1) ;
printf("姓名：") ;
scanf("%s",stu[a] .name) ;
printf("性别：") ;
scanf("%s",stu[a] .sex) ;
printf("学号：") ;
scanf("%d",&stu[a] .number) ;
stu[a] .count=0;
stu[a] .score=0;
} 
fp=fopen("stud","w") ;          /*新建一个文件，运用for函数将学生信息写入文件。*/
for(a=0;a<SIZE;a++) 
{

if(fwrite(&stu[a] ,sizeof(struct student) ,1,fp) !=1) 
printf("文件输入错误。\n") ;
} 
fclose(fp) ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
printf("建表如下：\n") ;
fp=fopen("stud","r") ;                /*读取新建的文件，并输出。*/
printf("姓名 \t性别 \t学号 \t缺课数 \t考勤分数 \n") ;
printf("----------------------------------------------\n") ;
for(a=0;a<SIZE;a++) 
{

fread(&stu[a] ,sizeof(struct student) ,1,fp) ;
printf("%s \t%s \t%d \t%d \t%d\n",stu[a] .name,stu[a] .sex,stu[a] .number,stu[a] .count,stu[a] .score) ;
} 
fclose(fp) ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
printf("#######################################\n") ;
printf("#               记录完毕              #\n") ;
printf("#             欢迎下次再来。          #\n") ;
printf("#######################################\n") ;
start() ;                     /*返回主函数的辅助函数,即主菜单。*/
} 
void search()                            /*第二个子函数——search函数，用于查询学生信息。*/
{

char b;
void search1() ;
void search2(); 
printf("****************************************\n") ;
printf("  请选择:\n") ;
printf("             1.按姓名查找。\n") ;
printf("             2.按学号查找。\n") ;
printf("****************************************\n") ;
scanf("%s",&b) ;
switch(b)                          /*运用switch函数，构成选择结构，可供选择查询类型。*/
{

case'1':search1() ;break;     /*进入第1种查询类型的函数。*/
case'2':search2() ;break;     /*进入第2种查询类型的函数。*/
default :printf("****输入有误，请重输：") ;search() ;
} 
printf("\n") ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
printf("#######################################\n") ;
printf("#               查找完毕              #\n") ;
printf("#             欢迎下次再来。          #\n") ;
printf("#######################################\n") ;
start() ;                      /*返回主函数的辅助函数,即主菜单。*/
} 
void search1()                    /*第1种查询类型的函数。*/
{

int c;
char student_name[9] ;
FILE *fp;                /*打开已建立的文件并将其输出到屏幕上。*/
fp=fopen("stud","r") ;
printf("姓名 \t性别 \t学号 \t缺课数 \t考勤分数 \n") ;
printf("----------------------------------------------\n") ;
for(c=0;c<SIZE;c++) 
{

fread(&stu[c] ,sizeof(struct student) ,1,fp) ;
printf("%s \t%s \t%d \t%d \t%d\n",stu[c] .name,stu[c] .sex,stu[c] .number,stu[c] .count,stu[c] .score) ;
} 
fclose(fp) ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
printf("请输入要查询学生姓名：") ;
scanf("%s",student_name) ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
for(c=0;c<SIZE;c++)           /*运用for循环和strcmp函数逐个比较输入的姓名与列表中学生的姓名，找到相同的后输出该学生的信息。*/
{

if(strcmp(student_name,stu[c] .name) ==0) 
{

printf("已查到*******************************************\n") ;
printf("姓名：%s 性别：%s 学号：%d 缺课数：%d\n",stu[c] .name,stu[c] .sex,stu[c] .number,stu[c] .count) ;
			} 
    } 
} 
void search2()                             /*第2种查询类型的函数。*/
{

int c;
int d;
FILE *fp;
fp=fopen("stud","r") ;
printf("姓名 \t性别 \t学号 \t缺课数 \t考勤分数 \n") ;
printf("----------------------------------------------\n") ;
for(c=0;c<SIZE;c++) 
{

fread(&stu[c] ,sizeof(struct student) ,1,fp) ;
printf("%s \t%s \t%d \t%d \t%d\n",stu[c] .name,stu[c] .sex,stu[c] .number,stu[c] .count,stu[c] .score) ;
} 
fclose(fp) ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
printf("请输入要查询学生学号：") ;
scanf("%d",&d) ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
for(c=0;c<SIZE;c++)       /*同第1种查询类型的函数，用for循环逐个比较输入的学号与列表中学生的学号，找到相同的后输出该学生的信息。*/
{

if(d==stu[c] .number) 
{

printf("已查到*********************************************\n") ;
printf("姓名：%s 性别：%s 学号：%d 缺课数：%d\n",stu[c] .name,stu[c] .sex,stu[c] .number,stu[c] .count) ;
		  } 
   } 
} 
void add()            /*第三个子函数——add函数，用于模拟考勤过程。*/
{

int e,f,y;
struct name                  /*再建立一个叫name的结构体数组。*/
{

char nam[9] ;
} na[300] ;
FILE *fp;
fp=fopen("stud","r") ;    /*打开已建立的文件并将其输出到屏幕上。*/
for(e=0;e<SIZE;e++) 
{

fread(&stu[e] ,sizeof(struct student) ,1,fp) ;
printf("%s \t%s \t%d \t%d \t%d\n",stu[e] .name,stu[e] .sex,stu[e] .number,stu[e] .count,stu[e] .score) ;
} 
fclose(fp) ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
printf("***************************\n") ;
printf("       模拟考勤开始。\n") ;
printf("***************************\n") ;
for(e=0;e<CLASS;e++)      /*运用for循环的嵌套，向name结构体中输入姓名，再依次与列表中的学生姓名逐个比较。*/
{

printf("请输入第%d节课未到的学生姓名并以“over”结束：",e+1) ;
for(y=0;y<=SIZE;y++) 
{

scanf("%s",na[y] .nam) ;
for(f=0;f<SIZE;f++) 
{

if(strcmp(na[y] .nam,stu[f] .name) ==0)  /*如果输入的姓名与某个学生姓名相同，在其count的信息中加1。*/
stu[f] .count++;
} 
if(strcmp(na[y] .nam,"over") ==0)     /*循环结束，遇到 "over"，退出循环。*/
break;
} 
} 
fp=fopen("stud","w") ;           /*将新的列表数据写入原文件中.*/
for(e=0;e<SIZE;e++) 
{

if(fwrite(&stu[e] ,sizeof(struct student) ,1,fp) !=1) 
printf("文件输入错误。\n") ;
} 
fclose(fp) ;
printf("\n") ;
printf("\n"); 
printf("\n") ;
printf("\n") ;
printf("模拟考勤完毕，结果如下：\n") ;
fp=fopen("stud","r") ;      /*打开更新的文件并将其输出到屏幕上。*/
printf("姓名 \t性别 \t学号 \t缺课数 \n") ;
printf("-------------------------\n") ;
for(f=0;f<SIZE;f++) 
{

fread(&stu[f] ,sizeof(struct student) ,1,fp) ;
printf("%s \t%s \t%d \t%d\n",stu[f] .name,stu[f] .sex,stu[f] .number,stu[f] .count) ;
} 
fclose(fp) ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
printf("#######################################\n") ;
printf("#               考勤完毕              #\n") ;
printf("#             欢迎下次再来。          #\n") ;
printf("#######################################\n") ;
start() ;                              /*返回主函数的辅助函数。*/
} 
void mark()          /*第四个子函数——mark函数，用于计算考勤分数。*/
{

int g;
FILE *fp;                  /*打开更新的文件并将其输出到屏幕上。*/
fp=fopen("stud","r+") ;
printf("姓名 \t性别 \t学号 \t缺课数\n") ;
printf("----------------------------------------------\n") ;
for(g=0;g<SIZE;g++) 
{

fread(&stu[g] ,sizeof(struct student) ,1,fp) ;
printf("%s \t%s \t%d \t%d\n",stu[g] .name,stu[g] .sex,stu[g] .number,stu[g] .count) ;
} 
printf("\n") ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
printf("********************************\n") ;
printf("           评分开始。\n") ;
printf("********************************\n") ;
for(g=0;g<SIZE;g++)                  /*用for循环实现评分过程。*/
{

stu[g] .score=(100-stu[g] .count*5) ;        /*缺一节课扣五分。*/
if(stu[g] .score<0) 
stu[g] .score=0;
} 
fclose(fp) ;
fp=fopen("stud","w") ;      /*将更新的学生列表信息写入原文件中。*/
for(g=0;g<SIZE;g++) 
{

if(fwrite(&stu[g] ,sizeof(struct student) ,1,fp) !=1) 
printf("文件输入错误。\n") ;
} 
fclose(fp) ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
printf("\n") ;
printf("结果如下：\n") ;
fp=fopen("stud","r") ;     /*打开更新的文件并将其输出到屏幕上。*/
printf("姓名 \t性别 \t学号 \t缺课数 \t考勤分数 \n") ;
printf("----------------------------------------------\n") ;
for(g=0;g<SIZE;g++) 
{

fread(&stu[g] ,sizeof(struct student) ,1,fp) ;
printf("%s \t%s \t%d \t%d \t%d\n",stu[g] .name,stu[g] .sex,stu[g] .number,stu[g] .count,stu[g] .score) ;
} 
fclose(fp) ;
printf("\n") ;
printf("\n") ;
printf("\n") ; 
printf("\n") ;
printf("#######################################\n") ;
printf("#               评分完毕              #\n") ;
printf("#             欢迎下次再来。          #\n") ;
printf("#######################################\n") ;
start() ;                     /*返回主函数的辅助函数,即主菜单。*/
 }
