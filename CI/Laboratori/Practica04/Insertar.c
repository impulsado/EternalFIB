#include "elemento.h"

void Asignar(S1 v[], S1 X, int pos);

int Insertar(S1 v[], S1 X){

  int i, j, lug;

  i = 0;
  lug = -1;
  do {
    if (X.k < v[i].k) { lug = i; break; }
    else i++; 
  } while (v[i].k != 0x80000000); 
       
  if (v[i].k == 0x80000000) lug = i;
  else while (v[i].k != 0x80000000) i++; 

  for (j=i; j>=lug; j--) {
    v[j+1].c = v[j].c;
    v[j+1].k = v[j].k;
    v[j+1].m = v[j].m;
  }

  Asignar(v, X, lug);   

  return i+1;
}

