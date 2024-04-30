#include "SumBelowAtEvenDepth.hh"
using namespace std;

int level = 0;

BinTree<int> sumOfTree(BinTree<int> t) {
    // Base Case
    if (t.empty()) return BinTree<int>();

    // General Case
    int value = t.value();
    BinTree<int> left_tree = sumOfTree(t.left());
    BinTree<int> right_tree = sumOfTree(t.right());

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

BinTree<int> SumBelowAtEvenDepthV2(BinTree<int> t, BinTree<int> aux) {
    // Base Case
    if (t.empty()) return BinTree<int>();

    // General Case
    level++;
    int value = t.value();
    BinTree<int> left_tree = SumBelowAtEvenDepthV2(t.left(), aux.left());
    level--;
    if (level%2==0) value = aux.value();
    level++;
    BinTree<int> right_tree = SumBelowAtEvenDepthV2(t.right(), aux.right());
    level--;

    return BinTree<int>(value, left_tree, right_tree);
}

BinTree<int> SumBelowAtEvenDepth(BinTree<int> t) {
    BinTree<int> aux = sumOfTree(t);
    BinTree<int> result = SumBelowAtEvenDepthV2(t,aux);
    return result;
}