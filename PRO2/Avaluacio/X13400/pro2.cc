#include <iostream>
#include "Cjt_estudiants.hh"

using namespace std;

int main() {
  Cjt_estudiants c;
  c.llegir();
  int op; 
  cin >> op;
  while (op != -5) {
    Estudiant est; 
    bool b; 
    switch (op) { 
    case -1:   // afegir estudiant
      est.llegir();
      c.afegir_estudiant(est, b);
      if (b)  cout << "L'estudiant " << est.consultar_DNI() << " ja hi era" << endl << endl;
      break;
    case -2:   // esborrar estudiant
      int dni; 
      cin >> dni; //  dni de l'estudiant a esborrar
      c.esborrar_estudiant(dni, b);
      if (not b)  cout << "L'estudiant " << dni << " no hi era" << endl << endl;      
      break; 
    case -3:   // escriure conjunt
      cout << "Conjunt:" << endl;
      c.escriure();
      cout << endl;
      break;
    case -4:   // nombre d'estudiants a un interval
      cout << "Estudiants interval ";
      int k;
      cin >> k;
      cout << k << ": " << c.nombre_est_interval(k) << endl << endl;
    }
    cin >> op;
  }
}

