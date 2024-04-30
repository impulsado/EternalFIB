#include <iostream>

using namespace std;

#include "BinTree.hh"

// Pre: Rep dos arbres binaris d'enters positius a1 i a2.
// Post: Retorna una arbre, on a la seva arrel hi ha el màxim de les arrels de a1,a2, després,
// en l'arrel del fill esquerra, el màxim de les arrels dels fills esquerra de a1,a2,
// i així successivament.
// Quan un dels arbres no té valors definits en alguna posició, l'arbre resultant hi té
// el valor de l'altre arbre en aquella posició.

BinTree<int> maximumTree(BinTree<int> a1, BinTree<int> a2);