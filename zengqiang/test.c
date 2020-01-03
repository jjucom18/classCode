#include"car.h"


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
 case 5:
		case '5':
			SearchData();
			break;
}


}


return 0;
}

