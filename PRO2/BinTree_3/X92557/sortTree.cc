#include "sortTree.hh"
using namespace std;

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

BinTree<int> sortTreeV2(BinTree<int> t, BinTree<int> aux) {
    // Base Case
    if (t.empty()) return BinTree<int>();

    // General Case
    int value = t.value();
    BinTree<int> left_tree = sortTreeV2(t.left(), aux.left());
    BinTree<int> right_tree = sortTreeV2(t.right(), aux.right());
    
    int left_sum = 0, right_sum = 0;
    if (not aux.left().empty()) left_sum = aux.left().value();
    if (not aux.right().empty()) right_sum = aux.right().value();

    if (left_sum>right_sum) return BinTree<int>(value,right_tree,left_tree);
    return BinTree<int>(value,left_tree,right_tree);
}

BinTree<int> sortTree(BinTree<int> t) {
    BinTree<int> aux = sumOfTree(t);
    BinTree<int> result = sortTreeV2(t,aux);
    return result;
}