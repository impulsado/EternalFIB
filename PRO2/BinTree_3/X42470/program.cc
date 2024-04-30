#include <iostream>
#include "BinTreeIOint.hh"
#include "BinTree.hh"
using namespace std;

void calc_dist(const BinTree<int> &a, int &max, int level = 0) {
    if (a.empty()) return;

    level++;
    if (level > max) max = level;
    calc_dist(a.left(), max, level);
    calc_dist(a.right(), max, level);
}

void arbre_graus_desequilibri(const BinTree<int> &a, BinTree<int> &agd) {
    if (a.empty()) return;

    int left_long = 0, right_long = 0;
    calc_dist(a.left(), left_long);
    calc_dist(a.right(), right_long);
    int value = left_long - right_long;

    BinTree<int> left, right;
    arbre_graus_desequilibri(a.left(), left);
    arbre_graus_desequilibri(a.right(), right);
    agd = BinTree<int>(value, left, right);
}