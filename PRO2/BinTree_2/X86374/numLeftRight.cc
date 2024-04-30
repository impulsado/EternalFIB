#include "numLeftRight.hh"
#include <map>
using namespace std;

map<char, int> mapa = {
    {'l',0},
    {'r',0}
};

BinTree<int> numLeftRight(BinTree<int> t) {
    // Base Case
    if (t.empty()) return BinTree<int>();

    // General Case
    int value = 0;
    if (t.value()==-1) value = mapa['l'];
    else if (t.value()==-2) value = mapa['r'];
    
    mapa['l']++;
    BinTree<int> left_tree = numLeftRight(t.left());
    mapa['l']--;
    
    mapa['r']++;
    BinTree<int> right_tree = numLeftRight(t.right());
    mapa['r']--;

    return BinTree<int>(value,left_tree,right_tree);
}