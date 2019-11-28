int main()
{
	system("clear");
	int ret;
	S_node head;
	S_node temp_head;
	Car_infor car_msg;
	Q_node *q_head;
	ret=init_queue(&q_head);
	if(ERROR==ret)
	{
		perror("初始化队列失败\n");
		exit(1);
	}
	ret=init(&temp_head);
	if(ERROR==ret)
	{
		perror("初始化栈空间失败");
		exit(1);
	}
	ret=stack_is_empty(head);
	if(ERROR==ret)
	{
		perror("停车场不为空，初始化栈空间失败");
		exit(3);
	}
	int count=-1;
	for(;;)
	{
		switch(menu_select())
		{
			case 1;
			{stack_push(&head,car_msg);
				break;
			}
			case 2;
			{count++;
				stack_pop(&head,&temp_head,car_msg,q_head,count);
				break;}
			case 3:
			{printf_stack(&head,car_msg);
				break;
			}
			case 4:
			{
				exit(1);
			}
		}}
	return 0；
}
menu_select()
{
	int c;
	char str[20];
	printf("--------------欢迎来到停车场系统--------------\n");
	printf("--------------我们每小时只收取3元钱-----------\n");
	printf("--------------1.进入停车场--------------------\n");
	printf("--------------2.离开停车场--------------------\n");
	printf("--------------3.查看停车场的信息--------------\n");
	printf("--------------4.退出系统----------------------\n");
	printf("----------------------------------------------\n");
	do
	{
		printf("请输入数字1 - 4：\n");
		scanf("%s",&str);
		c=atoi(str);
	}while(c<1||c>4);
	return c;
}
