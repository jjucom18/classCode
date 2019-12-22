#include"car.h"


int main(int argc,char **argv){
	LinkQueue wait;
	LinkQueue park;
	Linkstack giveway;
	int num = 0;
	int t   = 0;
	init(&wait,&park,&giveway);
	menu(&wait,&park,&giveway,num,t);
	return 0;
}

