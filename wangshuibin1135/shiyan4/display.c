#include"carpark.h"

void display()
{
    int choose;
    system("clear");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t  欢迎使用停车场管理系统！\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    sleep(2);
    while(1)
    {
        //time_t timer = time(NULL);
        system("clear");
	int i;
	int l = 0;
	for(i = 0; i <= topp ; i++)
	{
	    printf("%d:有车\t\t",i);
	    l++;
	    if(l % 4 == 0)
	    {
	        printf("\n");
	    }
	}
	for(i = topp+1; i < 10; i++)
	{
	    printf("%d:空\t\t",i);
	    l++;
	    if(l % 4 == 0)
	    {
	        printf("\n");
	    }
	}
	printf("\n\n\n\n\n");
        printf("/*******************************************/\n");
        printf("/*************** 1.停车 ********************/\n");
        printf("/*************** 2.离开 ********************/\n");
        printf("/*************** 3.查看当前以停时间*********/\n");
        printf("/*************** 4.退出*********************/\n");
        printf("/*******************************************/\n");
	printf("请输入您的选择：");
	scanf("%d",&choose);
	switch(choose)
	{
	    case 1:
	    {
                system("clear");
		l = 0;
	    	for(i = 0; i <= topp ; i++)
	{
	    printf("%d:有车\t\t",i);
	    l++;
	    if(l % 4 == 0)
	    {
	        printf("\n");
	    }
	}
	for(i = topp+1; i < 10; i++)
	{
	    printf("%d:空\t\t",i);
	    l++;
	    if(l % 4 == 0)
	    {
	        printf("\n");
	    }
	}
	printf("\n\n\n\n\n");    //pushp();
		incar();
		sleep(1);
		break;
	    }
	    case 2:
	    {
                system("clear");
		l = 0;
                	for(i = 0; i <= topp ; i++)
	{
	    printf("%d:有车\t\t",i);
	    l++;
	    if(l % 4 == 0)
	    {
	        printf("\n");
	    }
	}
	for(i = topp+1; i < 10; i++)
	{
	    printf("%d:空\t\t",i);
	    l++;
	    if(l % 4 == 0)
	    {
	        printf("\n");
	    }
	}
	l = 0;
	printf("\n\n\n\n\n");
	        outcar();
		printf("请按回车键继续...\n");
		getchar();
		getchar();
		break;
	    }
	    case 3:
	    {
                system("clear");
		l = 0;
                	for(i = 0; i <= topp ; i++)
	{
	    printf("%d:有车\t\t",i);
	    l++;
	    if(l % 4 == 0)
	    {
	        printf("\n");
	    }
	}
	for(i = topp+1; i < 10; i++)
	{
	    printf("%d:空\t\t",i);
	    l++;
	    if(l % 4 == 0)
	    {
	        printf("\n");
	    }
	}
	l = 0;
	printf("\n\n\n\n\n");
	        myprint();
		printf("请按回车键继续...\n");
		getchar();
		getchar();
	        break;
	    }
	    case 4:
	    {
                system("clear");
                printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t欢迎再次使用！\n");
                printf("\n\n\n\n\n\n\n\n\n\n\n");
		sleep(2);
		system("clear");
	        exit(0);
	        break;
	    }
	    default:
	    {
	        break;
	    }
	}
    }
}
