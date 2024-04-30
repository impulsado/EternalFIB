#include "treeOfHeights.hh"
using namespace std;

BinTree<int> treeOfHeights(BinTree<int> t) {
    // Base Case
    if (t.empty()) return BinTree<int>();

    // General case
    BinTree<int> left_tree = treeOfHeights(t.left());
    BinTree<int> right_tree = treeOfHeights(t.right());
    int value = 1;
    if (not left_tree.empty() and not right_tree.empty()) {
        value = max(left_tree.value(), right_tree.value())+1;
    } 
    else if (not left_tree.empty()) {
        value = max(value, left_tree.value())+1;
    }
    else if (not right_tree.empty()) {
        value = max(value, right_tree.value())+1;
    }

    return BinTree<int>(value,left_tree,right_tree);
}