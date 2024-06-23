#include <iostream>
using namespace std;

#if __has_include("program.hh")
#include "program.hh"
#else
#if __has_include("Arbre.hh")
#include "Arbre.hh"
#endif
#endif

void llegir_arbre_int(Arbre<int>& a, int marca){
  /* Pre: a es buit */
  /* Post: a conté l'arbre llegit de l'entrada */
  Arbre<int> a1;
  Arbre<int> a2;
  int x;
  cin >> x;
  if (x!= marca) {
    llegir_arbre_int(a1, marca);
    llegir_arbre_int(a2, marca);
    a.plantar(x,a1,a2);
  }
}

void escriure_arbre_int(Arbre<int> &a, int marca) {
  if (not a.es_buit()) {
    Arbre<int> a1;
    Arbre<int> a2;
    int x = a.arrel();
    cout << " " << x;
    a.fills(a1,a2);
    escriure_arbre_int(a1,marca); 
    escriure_arbre_int(a2,marca); 
    a.plantar(x,a1,a2);
  }
  else  cout << " " << marca;
}

int main()
{
  Arbre<int> a,b;
  llegir_arbre_int(a,0);
  llegir_arbre_int(b,0);

  Arbre<int> c = a.suma(b);
  escriure_arbre_int(c,0);
 
  cout << endl;
}
