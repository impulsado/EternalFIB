#include "ArbreG.hh"
#include "ArbGIOint.hh"
using namespace std;

int main () {
    ArbreGen<int> tree;
    
    llegir_arbre_int(tree, 0);

    if (tree.buscar(8)) cout << "existeix" << endl;
    else cout << "no existeix" << endl;
}