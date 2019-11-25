#include <stdio.h>

#include <time.h>

#include "Park.c"





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

	printf("Please enter the:\n");

	printf("j:Enter the vehicle\n");

	printf("c:Out of the vehicle\n");

	printf("e:Log out\n");

	printf("Charge per second%dRMB\n", FEE_per_s);

	while (1) {

		scanf("%c", &con);

		if (con == 'c') {

			printf("Please enter the outgoing vehicle number\n");

			scanf("%d", &num);

		}



		if (con == 'o') {

			return 0;

		}

		if (con == 'j') {

			if (Push(&S,count) == FALSE) {

				if(EnQueue(&Qc, count) == FALSE ) printf("Garage sidewalks are full,access failed\n");

				else {

					printf("%dEnter the sidewalk successfully\n", count);

					count++;

				}

			}

			else {

				printf("%dAccess to garage successfully\n", count);

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
