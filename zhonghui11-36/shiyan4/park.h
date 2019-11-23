#ifndef _PARK_H
#define _PARK_H
 
#define TRUE 10000
#define FALSE 10001
 
#define P_MAX 3
#define W_MAX 3
#define PRICE 2
 
 
struct car
{
	char *carnum;
	char *timein;
	char *timeout;
	int InsertSeconds;
	int total;
	struct car *next;
};
typedef struct car Car;
 
struct park
{
	Car *top;
	int length;
};
typedef struct park Park;
 
struct waitcar
{
	Car *front;
	Car *rear;
	int length;
};
typedef struct waitcar Wait;
 
void Menu();
void Init(Park **p, Park **r, Wait **w, Park **h);
int EmptyStack(Park *p);
int FullStack(Park *p);
int EnterStack(Park *p, Car *c);
Car *PopStack(Park *p);
int TraverStackP(Park *p);
int TraverStackH(Park *p);
int EmptyQueue(Wait *w);
int FullQueue(Wait *w);
Car *PopQueue(Wait *w);
int TraverQueue(Wait *w);
char *now_time(void);
int Seconds();
int InsertCar(Park *p, Wait *w);
int PopCar(Park *p,Park *r, Wait *w, Park *h);
int QueryCar(Park *p, Wait *w, Park *h);
int ListAll(Park *p, Wait *w, Park *h);
#endif
