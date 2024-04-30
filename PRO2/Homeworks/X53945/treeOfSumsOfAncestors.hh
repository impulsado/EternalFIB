#include <iostream>
#include <list>

using namespace std;

#include "BinTree.hh"

// Pre:
// Post: Retorna un arbre d'enters t' amb la mateixa estructura que t.
//       Per a cada posició p, el valor guardat a t' a posició p és igual a la suma
//       dels valors guardats a t a posició p i a posicions ancestres de p.
BinTree<int> treeOfSumsOfAncestors(const BinTree<int> t);