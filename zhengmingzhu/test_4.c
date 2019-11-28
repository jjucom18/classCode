//This is c program code!
/* *=+=+=+=+* *** *=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
  * 文档信息: *** :~/classCode/zhengmingzhu/test_4.c
  * 版权声明: *** :(魎魍魅魑)MIT
  * 联络信箱: *** :guochaoxxl@163.com
  * 创建时间: *** :2019年11月23日的下午03:20
  * 文档用途: *** :数据结构与算法分析-c语言描述
  * 作者信息: *** :guochaoxxl(http://cnblogs.com/guochaoxxl)
  * 修订时间: *** :2019年第46周 11月23日 星期六 下午03:20 (第327天)
  * 文件描述: *** :自行添加
 * *+=+=+=+=* *** *+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+*/
#include "test_4.h"
#include "struct4.c"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void menual(){//停车管理系统的显示界面

    SeqStackCar In,Temp;
    LinkQueueCar W;
    int ch;
		StackInit(&In);
		StackInit(&Temp);
        QueueInit(&W);

		printf("是否进入停车管理系统\n 请输入1或者0");
		scanf("%d",&ch);	
    while(1){

		printf(" 欢迎使用停车场系统\n");
		printf("1. 车辆到达登记\t");
		printf("2. 车辆离开登记\t");
		printf("3. 车辆列表显示\t");
		printf("4. 退出管理系统\n");
     
//	while(){
		printf("\n请选择: ");
		scanf("%d",&ch);

    if(ch>4&&ch<1){
		//else printf("\n 输入有误，请重新选择： 1~4: ");
    switch(ch){
    case 1:Arrival(&In,&W);
		break;
    case 2:Leave(&In,&Temp,&W);
		break;
	case 3:List(In,W);
		break;
    case 4:exit(0);

	default: break;} 
 
	} 		else printf("\n 输入有误，请重新选择： 1~4: ");
	}
}   

} 
