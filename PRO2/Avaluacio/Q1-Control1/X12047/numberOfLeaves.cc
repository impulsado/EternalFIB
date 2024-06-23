#include "numberOfLeaves.hh"
using namespace std;

int numberOfLeaves(BinTree<int> t) {
    // Base Case
    if (t.empty()) return 0;

    // General Case
    int left_counter = numberOfLeaves(t.left());
    int right_counter = numberOfLeaves(t.right());

    if (t.left().empty() and t.right().empty()) {
        return left_counter+right_counter+1;
    }
    return left_counter+right_counter;
}