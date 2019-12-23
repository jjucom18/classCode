#include "xt.c"
int main(int argc,char **argv){   //相当于char*argv[]就是一个指针数组，程序执行时是从这个函数进入的

	int i;
	Graph G;
    Init_Graph(&G);
    //show_menu(&G);
	LinkQueue wait;//两个链队列结构  wait用来等车，park用来停车 
	LinkQueue park;
    LinkStack giveway;//链栈   出来的车开到那个地方去
	int num = 0;
	int t = 0;
    init(&wait,&park,&giveway);
	//menu(&wait,&park,&giveway,G,num,t);
	caidan(wait,park,giveway,G,num,t);
    return 0;
}

void caidan(LinkQueue wait,LinkQueue park,LinkStack giveway,Graph G,int num ,int t){
	int i;
	printf("***********欢迎来到九江学院校园停车导航系统*************\n");
                printf("        |1|校园停车地图            |2|校园停车场管理      \n");
	printf("请输入你的选择\n");
	scanf("%d",&i);
	switch(i){
		case 1:
			show_menu(&G);
			break;
		case 2:
			menu(&wait,&park,&giveway,num,t);
			break;
		default:
			caidan(wait,park,giveway,G,num,t);
	} //无任何case匹配时，才会执行default;如果有case语句匹配时，运行结果是和default放在switch的最后是一样的。

}
