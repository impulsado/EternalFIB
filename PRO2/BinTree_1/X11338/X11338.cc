#include "BinTree.hh"
#include "ParInt.hh"
using namespace std;

void sumak(BinTree<ParInt>& a, int k) {
    // Base Case
    if (a.empty()) return;

    ParInt val = ParInt(a.value().primer(),a.value().segon()+k);
    BinTree<ParInt> tLeft = a.left();
    BinTree<ParInt> tRight = a.right();
    sumak(tLeft, k);
    sumak(tRight, k);
    a = BinTree<ParInt>(val,tLeft,tRight);
}