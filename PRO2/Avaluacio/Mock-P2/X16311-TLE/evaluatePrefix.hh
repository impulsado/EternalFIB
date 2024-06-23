#include <iostream>
#include <string>

using namespace std;

#include "BinTree.hh"

// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre strings de lletres minúscules i els operadors Concat, Reverse.
//       n>=0
// Post: Retorna el prefix de longitut n de l'avaluació de l'expressió representada per t.
//       En cas que n sigui més gran que la longitut d'aquesta avaluació,
//       llavors retorna només l'avaluació, cap caràcter més.
string evaluatePrefix(BinTree<string> t, int n);