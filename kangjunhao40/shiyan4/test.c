#include <stdio.h>
#include <time.h>
#include "P.c"


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
	printf("请输入：\n");
	printf("i:进入车辆：\n");
	printf("o:驶出车辆：\n");
	printf("e:退出系统\n");
	printf("每刻钟收费%d元\n", FEE_per_s);
	while (1) {
		scanf("%c", &con);
		if (con == 'o') {
			printf("输入驶出车辆：\n");
			scanf("%d", &num);
		}

		if (con == 'e') {
			return 0;
		}
		if (con == 'i') {
			if (Push(&S,count) == FALSE) {
				if(EnQueue(&Qc, count) == FALSE ) printf("Garage sidewalks are full,access failed\n");
				else {
					printf("%d进入便道成功\n", count);
					count++;
				}
			}
			else {
				printf("%d入库成功\n", count);
				S.TIME[S.top] = COUNT_TIME();
				count++;
			}
		}
		if (con == 'o') {
			if (DriveOut(&S, num, &St) == TRUE) Drive_Qc_S(&Qc, &S);
		}
		printALL(S, Qc);
		getchar();
	}
}
