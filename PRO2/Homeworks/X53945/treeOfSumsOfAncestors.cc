#include "BinTree.hh"
using namespace std;

BinTree<int> tResult;
int sum = 0;

BinTree<int> treeOfSumsOfAncestors(const BinTree<int> t) {
    // Base Case
    if (t.empty()) return BinTree<int>();

    // General Case
    sum += t.value();
    BinTree<int> tLeft = treeOfSumsOfAncestors(t.left());
    BinTree<int> tRight = treeOfSumsOfAncestors(t.right());
    tResult = BinTree<int>(sum,tLeft,tRight);
    sum -= t.value();
    
    return tResult;
}