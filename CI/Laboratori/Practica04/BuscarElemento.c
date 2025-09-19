#include "elemento.h"

int BuscarElemento(int *low, int *high, int *mid, S1 X, S1 v[])
{  
  if (X.k == v[*mid].k)
    return *mid;	/* elemento encontrado */
  else
    if (*mid < *high) {
      *mid = *high;
      (*low)++;
    } else {
      *mid = *low;
      (*high)--;
    }
  return -1;            /* elemento no encontrado */
}

