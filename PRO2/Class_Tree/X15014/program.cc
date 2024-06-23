#include "Arbre.hh"
#include "ArbIOint.hh"
using namespace std;

int main () {
    Arbre<int> tree;
    llegir_arbre_int(tree, 0);
    Arbre<int> tree_sumes;
    tree.arb_sumes(tree_sumes);
    escriure_arbre_int(tree_sumes);
}