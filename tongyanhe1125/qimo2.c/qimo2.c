#include "qimo2.h"

void InitStack(SeqStack *S) {
    S->top = -1;
}

int Push(SeqStack *S,Date e) {
    if (S->top == MAXSIZE1 -1 ) return 0;
    S->Selem[++S->top] = e;
    return 1;
}

int Pop(SeqStack *S, Date *e) {
    if (S->top == -1) return 0;
    *e = S->Selem[S->top];
    S->top--;
    return 1;
}

void InitQueue(SeqQueue *Q) {
    Q->front = Q->rear = 0;
    for (int i = 0; i < MAXSIZE; i++){
		Q->Qelem[i] = NULL;
	}
}

int EnQueue(SeqQueue *Q,Date e) {
    if ((Q->rear + 1) % MAXSIZE == Q->front) return 0;
    Q->Qelem[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return 1;
}

int DeQueue(SeqQueue *Q, Date *e) {
    if (Q->front == Q->rear) return 0;
    *e = Q->Qelem[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 1;
}

MGraph MGr;
int shortest[N][N];
int path[N][N];

void Init(){
    int i,j;
	
    for(i=1;i<=N;i++){
	for(j=1;j<=N;j++){
	    MGr.length[i][j]=MaxRoad;
        }
    }
    for(i=1;i<=N;i++){
        shortest[i][j]=0;
    }

    MGr.length[1][11]=MGr.length[11][1]=5;
    MGr.length[2][11]=MGr.length[11][2]=10;
    MGr.length[3][11]=MGr.length[11][3]=15;
    MGr.length[4][11]=MGr.length[11][4]=20;
    MGr.length[5][11]=MGr.length[11][5]=25;
    MGr.length[6][11]=MGr.length[11][6]=30;
    MGr.length[7][11]=MGr.length[11][7]=35;
    MGr.length[8][11]=MGr.length[11][8]=40;
    MGr.length[9][11]=MGr.length[11][9]=45;
    MGr.length[10][11]=MGr.length[11][10]=50;
}

void floyd(){
    int i,j,k;
    for(i=1;i<=N;i++){
	for(j=1;j<=N;j++){
	    shortest[i][j]=MGr.length[i][j];
	    path[i][j]=0;
        }
    }   
    for(k=1;k<=N;k++){
	for(i=1;i<=N;i++){
	    for(j=1;j<=N;j++){
                if(shortest[i][j]>(shortest[i][k]+shortest[k][j])){
                    shortest[i][j]=shortest[i][k]+shortest[k][j];
                    path[i][j]=k;
                    path[j][i]=k;
                }
            }			
        }
    }
}

int shortdistance(){
    int i,j;
    printf("Choose two numbers from 1 to 11,and 11 is exit! \n");
    scanf("%d %d",&i,&j);
    if(i>N||i<0||j>N||j<0){
        printf("Error! \n\n");
        printf("Input two numbers.\n");
        scanf("%d %d",&i,&j);
    }
    else{
        floyd();
        printf("Two Points are the shortest distance: \n\n");
        fflush(stdin);
            if(i<j){
                printf("%d",j);
                while(path[i][j]!=0){
                    printf("<--%d",path[i][j]);
                    if(i<j)
                        j=path[i][j];
                    else
                        i=path[j][i];
                    }
                    printf("<-%d\n\n",i);
                    printf("%d->%d shortest path: %d meters。\n\n",i,j,shortest[i][j]);
            }
            else{
                printf("%d",i);
                while(path[i][j]!=0){
                    printf("-->%d",path[i][j]);
                    if(i<j)
                        j=path[i][j];
                    else
                        i=path[j][i];
                }
            printf("->%d\n\n",j);
            printf("%d->%d shortest path: %d meters。\n\n",i,j,shortest[i][j]);
        }
    }
    return 1;
    fflush(stdin);
}

int COUNT_TIME() {
    time_t tmpcal_ptr;
    struct tm *tmp_ptr = NULL;
    time(&tmpcal_ptr);
    return tmpcal_ptr;
}

int COUNT_FEE(SeqStack S, int gar_NUM) {
    int fee;
    time_t tmpcal_ptr;
    struct tm *tmp_ptr = NULL;
    time(&tmpcal_ptr);
    fee = (tmpcal_ptr - S.TIME[gar_NUM])*FEE;
    return fee;
}

int InternetOut(SeqStack *S, Date e, SeqStack *St) {
    Date S2S;
    while ( S->Selem[S->top] != e ){
        if (Pop(S, &S2S) == 0) {
	    while (St->top != -1) {
		Push(S, St->Selem[St->top]);
		    St->top--;
		}
		printf("No People surf the Internet.\n");
		return 0;
	}
	Push(St, S2S);
    }
    if (S->Selem[S->top] == e) {
	printf("\n NO.%dRecharge successfully!\n", S->Selem[S->top]);
	    printf(" Should pay cost:%d\n", COUNT_FEE(*S, S->top));
		for (int i = S->top; i < MAXSIZE1 -1; i++){
		    S->TIME[i] = S->TIME[i+1];
		}
		S->top--;
    }
    while (St->top != -1) {
	Push(S, St->Selem[St->top]);
	St->top--;
    }
    return 1;
}

int Internet(SeqQueue *Q, SeqStack *S) {
    Date e;
    if (DeQueue(Q, &e) == 0) return 0;
	else {
            Push(S, e);
	    S->TIME[S->top] = COUNT_TIME();
	    return 1;
	}
}

void printALL(SeqStack S, SeqQueue Q) {
    printf("\n");
    printf("On the Internet\n");
    for (int i = S.top; i > -1; i--){
        printf(" ( %d )fee:%d \t",S.Selem[i], COUNT_FEE(S, i));
    }
    printf(" Waiting:\n");
    for (int i = Q.front, m = 0; m < MAXSIZE -1; m++){
    }
    int i = Q.front;
    while (1){
 	if (i == Q.rear) break;
	printf("( %d )\n", Q.Qelem[i]);
		i = (i + 1) % MAXSIZE;
    }
    printf("\n");
}

void Enter(){
    SeqStack S;
    SeqStack St;
    SeqQueue Qc; 
    InitStack(&S);
    InitQueue(&Qc);
    InitStack(&St);
    Init();
    char con;
    int num;
    int count = 1;

    while (1) {
	scanf("%c", &con);
	if (con == '2') {
	    printf("Computer number\n");
	    scanf("%d", &num);
	}
	if (con == '3') {
  	return 0;
	}
	if (con == '1') {
	    if (Push(&S,count) == 0) {
		if(EnQueue(&Qc, count) == 0 ) printf("No Computer,thanks!\n");
		else {
		    printf("%dEnter the bar successfully\n", count);
		    count++;
		}
	    }
	    else {
		printf("%dSuccessful Internet surfing!\n", count);
		S.TIME[S.top] = COUNT_TIME();
		count++;
	    }
	}
	if (con == '2') {
	    if (InternetOut(&S, num, &St) == 1) Internet(&Qc, &S);
	}
        if (con == '0'){
            shortdistance();
        }
	printALL(S, Qc);
	getchar();
    }
}


