#include "BinTree.hh"
using namespace std;

BinTree<int> maximumTree(BinTree<int> a1, BinTree<int> a2) {
    if (a1.empty() and a2.empty()) return BinTree<int>();
    if (a1.empty()) return BinTree<int>(a2.value(),a2.left(),a2.right());
    if (a2.empty()) return BinTree<int>(a1.value(),a1.left(),a1.right());

    int val0;
    int val1 = a1.value();
    int val2 = a2.value();
    if (val1>val2) val0 = val1; else val0 = val2;

    BinTree<int> tLeft = maximumTree(a1.left(), a2.left());
    BinTree<int> tRight = maximumTree(a1.right(), a2.right());

    return BinTree<int>(val0,tLeft,tRight);
}