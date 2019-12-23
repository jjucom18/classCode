#include "xt.c"
int main(int argc,char **argv){

	int i;
	Graph G;
    Init_Graph(&G);
    //show_menu(&G);
	LinkQueue wait;
	LinkQueue park;
    LinkStack giveway;
	int num = 0;
	int t = 0;
    init(&wait,&park,&giveway);
	//menu(&wait,&park,&giveway,G,num,t);
	caidan(wait,park,giveway,G,num,t);
    return 0;
}

void caidan(LinkQueue wait,LinkQueue park,LinkStack giveway,Graph G,int num ,int t){
	int i;
	printf("|1|地图    |2|停车场      \n");
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
	} 

}
