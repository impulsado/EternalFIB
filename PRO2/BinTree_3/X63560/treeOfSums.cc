#include "treeOfSums.hh"
using namespace std;

BinTree<int> treeOfSums(BinTree<int> t) {
    // Base Case
    if (t.empty()) return BinTree<int>();

    // General Case
    int value = t.value();
    BinTree<int> left_tree = treeOfSums(t.left());
    BinTree<int> right_tree = treeOfSums(t.right());

    if (not left_tree.empty() and not right_tree.empty()) {
        value += left_tree.value() + right_tree.value();
    }
    else if (not left_tree.empty()) {
        value += left_tree.value();
    }
    else if (not right_tree.empty()) {
        value += right_tree.value();
    }

    return BinTree<int>(value,left_tree,right_tree);
}