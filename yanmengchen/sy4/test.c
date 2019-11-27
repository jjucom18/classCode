nclude <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include <ctype.h>


#define MAX_SIZE_PARK 5  //停车场的最大容量
#define MAX_SIZE_SERVICE_ROAD 15 //便道的容量
#define OK  1
#define ERROR 0 


typedef char Elementtype;
typedef char Status;


//车辆信息据结构定义
typedef struct car
{
    Elementtype car_licence[20];   //车辆的牌照号码
int timearv_hours;    //车辆进入停车场的时间,小时
int timearv_mins;     //车辆进入出停车场的时间,分钟
int timelev_hours;
int timelev_mins;
}Car_informa;


//栈的定义 
typedef struct stack
{
    	Car_informa data[MAX_SIZE_PARK];
	Car_informa data_temp[MAX_SIZE_PARK];//定义一个临时空间用来存储因让车从停车场退出去的车
int top;
}S_node;




//队列的定义，链表的结构
typedef struct queue
{ 
    Car_informa data[MAX_SIZE_SERVICE_ROAD];
struct queue *next;   

}Q_node;


//对栈的操作 
Status init(S_node *head);
Status stack_is_empty(S_node head);
Status stack_is_full(S_node head);
Status stack_push(S_node *head,Car_informa car_msg);
Status stack_pop(S_node *head,S_node *temp_head,Car_informa car_msg,Q_node* q_head,int count);


//对队列的操作
Status init_queue(Q_node **q_head);
Status queue_push(Q_node* q_head,Car_informa car_msg);


void printf_stack(S_node *head,Car_informa car_msg);//打印停车场的信息
void printf_queue(Q_node *q_head ,Car_informa car_msg);


int  length(Q_node *q_head);


Q_node *q_head;//(全局变量)定义一个队列的头指针




int main()
{

system("clear");
int ret;

S_node head;//定义一个名为head的栈
S_node temp_head;//定义一个临时的栈，用来存储停车场退出去的车

Car_informa car_msg;//定义汽车信息结构体名为car_msg
//Q_node *q_head;//定义一个队列的头指针

ret = init_queue(&q_head);
if(ERROR == ret)
{
perror("初始化队列失败\n");
exit(1);
} 

ret = init(&temp_head);
if(ERROR == ret)
    {
perror("初始化临时栈空间失败\n");
exit(2);
}
    
ret = init(&head);
if(ERROR == ret)
{
        perror("初始化栈空间失败"); 
exit(1);
}

ret = stack_is_empty(head);
if( ERROR == ret)
{
   perror("停车场不为空，初始化栈空间失败");
        exit(3); 
}
int count = -1;
for(;;)
{
switch(menu_select())
{
case 1:
{ 
   stack_push(&head,car_msg);
   break;
}
case 2:
{   
   count++;//每次操作一次进行一次加1
   stack_pop(&head,&temp_head,car_msg,q_head,count);
break;
}
case 3:
{   
   //printf_queue(q_head,car_msg);
printf_stack(&head,car_msg); 
break;

}
case 4:
{   
        exit(1);
}

}


}


return 0;
}


menu_select()
{
int c;
char str[20];
	printf("-------------- 欢迎来到停车场系统 -------------\n");
	printf("--------------我们每小时只收取3元钱------------\n");
	printf("-----------------1. 进入停车场-----------------\n"); 
    	printf("-----------------2. 离开停车场-----------------\n");
    	printf("-----------------3. 查看停车场的信息-----------\n");
	printf("-----------------4. 退出系统-------------------\n");
	printf("-----------------------------------------------\n");
    
do
    {
   	printf("请输入数字 1 ~ 4 :\n");
        scanf ("%s",&str);
   	c = atoi(str);//将字符串转换为整形
}while(c < 1 || c > 4);

return c;
}


//初始化栈空间
Status init(S_node *head)
{
//在栈的模型中，空栈的top通常为-1
head -> top = -1;
return OK;
} 


//判断栈空间是否为空
Status stack_is_empty(S_node head)
{ 
     return head.top == -1 ? OK : ERROR;
}


//判断是否满栈
Status stack_is_full(S_node head)
{
return head.top == MAX_SIZE_PARK - 1 ? OK : ERROR;
}
//入栈
Status stack_push(S_node *head , Car_informa car_msg)
{
char carlicence[20];

int timearvhours;
int timearvmins;

if(OK == stack_is_full(*head))
{
//printf("***********停车场已满，请停到便道.************\n");
//将车停到便道
        queue_push(q_head,car_msg);
}
    else
    { 
        int top = -1;
head -> top = head -> top + 1;

//head -> data[head -> top] = car_msg;
printf("请输入你的牌照 :\n");
scanf("%s",carlicence);    

printf("请输入你的入场时间(比如10:10 :输入10确定再输入10确定):\n");
scanf("%d",&timearvhours);
scanf("%d",&timearvmins);

//此方法试过不成功
//head->data[head->top] = car_msg;
        //car_msg.timearv_hours = timearvhours;
        //car_msg.timearv_mins = timearvmins;

strcpy(head -> data[head -> top].car_licence ,carlicence);
head->data[head -> top].timearv_hours = timearvhours;
head->data[head -> top].timearv_mins = timearvmins;

	printf("*************************************\n");
	printf("**你停在停车场的起始时间为:%d : %d **\n",car_msg.timearv_hours,car_msg.timearv_mins);
	printf("**你停在停车场的起始时间为:%d : %d **\n",head->data[head -> top].timearv_hours,head ->data[head->top].timearv_mins);
	printf("*************************************\n");
	printf("*****请把你的车停在停车场第%d道*******\n",head -> top + 1);
        printf("*************************************\n"); 
}
    return OK; 
}
//初始化队列
Status init_queue(Q_node ** q_head )
{
Q_node *new = (Q_node*)malloc(sizeof(Q_node));

if(NULL == new)
{
return ERROR;
}
*q_head = new;
new -> next = NULL;

return OK;
}

//停车场已满，把车停到便道
Status queue_push(Q_node *q_head,Car_informa car_msg)
{  
char carlicence[20];
int timearvhours;
int timearvmins;
    int len = length(q_head);//测量链表的长度
    //用尾插法把车依次插在便道末尾
Q_node* new =(Q_node*) malloc(sizeof(Q_node));
if(NULL == new)
{
exit(1);
}


while(q_head -> next != NULL)
{
q_head = q_head -> next;
}
   //new -> data[i - 1] = car_msg;

printf("***********停车场已满，请停到便道.************\n");
printf("*****************欢迎来到便道*****************\n");
printf("*********我们的便道停车不满24小时免费*********\n");
printf("请输入你的牌照 :\n");
scanf("%s",carlicence);

printf("请输入你的进入便道的时间（比如10:10 :输入10确定再输入10确定） :\n");
scanf("%d",&timearvhours);
scanf("%d",&timearvmins);

new -> next = NULL;

strcpy(new -> data[len].car_licence , carlicence);//字符串的拷贝
    new -> data[len]. timearv_hours = timearvhours;
    new -> data[len].timearv_mins = timearvmins;

q_head -> next = new;


printf("****你停在便道的起始时间为: %d : %d ****\n",new -> data[len].timearv_hours,new -> data[len].timearv_mins);
printf("*************************************\n");
printf("******请把你的车停在便道第%d道********\n",len + 1);
printf("*************************************\n");
 
    return OK;
}


Status stack_pop(S_node *head,S_node *temp_head,Car_informa car_msg,Q_node * q_head,int count)
{ 
int timelevhours;
int timelevmins;
float money;
int a;//定义要出去的车道
int b,c;

char carlicence[20];
int timearvhours;
int timearvmins;

printf("请输入你从停车场离开的车道: 1 ~ %d  :\n",head -> top + 1);
    scanf("%d",&a);
    
printf("请输入你的离开的时间（比如10:10 :输入10确定再输入10确定）:\n");
scanf("%d",&timelevhours);
scanf("%d",&timelevmins);

printf("***************************************\n");
printf("****你的到达时间为 :%d : %d************\n",head->data[a-1].timearv_hours,head ->data[a-1].timearv_mins);
    printf("****你在停车场的离开时间为: %d : %d *****\n",timelevhours,timelevmins);
    
b = timelevhours - head -> data[a-1].timearv_hours;
c = timelevmins - head -> data[a-1].timearv_mins;
if( c < 0)
{
c = c + 60;
b = b - 1;
}

  money = (b * 60.0 + c) * 0.05;

  printf("*************************************\n");
printf("你的车在停车场一共停留了:%d小时%d分钟\n",b,c); 
    printf("*************************************\n");
printf("**********你共需要交费%f元***********\n",money);
printf("*************************************\n");
  
if(head -> top + 1 == a)//当车就在门口的时候
{
head -> top = head -> top - 1;
}
else//车不在停车场门口
{    
//将栈空间要出去的车后面的车都保存在临时栈的空间里面
   while(head -> top + 1 > a)
{
temp_head -> top = temp_head -> top + 1;
temp_head -> data[temp_head -> top] = head -> data[head -> top];
head -> top--;  
}
head -> top = head -> top - 1;
//把移出去的车在依次排队回到栈空间里面
while(temp_head -> top >= 0)
{
head -> top = head -> top + 1;
head -> data[head -> top] = temp_head -> data[temp_head -> top];
temp_head -> top--;
}
}
//便道的第一辆车进入停车场
if(q_head -> next == NULL)
{   
        printf("---------------------------------------------------------------\n");
	printf("********************便道此时竟然没有车*************************\n");
	printf("---------------------------------------------------------------\n");
}
else
{   
        Q_node *temp = q_head -> next;
head -> top = head -> top + 1;

strcpy(head -> data[head -> top].car_licence ,q_head -> next -> data[count].car_licence); 
q_head -> next = q_head -> next -> next;
free(temp);
temp = NULL;

	printf("**************请便道的第一辆车进入停车场*******************\n"); 
   	printf("请输入你此时进入场的时间(比如10:10 :输入10确定再输入10确定):\n");
scanf("%d",&timearvhours);
scanf("%d",&timearvmins);

head->data[head -> top].timearv_hours = timearvhours;
head->data[head -> top].timearv_mins = timearvmins;

printf("*************************************\n");
printf("**你停在停车场的起始时间为:%d : %d **\n",head->data[head -> top].timearv_hours,head ->data[head->top].timearv_mins);
printf("*************************************\n");
printf("*****请把你的车停在停车场第%d道*******\n",head -> top + 1);
printf("*************************************\n"); 

} 
return OK;


}


void printf_stack(S_node *head,Car_informa car_msg)
{
    int i;

    if(OK == stack_is_empty(*head))
{
printf("************************停车场此时为空*************************\n");
    }

    for(i = 0 ;i <= head -> top;i++)
    {  
        printf("***************************************************************\n"); 
        printf("停车道 : %d\t 车牌 : %s\t进入停车场时间 : %d : %d\n",i+1,head->data[i].car_licence,head->data[i].timearv_hours,head->data[i].timearv_mins);
        printf("***************************************************************\n");
}

}


void printf_queue(Q_node *q_head ,Car_informa car_msg)
{
int i = 0;

while(q_head -> next != NULL)
{ 
        printf("便道 : %d\t 车牌 : %s\t 进入停车场时间 : %d : %d\n",i,q_head->data[0].car_licence,q_head->data[0].timearv_hours,q_head->data[0].timearv_mins);
        i++; 
q_head = q_head -> next;
    }
}


int  length(Q_node *q_head)
{   
    int len = 0;

while(q_head -> next != NULL)
{

q_head = q_head -> next;
len++;
}
return len ;
}

