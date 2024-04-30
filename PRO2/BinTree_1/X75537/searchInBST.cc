#include "BinTree.hh"
using namespace std;

bool searchInBST(BinTree<int> t, int x) {
    // Base Case: Is leaf
    if (t.empty()) {
        return false;
    }

    if (t.value()==x) {
        return true;
    }
    else if (t.value()<x) {
        return searchInBST(t.right(),x);
    }
    else if (t.value()>x) {
        return searchInBST(t.left(),x);
    }
    
    return false;  // It will not get here. It's just for the p2++ compiler
}