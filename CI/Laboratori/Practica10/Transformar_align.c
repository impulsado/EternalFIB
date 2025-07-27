#include<stdio.h>
#include<stdlib.h>

#ifndef N
#define N 100  /* Dimension por defecto */
#endif
#ifndef M
#define M 1000000
#endif
#ifndef PT
#define PT 15000
#endif

typedef struct {
	char tipo[50];
	int nfil;
	int ncol;
	int tamdato;
} tinfo_fichero;

void leer(unsigned char mat[N][N], char fichero[], tinfo_fichero *info) {
  int i, j;
  FILE *f;
  
  f = fopen(fichero,"rb");
  if (f==NULL) {
    printf("\n ERROR abriendo %s \n", fichero);
    exit(0);
  }

  fscanf(f,"%s ", info->tipo); 
  fscanf(f,"%d %d %d ", &info->ncol, &info->nfil, &info->tamdato); 

  for (i=0; i<info->nfil; i++) {
    for (j=0; j<info->ncol; j++) {
      fread(&mat[i][j], 1, 1, f);
    }
  }

  fclose(f);
}

void escribir(unsigned char mat[N][N], char fichero[], tinfo_fichero info) {
  int i, j;
  FILE *f;
  
  f = fopen(fichero, "wcb");
  if (f==NULL) {
    printf("\n ERROR abriendo %s \n", fichero);
    exit(0);
  }

  fprintf(f,"%s\n", info.tipo);
  fprintf(f,"%d %d\n%d\n", info.ncol, info.nfil, info.tamdato);

  for (i=0; i<info.nfil; i++) {
    for (j=0; j<info.ncol; j++) {
      fwrite(&mat[i][j], 1, 1, f);
    }
  }
  fclose(f);
} 

long int pierdetiempo(int i) {
   int j, k;
   long int resultado=0;

   for (j=1;j<i;j++)
     for (k=1;k<=j;k++)
       resultado+=j;

   return resultado;
}

void procesar(unsigned char *mata, unsigned char *matb, int n);

float GetTime();

void main() {
  float t1, t2;
  unsigned char mat1[N][N] __attribute__ ((aligned(16)));
  int i;
  char tonto;
  unsigned char mat2[N][N] __attribute__ ((aligned(16)));
  tinfo_fichero info;
    
  // Podeis crear mas contadores de tiempo o mover los que ya hay
  t1 = GetTime();
  
  leer(mat1,"in.pgm",&info);
  
  for (i=0;i<M;i++)  
    procesar(&mat1[0][0],&mat2[0][0],N);
  
  escribir(mat2,"out.pgm",info);
  
  // Esta es la unica invocacion a la rutina "PierdeTiempo"
  printf("Pierdo algo de tiempo mientras calculo el numero: %ld\n",pierdetiempo(PT));
  
  t2 = GetTime();
  printf("Milisegundos = %9f\n\n", t2 - t1);

}
