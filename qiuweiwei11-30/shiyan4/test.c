#include <stdio.h>
#include <time.h>
#include"abc.c"
#define FEE_per_s 1
#define FALSE 0
#define TRUE 1

int main() {
	SeqStack S;
	SeqQueue Qc;
	SeqStack St;
	InitStack(&S);
	InitQueue(&Qc);
	InitStack(&St);
	char con;
	int num;
	int count = 1;
	printf("请输入:\n");
	printf("j:进入车辆\n");
	printf("c:驶出车辆\n");
	printf("e:退出系统\n");
	printf("每秒收费%d元\n", FEE_per_s);
	while (1) {
		scanf("%c", &con);
		if (con == 'c') {
			printf("请输入驶出的车辆序号\n");
			scanf("%d", &num);
		}

		if (con == 'e') {
			return 0;
		}
		if (con == 'j') {
			if (Push(&S,count) == FALSE) {
				if(EnQueue(&Qc, count) == FALSE ) printf("车库便道均已满，进入失败\n");
				else {
					printf("%d进入便道成功\n", count);
					count++;
				}
			}
			else {
				printf("%d进入车库成功\n", count);
				S.TIME[S.top] = COUNT_TIME();
				count++;
			}
		}
		if (con == 'c') {
			if (DriveOut(&S, num, &St) == TRUE) Drive_Qc_S(&Qc, &S);
		}
		printALL(S, Qc);
		getchar();
	}
}
