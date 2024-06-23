#include "ArbreN.hh"
#include "ArbNIOint.hh"
using namespace std;

int main () {
    ArbreNari<int> arbre(2);
    llegir_arbre_int(arbre, 0);
    cout << "Si" << endl;
    escriure_arbre_int(arbre);
    cout << "si si" << endl;
    ArbreNari<int> arbre_sumes(2);
    arbre.arbsuma(arbre_sumes);
    escriure_arbre_int(arbre_sumes);
}