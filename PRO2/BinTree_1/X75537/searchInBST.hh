#include <iostream>
#include <list>

using namespace std;

#include "BinTree.hh"

// Pre: t és un BST
// Post: Retorna cert si i només si x apareix a t
bool searchInBST(BinTree<int> t, int x);