#ifndef __PLOT_H__
#define __PLOT_H__

#define Price    1      
#define MAX_STOP 10
#define MAX_PAVE 10

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<time.h>                        
#include<malloc.h>
#include<ctype.h>
#include<string.h>
typedef struct
{

    int timeIn;             
    int timeOut;             
    char plate[10];
}Car;
typedef struct
{
    Car Stop[MAX_STOP];   
    int top;                  
}Stopping;
typedef struct
{
    int count;          
    Car Pave[MAX_PAVE]; 
    int front, rear;          
}Pavement;
typedef struct
{
    Car Help[MAX_STOP];   
    int top;                  
}Buffer;

Stopping s;
Pavement p;
Buffer   b;
Car      c;
char     C[10];

void stop_to_pave();       
void car_come    ();       
void stop_to_buff();       
void car_leave   ();       
void welcome     ();
void Display     ();       

#endif
