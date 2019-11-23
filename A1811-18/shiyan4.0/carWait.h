#ifndef carWait_h
#define carWait_h


#define maxsize 100
typedef struct car{
	car *data;
	struct car *next;
}queuenode;
typedef struct Node{
	queuenode *head;
	queuenode *rear;
}carWait;

int init_carWait(carWait *q);//初始化等候路线
int in_carWait(carWait *q,car *x);
int out_carWait(carWait *q,car *x);
int  emoty_carWait(carWait *q);




#endif
