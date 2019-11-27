#include"PackingSeq.h"
#include"PackingLink.h"
void main()
{
	char ch1;
	SqStackCar s1,s2;
	LinkQueueCar p;
	CarNode x;
	int flag;
	InitSeqStack (&s1);
	InitSeqStack (&s2);
	InitLinkQueue (&p);
	flag=1;
	for( ; ;)
	{
		printf("输入数据:'A'/'L'/'E',车牌号,到达/离开时间\n");
		scanf("%c%d%d%d",&ch1,&x.num,&x.arrtime.hour,&x.arrtime.minute);
		getchar();
		switch(ch1)
		{
          case 'A':Arrive(&s1,&p,x);
				 break;
				 
	      case 'L':leave(&s1,&p,x);
				   break;

		  case 'E':flag=0;
			
		  printf("程序正常结束\n");
		  break;	
		  default:printf("输入数据错误，重新输入\n");
		}
		if(flag=0) break;
	}
}/*mian*/
