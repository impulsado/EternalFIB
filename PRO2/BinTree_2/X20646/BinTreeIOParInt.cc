#include "BinTreeIOParInt.hh"
using namespace std;

void read_bintree_parint(BinTree<ParInt>& a) {
    ParInt value;

    if (value.llegir()) {
        BinTree<ParInt> left_tree;
        read_bintree_parint(left_tree);
        BinTree<ParInt> right_tree;
        read_bintree_parint(right_tree);
        a = BinTree<ParInt>(value,left_tree,right_tree);
    } else return;
}