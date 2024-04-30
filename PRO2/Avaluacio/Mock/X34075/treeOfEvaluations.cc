#include "treeOfEvaluations.hh"
using namespace std;

BinTree<bool> treeOfEvaluations(BinTree<string> t) {
    // Base Case
    if (t.empty()) return BinTree<bool>();

    // General case
    BinTree<bool> left_tree;
    BinTree<bool> right_tree;
    bool left_val, right_val, value = true;

    if (t.value()=="true") {
        value = true;
        left_tree = treeOfEvaluations(t.left());
        right_tree = treeOfEvaluations(t.right());
    }
    else if (t.value()=="false") {
        value = false;
        left_tree = treeOfEvaluations(t.left());
        right_tree = treeOfEvaluations(t.right());       
    }
    else if (t.value()=="and") {
        left_tree = treeOfEvaluations(t.left());
        right_tree = treeOfEvaluations(t.right());    
        left_val = left_tree.value();
        right_val = right_tree.value();
        value = left_val and right_val;
    }
    else if (t.value()=="or") {
        left_tree = treeOfEvaluations(t.left());
        right_tree = treeOfEvaluations(t.right());    
        left_val = left_tree.value();
        right_val = right_tree.value();
        value = left_val or right_val;
    }
    else if (t.value()=="not") {
        left_tree = treeOfEvaluations(t.left());
        right_tree = treeOfEvaluations(t.right());  
        left_val = left_tree.value();
        value = not left_val;
    }

    return BinTree<bool>(value,left_tree,right_tree);
}