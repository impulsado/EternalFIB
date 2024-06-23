#ifndef ARBIOINT_HH
#define ARBIOINT_HH

#include "ArbreG.hh"

// Lectura d'un arbre general d'enters, acci�.  Els elements
// s'introdueixen en preordre: primer l'arrel, despr�s la seva aritat,
// despr�s el primer subarbre, despr�s el segon, ..., fins l'ultim.
// Una arbre no buit no pot tenir subarbres buits. 
//
// La marca nom�s es fa servir si volem llegir un arbre buit,

/* Exemple: l'arbre 

     1
   / | \
  2  3  4

es llegeix 

1 3 

2 0
3 0 
4 0 
(o amb els numeros a la mateixa l�nia). 
Els zeros son les corresponents aritats, no pas la marca */

void llegir_arbre_int(ArbreGen<int>& a, int marca)
   //Pre: a es buit
   //Post: a cont� l'arbre llegit de l'entrada
{  
  int x;
  cin >> x;
  if (x != marca){
    int aritat;  cin >> aritat;
    if (aritat == 0) a.plantar(x);
    else {
      vector<ArbreGen<int> > vect(aritat);
      for (int i = 0; i < aritat; ++i){
	llegir_arbre_int(vect[i], marca);
      }
      a.plantar(x,vect);
    }
  }
}

// Escriptura d'un arbre general d'enters, acci�.  Els elements
// s'escriuen en preordre: primer l'arrel, despr�s el primer subarbre,
// despr�s el segon, ..., fins l'�ltim.

void escriure_arbre_int(ArbreGen<int> &a) {
  if (not a.es_buit()) {
    int x = a.arrel();
    cout<< x  << " ";
    int n = a.nombre_fills();
    if (n > 0) { 
      vector<ArbreGen<int> > v;
      a.fills(v);
      for (int i = 0; i < n; ++i) {
	escriure_arbre_int(v[i]); 
      }
      a.plantar(x,v);
    }
  }
}

#endif
