#include <iostream>

using namespace std;

#include "BinTree.hh"

// Pre:  Sigui T el valor inicial de t.
// Post: Retorna un arbre d'enters R amb la mateixa estructura que T.
//       Per a cada posició p de T i R, si p és a profunditat senar,
//       llavors T i R tenen el mateix valor a posició p.
//       En canvi, si p es a profunditat parell, llavors el valor de R a posició
//       p és la suma de tots els valors que es troben a T a posició p o per sota.
BinTree<int> SumBelowAtEvenDepth(BinTree<int> t);