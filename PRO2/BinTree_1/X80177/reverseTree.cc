#include "BinTree.hh"
using namespace std;

BinTree<int> reverseTree(BinTree<int> t) {
    if (t.empty()) return BinTree<int>();  // Return empty tree because the node is actually empty
    
    BinTree<int> tRight, tLeft;
    int node_value = t.value();
    tLeft = reverseTree(t.right());
    tRight = reverseTree(t.left());
    
    return BinTree<int>(node_value, tLeft, tRight);
}