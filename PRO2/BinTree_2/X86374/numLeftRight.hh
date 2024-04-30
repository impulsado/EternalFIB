#include <iostream>

using namespace std;

#include "BinTree.hh"

// Pre:  Sigui T el valor inicial de l'arbre t que es rep com a paràmetre.
//       Els valors guardats a T son tots -1 o -2.
// Post: Sigui T' l'arbre retornat. T i T' tenen exactament la mateixa estructura.
//       Sigui p una posició qualsevol de T'.
//       Si T té un valor -1 a posició p, llavors T' té el nombre de cops que
//       s'escull fill-esquerra en el camí des de l'arrel fins a posició p.
//       Si T té un valor -2 a posició p, llavors T' té el nombre de cops que
//       s'escull fill-dret en el camí des de l'arrel fins a posició p.
BinTree<int> numLeftRight(BinTree<int> t);
