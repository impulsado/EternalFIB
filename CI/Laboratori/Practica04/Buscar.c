#include "elemento.h"

int BuscarElemento(int *low, int *high, int *mid, S1 X, S1 v[]);

int Buscar(S1 v[], S1 X, int N){

   int low, high, mid;
   int trobat = -1;
  
   low = 0;
   mid = low;
   high = N-1;
   while (low <= high) {
 	trobat = BuscarElemento(&low, &high, &mid, X, v);
	if (trobat >= 0) break;
   }

   return trobat;
}

