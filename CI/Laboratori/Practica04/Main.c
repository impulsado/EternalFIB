#include <stdio.h>
#include <stdlib.h>
#include "elemento.h"


int Ordenar(S1 v[]);
int Insertar(S1 v[], S1 X);
int Buscar(S1 v[], S1 X, int N);
int Volcar(S1 v[]);

int main(int argc, char *argv[]) 
{  
   int a=1, b=27;
   int n;
   int trobat;
   S1 X = {'Z', 310, &a};
   S1 Y = {'Z',   6, &a};
   S1 Z = {'Z',  30, &a};
   S1 v[30] = {{'3', 13, &a}, {'r', 97, &b}, {'y',  0, &a}, {'8', 48, &b}, 
               {'x', 17, &a}, {'z', 41, &b}, {'p', -3, &a}, {'$', 62, &b}, 
               {'r',  3, &a}, {'+', 37, &b}, {'y',  6, &a}, {'%', -9, &b}, 
               {'g',  5, &a}, {'b',  1, &b}, {'m', 12, &a}, {'q', 32, &b}, 
               {'!',  7, &a}, {'-',  2, &b}, {'i', 25, &a}, {'z', 32, &b},
               {' ', 0x80000000, NULL}};
	       
   if (argc == 2){ 
     Y.k = atoi(argv[1]); /* elemento a buscar */
   }  
   
   X = (S1) {'Z',  30, &a};

   n = Volcar(v);

   n = Ordenar(v);
   n = Volcar(v);


   n = Insertar(v, X);
   n = Volcar(v);

   trobat = Buscar(v, Y, n);
   if (trobat >= 0) printf("%3d encontrado en %3d\n", Y.k, trobat);
               else printf("%3d NO encontrado\n", Y.k);

   trobat = Buscar(v, Z, n);
   if (trobat >= 0) printf("%3d encontrado en %3d\n", Z.k, trobat);
               else printf("%3d NO encontrado\n", Z.k);


   return 1;

}



