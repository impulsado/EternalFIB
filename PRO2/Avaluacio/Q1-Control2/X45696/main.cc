#include <iostream>
using namespace std;

#if __has_include("program.hh")
#include "program.hh"
#else
#if __has_include("Arbre.hh")
#include "Arbre.hh"
#endif
#endif

void llegir_arbre_string(Arbre<string>& a, string marca){
  /* Pre: a es buit */
  /* Post: a conté l'arbre llegit de l'entrada */
  Arbre<string> a1;
  Arbre<string> a2;
  string x;
  cin >> x;
  if (x!= marca) {
    llegir_arbre_string(a1, marca);
    llegir_arbre_string(a2, marca);
    a.plantar(x,a1,a2);
  }
}
int main()
{
  
  Arbre<string> b;
  llegir_arbre_string(b,"#");
  while (not b.es_buit()){
    if (b.evaluate()) cout << "true" << endl;
    else cout << "false" << endl;
    b.a_buit();
    llegir_arbre_string(b,"#");
  }
}
