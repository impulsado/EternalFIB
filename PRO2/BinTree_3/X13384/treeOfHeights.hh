#include <iostream>
#include <list>

using namespace std;

#include "BinTree.hh"

// Pre:
// Post: Retorna un arbre d'enters amb la mateixa estructura que t,
//       i a on cada subarbre té com a arrel la seva alçada.
BinTree<int> treeOfHeights(BinTree<int> t);