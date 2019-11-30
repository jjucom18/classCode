 #include"jiuyuandaohang.c"
 int  main(void)
{
	system("color 2f");
	system("mode con: cols=120 lines=50");
	int choice;
	char c;
	Init();
	do {
		view();  //地图介绍
		huanyingjiemian();
		printf("\n");
		printf("请输入你的选择\n");
		scanf("%d",&choice);
		switch(choice){
		case 1:
			system("cls");
			jingdianliebiao();
			printf("\n\n按回车键返回....");
			getchar();
			getchar();
			system("cls");
			break;
		case 2:
			system("cls");
			getchar();
			do{
			zuiduanlujing();
			printf("\n需要继续查询吗? 'y' or 'n'\n");
			getchar();
			c=getchar();
			system("cls");
			}while(c=='y');
			system("cls");
			break;
		case 3:
			system("cls");
			getchar();
			printf("\t\t\t\t进入景点信息介绍查询.......\n\n");
			jingdianjieshao();
			break;
		case 4: system("cls");
				getchar();
				tuijianlujing();
				printf("\n\n按回车键返回....");
				getchar();
				getchar();
				system("cls");
				break;
		case 5:break;
		default:printf("您输入的选择错误，请重新输入\n");}
	}while(choice!=5);
	jiesujiemian();
	return 0;
}
