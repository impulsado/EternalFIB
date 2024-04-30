#include <iostream>

using namespace std;

#include "BinTree.hh"

// Pre: sigui T el valor inicial de t.
// Post: el valor retornat s'obté a partir de T a base de
// swapejar els fills esquerra i dret dels nodes de T
// que cumpleixen que la suma dels valors que penjen del seu fill esquerra és més gran
// que la suma dels valors que penjen del seu fill dret.
BinTree<int> sortTree(BinTree<int> t);
