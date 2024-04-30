#include "BinTree.hh"
using namespace std;

bool poda_subarbre(BinTree<int> &a, int x) {
    if (a.empty()) return false;
    else if (a.value()==x) {
        a = BinTree<int>();
        return true;
    }

    int val = a.value();
    BinTree<int> tLeft = a.left();
    BinTree<int> tRight = a.right();
    
    bool result1, result2; 
    result1 = poda_subarbre(tLeft,x);
    result2 = poda_subarbre(tRight,x);
    if (result1 or result2) {
        a = BinTree<int>(val,tLeft,tRight);
        return true;
    }
    
    return false;
}