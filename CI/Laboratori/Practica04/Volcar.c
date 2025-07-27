#include <stdio.h>
#include "elemento.h"


int Volcar(S1 v[]){

  int i;

  for (i=0; v[i].k != 0x80000000; i++) 
    printf("%3d - %c : %3d : %3d \n", i, v[i].c, v[i].k, *(v[i].m));
  printf("\n\n\n");
        
  return i;
}
