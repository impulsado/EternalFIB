#include "longestLeftmostPath.hh"
#include <vector>
using namespace std;

BinTree<int> generateTreeWithLengths(BinTree<int> t) {
    // Base Case
    if (t.empty()) return BinTree<int>();

    // General Case
    int numLeft;
    BinTree<int> tLeft = generateTreeWithLengths(t.left());
    if (tLeft.empty()) numLeft = 0;
    else numLeft = tLeft.value()+1;
    
    int numRight;
    BinTree<int> tRight = generateTreeWithLengths(t.right());
    if (tRight.empty()) numRight = 0;
    else numRight = tRight.value()+1;

    int value = max(numLeft,numRight);

    return BinTree<int>(value,tLeft,tRight);
}

void generateListWithPath(BinTree<int> t, BinTree<int> tPaths, list<int> &lPath) {
    // Base Case
    if (t.empty()) return;

    // General Case
    lPath.push_back(t.value());
    if (!t.left().empty() and !t.right().empty()) {
        if (tPaths.left().value()>=tPaths.right().value()) generateListWithPath(t.left(),tPaths.left(),lPath);
        else generateListWithPath(t.right(),tPaths.right(),lPath);
    }
    else if (!t.left().empty()) generateListWithPath(t.left(),tPaths.left(),lPath);
    else if (!t.right().empty()) generateListWithPath(t.right(),tPaths.right(),lPath);

    return;
}

list<int> longestLeftmostPath(BinTree<int> t) {
    BinTree<int> tPaths;
    list<int> lPath;

    tPaths = generateTreeWithLengths(t);
    generateListWithPath(t,tPaths,lPath);

    return lPath;
}