#include <iostream>
#include <string>

using namespace std;

#include "BinTree.hh"

// Pre:  t és un arbre no buit que representa una expressió booleana correcta
//       sobre els true,false i els operadors and,or,not.
// Post: Retorna l'avaluació de l'expressió representada per t.
bool evaluate(const BinTree<string> t);