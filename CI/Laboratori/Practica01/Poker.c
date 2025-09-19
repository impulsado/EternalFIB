#include <stdio.h>
#include "cycle.h"
#define COR 0
#define PIC 1
#define DIA 2
#define TRE 3
#define N 52
#define PT 10000

typedef struct {
  int num;
  int palo;
}carta;

char trad[13] = {'2', '3', '4', '5', '6', '7', '8', '9', '1', 'J', 'Q', 'K', 'A'};
carta baraja[52];
int pareja = 0;
int trio = 0;
int poker = 0;
int full = 0;
int color = 0;
int nada = 0;
int doblepareja = 0;
int escalera = 0;
int escaleracolor = 0;
int V = 0;


void Init (carta baraja[52])
{ int i;

  for (i=0; i<13; i++) {
    baraja[i].num = i;
    baraja[i].palo = COR;
    baraja[i+13].num = i;
    baraja[i+13].palo = PIC;
    baraja[i+26].num = i;
    baraja[i+26].palo = DIA;
    baraja[i+39].num = i;
    baraja[i+39].palo = TRE;
  }
}
 
void Ordenar(carta mano[5])
{  int i, j, tmp;

  for (i=0; i<5; i++)
    for (j=i+1; j<5; j++) 
      if (mano[i].num > mano[j].num) {
        tmp = mano[i].num;
        mano[i].num = mano[j].num;
        mano[j].num = tmp;
        tmp = mano[i].palo;
        mano[i].palo = mano[j].palo;
        mano[j].palo = tmp;
      }
}

void Mostrar(carta mano[5])
{ int i, num, palo;

  printf("\n");
  for (i=0; i<5; i++) {
    num = mano[i].num;
    palo = mano[i].palo;
    if (trad[num] == '1') printf("10 - ");
    else printf (" %c - ", trad[num]);
    switch(palo) {
      case COR: printf("COR\n"); break;
      case PIC: printf("PIC\n"); break;
      case TRE: printf("TRE\n"); break;
      case DIA: printf("DIA\n"); break;
     
    }
  }
  printf("\n");
}

int verbose(char c[3]) {

  if (V) printf("%s", c);
}

int Color(carta mano[5])
{
  return (mano[0].palo == mano[1].palo) && (mano[0].palo == mano[2].palo) && (mano[0].palo == mano[3].palo) && (mano[0].palo == mano[4].palo); 
} 

int Poker(carta mano[5])
{ int caso1, caso2;

  caso1 = (mano[0].num == mano[1].num) && (mano[0].num == mano[2].num) && (mano[0].num == mano[3].num); 
  caso2 = (mano[1].num == mano[2].num) && (mano[1].num == mano[3].num) && (mano[1].num == mano[4].num); 

  return caso1 || caso2;
}

int Full(carta mano[5])
{ int caso1, caso2;

  caso1 = (mano[0].num == mano[1].num) && (mano[0].num == mano[2].num) && (mano[3].num == mano[4].num); 
  caso2 = (mano[0].num == mano[1].num) && (mano[2].num == mano[3].num) && (mano[2].num == mano[4].num); 

  return caso1 || caso2;
}

int Escalera(carta mano[5])
{ int caso1, caso2;

  caso1 = (mano[0].num == (mano[1].num-1)) && (mano[0].num == (mano[2].num-2)) && (mano[0].num == (mano[3].num-3)) && (mano[0].num == (mano[4].num-4));
  caso2 = (mano[0].num == 0) && (mano[1].num == 1) && (mano[2].num == 2) && (mano[3].num == 3) && (mano[4].num == 12);

  return caso1 || caso2;

}

int Trio(carta mano[5])
{ int caso1, caso2, caso3;

  caso1 = (mano[0].num == mano[1].num) && (mano[0].num == mano[2].num); 
  caso2 = (mano[1].num == mano[2].num) && (mano[1].num == mano[3].num); 
  caso3 = (mano[2].num == mano[3].num) && (mano[2].num == mano[4].num); 

  return caso1 || caso2 || caso3;
}


int Pareja(carta mano[5])
{ int caso1, caso2, caso3, caso4;

  caso1 = (mano[0].num == mano[1].num); 
  caso2 = (mano[1].num == mano[2].num); 
  caso3 = (mano[2].num == mano[3].num); 
  caso4 = (mano[3].num == mano[4].num); 

  return caso1 || caso2 || caso3 || caso4;
}

int DoblePareja(carta mano[5])
{ int caso1, caso2, caso3;

  caso1 = (mano[0].num == mano[1].num) && (mano[2].num == mano[3].num); 
  caso2 = (mano[0].num == mano[1].num) && (mano[3].num == mano[4].num); 
  caso3 = (mano[1].num == mano[2].num) && (mano[3].num == mano[4].num); 

  return caso1 || caso2 || caso3;
}

void Test (carta mano[5]) {

  if (Color(mano) && Escalera(mano)) { escaleracolor++; verbose("EC "); }
  else if (Poker(mano))              { poker++;         verbose("PK "); }
  else if (Full(mano))               { full++;          verbose("FL "); }
  else if (Color(mano))              { color++;         verbose("CL "); }
  else if (Escalera(mano))           { escalera++;      verbose("ES "); }
  else if (Trio(mano))               { trio++;          verbose("TR "); }
  else if (DoblePareja(mano))        { doblepareja++;   verbose("PP "); }
  else if (Pareja(mano))             { pareja++;        verbose("PR "); }
  else                               { nada++;          verbose(" . "); }
}


void Repartir(carta mano[5], int i, int j, int k, int m, int n)
{
  mano[0].num = baraja[i].num;
  mano[1].num = baraja[j].num;
  mano[2].num = baraja[k].num;
  mano[3].num = baraja[m].num;
  mano[4].num = baraja[n].num;
  mano[0].palo = baraja[i].palo;
  mano[1].palo = baraja[j].palo;
  mano[2].palo = baraja[k].palo;
  mano[3].palo = baraja[m].palo;
  mano[4].palo = baraja[n].palo;
}

long int PierdeTiempo(int i) {
   int j, k;
   long int resultado=0;

   for (j=1;j<i;j++)
     for (k=1;k<=j;k++)
       resultado+=j;

   return resultado;
}

float GetTime(void);

main (int argc, char *argv[])
{
   carta mano[5];
   int i, j, k, m, n;
   int tot;
   // Descomentar para medir el tiempo
   //float t1,t2; 
   // Descomentar para medir los ticks
   //ticks tick1,tick2;
   tot = 0;
   
  // Descomentar para medir el tiempo
  //t1=GetTime();
  // Descomentar para medir los ticks
  //tick1=getticks();
  if (argc == 2) V = atoi(argv[1]); 
            else V = 0;

  Init(baraja);
  for (i=0; i<N-4; i++)
    for (j=i+1; j<N-3; j++) 
      for (k=j+1; k<N-2; k++) 
        for (m=k+1; m<N-1; m++)  
          for (n=m+1; n<N; n++) 
          {
            if (tot%25 == 0) verbose("  \n");
            Repartir(mano, i, j, k, m, n);
            Ordenar(mano);
            Test(mano);
            tot++;

          }
  printf("\n");
      
  printf("%7d COMBINACIONES:\n - ESCALERA COLOR (%d)\n - POKER (%d)\n - FULL (%d)\n - COLOR (%d)\n - ESCALERA (%d)\n - TRIO (%d)\n - DOBLE PAREJA (%d)\n - PAREJA (%d)\n - NADA (%d) \n", 
                   tot, escaleracolor, poker, full, color, escalera, trio, doblepareja, pareja, nada);   
		   
  // Esta es la única invocación a la rutina "PierdeTiempo"
  printf("Pierdo algo de tiempo mientras calculo el numero: %ld\n",PierdeTiempo(PT));
  // Descomentar para medir el tiempo
  //t2=GetTime();
  //printf("Milisegundos Tot = %9f\n",t2-t1);  
  // Descomentar para medir los ticks
  //tick2=getticks();  
  //printf("Ciclos = %lf\n",elapsed(tick2,tick1));  
}



