#include <iostream>

using namespace std;

#include "BinTree.hh"

typedef BinTree<string> BT;

// Pre:  Els nodes de 't' o bé son strings no buits de lletres minuscules, o bé
//       son de la forma "s.e", on s i e son strings no buits de lletres minúscules.
//       En l'últim cas, el node ha de ser una fulla, i e s'anomena la extensió de la fulla.
// Post: Retorna l'arbre resultant d'esborrar de t tots els nodes amb strings de
//       la forma "s.e" a on 'e' és igual a 'extension'.
BT removeAll(const string &extension, const BT &t);
