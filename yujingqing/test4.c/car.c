#include"car.h"

Status init(S_node *head)
{
	head->top=-1;
	return OK;
}


Status stack_is_empty(S_node head)
{
	return head.top==-1 ? OK:ERROR;
}


Status stack_is_full(S_node head)
{
	return head.top==MAX_SIZE_PARK-1? OK :ERROR;
}

Statue stack_push(S_node *head,Car_infor car_msg)
{
	char carlicence[20];
	int timeavhours;
	int arvmins;

	if(OK == stack_is_full(*head))
	{
		//printf("**********停车场已满，请停到便道.************\n");
		//将车停到n便道
		queue_push(q_head,car_msg);
	}
	  else 
        {
		int top=-1;
	head->top=head->top+1;
	head->data[head->top]=car_msg;
	//car+msg.timearv_hours=timearvhours;
	//car_msg.timearv_mins=timearvmins;

	strcpy(head->data[head->top].car_licence,carlicence);
	head->data[head->top].timearv_hours=timearvhours;
	head->data[head->top].timearv_mins=timearvmins;
	printf("************************\n");
	//printf("**你停在停车场的起始时间为：%d：%d **\n",car_msg.timearv_hours,car_msg.timearv_mins);
	printf("**你停在停车场的起始时间为：%d：%d **\n",head->data[head->top].timearv_hours,head->data[head->top].timearv_mins);
	printf("************************\n");
	printf("*******请把你的车停在停车场第%d道*********\n",head->top+1);
	printf("*******************************\n");

	}

return OK;
}




Status init_queue(Q_node ** q_head)
{
	Q_node *new=(Q_node*)malloc(sizeof(Q_node));
	if (NULL== new)
	{return ERROR;
	}
	* q_head=new;
	* new->next=NULL;
	return OK;
}

Status queue_push(Q_node *q_head,Car_infor car_msg)
{
	char carlicence[20];
	int timearvhours;
	int timearvmins;
	int len=length(q_head);
	Q_node* new=(Q_node*)malloc(sizeof(Q_node));
	if(NULL==new)
	{
		exit(1);
	}

	while (q_head->next !=NULL)
	{
	q_head=q_head->next;
	}
	printf("**********停车场已满，请停到便道。***********\n");
	printf("**********欢迎来到便道*************\n");
	printf("**********我们的便道停车不满24小时免费***********\n");
	printf("请输入你的牌照：\n");
	scanf("%s",carlicence);

	printf("请输入你的进入便道的时间（比如10：10：输入10确定再输入10确定）\n");
	scanf("%d",&timearvhours);
	scanf("%d",&timearvmins);

	new->next =NULL;
	strcpy(new->data[len].car_licence,carlicence);
	new->data[len].timearv_hours=timearvhours;
	new->data[len].timearv_mins=timearvmins;

  q_head->next=new;

  printf("******你停在便道的起始时间为:%d:%d ****\n",new->data[len].timearv_hours,new->dta[len].timearv_mins);
  printf("**********************************\n");
  printf("************请把你的车停在便道第%d道**************\n",len +1);
  printf("**********************************\n");
  return OK;
}

Status stack_pop(S_node *head,S_node *temp_head,Car_infor car_msg,Q_node * q_head,intcount)
{
	int timelevhours;
	int timelevmins;
	float money;
	int a;
	int b,c;

	char carlicence[20];
	int timearvhours;
	int timearvmins;

	printf("请输入你从停车场离开的车道： 1 ：%d  :\n",head->top+1);
	scanf("%d",&a);
	printf("请输入你的离开的时间：\n");
	scanf("%d",&timelevhours);
	scanf("%d",&timelevmins);
