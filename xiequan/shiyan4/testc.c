#include"tingchechang.h"


int main(int argc,char **argv){
	LinkQueue wait;
	LinkQueue park;
	Linkstack giveway;
	int num = 0;
	int t   = 0;
	init(&wait,&park,num,t);
	menu(&wait,&park,num,t);
	return 0;
}
