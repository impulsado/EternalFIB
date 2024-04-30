#include <iostream>
#include "BinTree.hh"
#include "ParInt.hh"
#include "BinTreeIOParInt.hh"
using namespace std;

typedef BinTree<ParInt> BT;

void search_number_bintree(const BT tree, int num, int &num2, int &lvl, int counter, bool &found) {
    // Base Cases
    if (tree.empty()) return;
    else if (tree.value().primer() == num) {
        found = true;
        lvl = counter;
        num2 = tree.value().segon();
        return;
    }

    // General Case
    if (not found) counter++;
    search_number_bintree(tree.left(), num, num2, lvl, counter, found);
    search_number_bintree(tree.right(), num, num2, lvl, counter, found);
}

int main () {
    BT tree;
    int usr_num;

    read_bintree_parint(tree);

    while (cin >> usr_num) {
        int num2, lvl = 0, counter = 0;
        bool found = false;
        search_number_bintree(tree, usr_num, num2, lvl, counter, found);
        if (not found) cout << -1 << endl;
        else cout << usr_num << ' ' << num2 << ' ' << lvl << endl;
    }
}