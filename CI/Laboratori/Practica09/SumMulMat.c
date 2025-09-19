#include <stdio.h>
#ifndef N
#define N 256  /* Dimensión por defecto */
#endif
#define PT 10000

float A[N][N], B[N][N], C[N][N]; 

long int PierdeTiempo(int i) {
   int j, k;
   long int resultado=0;

   for (j=1;j<i;j++)
     for (k=1;k<=j;k++)
       if (i==k)
         resultado+=j;

   return resultado;
}

float GetTime();


int main() {
  float t1, t2;
  int i, j, k;
  float x;


  // Inicializacion de las matrices A, B y C
  // No la evaluamos para MIPS ni MFLOPS
   
  x = 0.001;
  for (i=0; i<N; i++) 
    for (j=0; j<N; j++) {
      A[i][j] = 3.4 + x;
      B[i][j] = 0.1 + x;
      C[i][j] = 0.0;
      x = x + 0.02;
    }

  t1 = GetTime();

  // CODIGO A EVALUAR: 
  for (i=0; i<N; i++) 
    for (j=0; j<N; j++)
      for (k=0; k<N; k++) 
        C[i][j] = C[i][j] + A[i][k] * B[k][j] * B[k][j];

  // Esta es la única invocación a la rutina "PierdeTiempo"
  printf("Pierdo algo de tiempo mientras calculo el numero: %ld\n",PierdeTiempo(PT));
  
   /*
   * (t2-t1) es el tiempo medido en tics que tarda
   * en ejecutarse el codigo que queremos evaluar
   */ 
  t2 = GetTime();

  // Fin, NO lo evaluamos ni para MIPS ni para MFLOPS
  if (N > 6) {
    printf("FORMA ijk (%d), Milisegundos = %9f \n\n", N, t2 - t1);
  }
  if (N <= 6) {
    /* 
     * Para Ns peque¤as se saca el resultado para comprobar que las tres
     * formas dan el mismo resultado
     */
    printf("\nFORMA ijk \n\n");
    for (i=0; i<N; i++) {
      for (j=0; j<N; j++)
        printf("%10f ", C[i][j]);
      printf ("\n");
    }
  }

  return 0;
}

