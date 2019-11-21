#ifndef createrandom_h
#define createrandom_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
#define random_1(a,b) ((rand()%(b - a)) + a)
#define random_2(a,b) ((rand()%(b - a + 1)) + a)

int createrandom(int arr[10]);


#endif
