#include "Cjt_estudiants.hh"
#include "Estudiant.hh"
using namespace std;

int main () {
    Cjt_estudiants alumnes;
    alumnes.llegir();
    cout << "POSICIO IMAX: " << alumnes.consultar_imax() << endl;
    Estudiant temp(1111);
    temp.afegir_nota(9);
    alumnes.afegir_estudiant(temp);
    cout << "POSICIO IMAX: " << alumnes.consultar_imax() << endl;
}