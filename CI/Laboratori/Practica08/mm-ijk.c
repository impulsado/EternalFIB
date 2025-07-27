#include <stdio.h>
#ifndef N
#define N 256  /* Dimensión por defecto */
#endif

float A[N][N], B[N][N], C[N][N]; 

float GetTime();


int main() {
  float t1, t2;
  int i, j, k;
  float x;


  // Inicializacion de las matrices A, B y C
   
  x = 0.001;
  for (i=0; i<N; i++) 
    for (j=0; j<N; j++) {
      A[i][j] = 3.4 + x;
      B[i][j] = 0.1 + x;
      C[i][j] = 0.0;
      x = x + 0.02;
    }

  t1 = GetTime();

  // CODIGO A EVALUAR: forma ijk del producto de dos matrices de tamaño NxN
  for (i=0; i<N; i++) 
    for (j=0; j<N; j++)
      for (k=0; k<N; k++) 
        C[i][j] = C[i][j] + A[i][k] * B[k][j];

  /*
   * (t2-t1) es el tiempo medido en tics que tarda
   * en ejecutarse el codigo que queremos evaluar
   */

  t2 = GetTime();

  
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

