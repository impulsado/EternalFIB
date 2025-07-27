#include "elemento.h"

void Intercambiar(S1 v[], int i, int j);

int Ordenar(S1 v[]){

  int i, j;

  for (i=0; v[i].k != 0x80000000; i++) 
    for (j=i+1; v[j].k != 0x80000000; j++) 
      if (v[i].k > v[j].k) 
         Intercambiar(v, i, j);
        
   return i;
}
