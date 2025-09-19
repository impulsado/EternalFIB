#include "elemento.h"

void Intercambiar(S1 v[], int i, int j) {

  int tmp; 
  int *aux;
  char s;

  s      = v[i].c;
  v[i].c = v[j].c;
  v[j].c = s;

  tmp    = v[i].k;
  v[i].k = v[j].k;
  v[j].k = tmp;

  aux    = v[i].m;
  v[i].m = v[j].m;
  v[j].m = aux;

}

