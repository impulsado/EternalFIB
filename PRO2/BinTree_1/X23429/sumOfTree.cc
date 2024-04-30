#include "BinTree.hh"
using namespace std;

int sumOfTree(BinTree<int> t) {
    // Base Case: This node is empty so our parent is a leaf.
    if (t.empty()) return 0;
    
    return t.value()+sumOfTree(t.right())+sumOfTree(t.left());
}