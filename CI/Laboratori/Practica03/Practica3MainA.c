#include <stdio.h>
#include "cycle.h"
#define N 3

int v[10]={1,2,3,4,-10,-11,-11,-13,201,-150};

int OperaVec(int Vector[], int elementos);

main(){
   long int i,b;
   int a;
   // Descomentar para medir los ticks
   //ticks tick1,tick2;
   
  // Descomentar para medir los ticks
  //tick1=getticks();
   for (i=0;i<1000;i++)
     for (b=0;b<1000;b++)
       a=OperaVec(v,9);
  // Descomentar para medir los ticks
  //tick2=getticks();  
  //printf("Ciclos = %lf\n",elapsed(tick2,tick1)); 
       
   if (a==6)
     printf("OperaVec BIEN programado.\n");
   else
     printf("OperaVec MAL programado.\n");
}