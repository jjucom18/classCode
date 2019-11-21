#ifndef kspaixusort_h
#define kspaixusort_h

#include <stdio.h>
#include <stdlib.h>

void kspaixusort(redtype r[],int t,int w)
{
	int i,j;
	redtype x;
	if(t < w){
	i = t;
	j = w;
	x = r[i];
	while(i < j){
		while((r[j].key >= x.key)&&(j > i)){
			j--;
			if(i < j){
				r[i] = r[j];
				i++;

			}
			while((r[i].key <= x.key)&&(j > i)) {
				i++;
				if(i < j){
					r[j] = r[i];
					j--;
				}
				r[i] = x;
				kspaisusort(r,j+1,w);
			}
		}
	}

	}
}
