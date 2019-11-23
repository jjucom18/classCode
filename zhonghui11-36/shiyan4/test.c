#include"park.c"
#include<stdio.h>
#include<stdlib.h>
 
int main()
{
	system("clear");
	Park *park;
	Park *road;
	Wait *waitcar;
	Park *history;
	Init(&park, &road, &waitcar, &history);
 
	int choice;
	while(1)
	{
		Menu();
		printf("请选择：");
		scanf("%d",&choice);
		getchar();
		switch(choice)
		{
			case 1:
				InsertCar(park, waitcar);
				break;
			case 2:
				PopCar(park, road, waitcar, history);
				break;
			case 3:
				QueryCar(park, waitcar, history);
				break;
			case 4:
				ListAll(park, waitcar, history);
				break;
		/*	case 5:
				ListCarIn(park);
				break;
			case 6:
				ListCarWait(wait);
				break;*/
			case 7:
				printf("欢迎下次使用！\n");
				sleep(1);
				exit(1);
				break;
			default:
				printf("请重新选择！\n");
				break;
		}
	}
	
	return 0;
}
