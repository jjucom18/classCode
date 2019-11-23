int main()
{
	stack1 s1;
	queue q2;
	int choice,starttime,endtime,flag;
	char str[50];
	initStack(&s1);
	initqueue(&q2);
	printf("请选择到达（1）还是离去（2）退出程序（-1）\n");
	scantf("%d",&choice);//-1代表退出
	while(choice!=-1)
	{
		if(choice==1){
			printf("\n您当前选择到达（1）")；
				if（isfull(&s1)==1) {
					printf("\n（1号栈）车库位置以达到上限，请等待，开始进入便道排队")；
						printf("请输入您的车牌号\n");
					scanf("%s",&str);
					enterqueue2(&q2,str);
				}else{
					printf("\n请输入您的车牌号");
					scanf("%s",&str);
					printf("\n请输入您的开始时间");
					scanf("%d",&starttime);
					printf("\n请输入您的结束时间");
					scanf("%d",&endtime);
					pushstack(&s1,str,starttime,endtime);
				}
		}else if(choice==2){
			printf("\n您当前选择为退出车库（2）");
			printf("\n请输入您的车牌号")；
				scanf("%s",&str);
			flag=find(&s1,str);
			if(flag==1)
				pop(&s1,flag);
		}printf("\n请继续选择到达（1）还是离去（2）退出程序（-1）");
		scanf("%d",&choice);
	}printf("\n本次服务结束，欢迎下次使用");
	return 0;
}
