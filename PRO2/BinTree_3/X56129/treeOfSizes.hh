#include <iostream>
#include <list>

using namespace std;

#include "BinTree.hh"

// Pre:
// Post: Retorna un arbre d'enters amb la mateixa estructura que t,
//       i a on cada subarbre té com a valor a l'arrel el nombre de nodes
//       del corresponent subarbre a t.
BinTree<int> treeOfSizes(BinTree<int> t);
