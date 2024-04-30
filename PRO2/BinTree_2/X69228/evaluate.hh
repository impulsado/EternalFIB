#include <iostream>
#include <string>

using namespace std;

#include "BinTree.hh"

// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre strings de lletres minúscules i els operadors Concat, Reverse.
// Post: Retorna l'avaluació de l'expressió representada per t.
string evaluate(BinTree<string> t);