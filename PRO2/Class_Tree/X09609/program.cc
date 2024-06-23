#include "ArbIOint.hh"
#include "Arbre.hh"
using namespace std;

int main () {
    Arbre<int> tree;
    llegir_arbre_int(tree, 0);
    Arbre<int> tree_result;
    tree.sub_arrel(tree_result, -2);
    escriure_arbre_int(tree_result);
}