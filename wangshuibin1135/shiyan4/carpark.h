#ifndef carpark_h
#define carpark_h

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
 
#define N 1
 
typedef struct car
{
    char * timer;
}CAR;
 
typedef struct que
{
    int flt;
    struct que *next;
}QUE;
 
void pushp();
char *popp();
void push(char *);
void popg();
void enterque();
void outque();
void mytime(char *,char *);


#endif
