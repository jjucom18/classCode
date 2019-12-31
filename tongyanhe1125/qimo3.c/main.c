#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"meun.h"
#include"model.h"

int main() {
	int nSelection = -1;	//输入菜单项编号
	printf("\n 欢迎进入计费管理系统\n");
	do {
		outputMenu();//输出系统菜单
		nSelection = -1;
		//该循环用来解决输入字符(串)后会进入死循环的问题
		while (scanf("%d", &nSelection) != 1) {	//scanf函数有n个输入正确便会返回n
			printf("您输入的菜单错误,请重新输入。\n");
			while (getchar() != '\n');
			//内层while循环换成下面的语句也可以解决问题，但VS2017的编译器不支持fflush(stdin)函数
			//fflush(stdin);
		}
		switch (nSelection){
		case 1://添加卡
			add();
			break;
		case 2://查询卡
			query();
		break;
		case 3://上机
			login();
			break;
		case 4://下机
			settle();
			break;
		case 5://充值
			addMoney();
			break;
		case 6://退费
			refundMoney();
			break;
		case 7://注销卡
			annul();
			break;
		case 8://修改密码
			changePwd();
			break;
		case 9://重新激活卡
			renew();
			break;
		case 10://显示所有卡信息
			allCard();
			break;
		case 0://退出
			exitApp();
			break;

		default:
			printf("您输入的菜单错误,请重新输入。\n");
			break;
		}
	}
	while (nSelection != 0);
	return 0;
}

