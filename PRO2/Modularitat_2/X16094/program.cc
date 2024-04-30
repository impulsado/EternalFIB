#include "Estudiant.hh"
#include <iostream>
using namespace std;

int main() {
    Estudiant est(4444);
    est.modificar_nota(9);

    Estudiant usr_est;
    cout << "Escribe un estudiante <DNI nota>" << endl;
    usr_est.llegir();
    
    if (est==usr_est) cout << "si tenen el mateix dni" << endl;
    else cout << "no tenen el mateix dni" << endl;
}