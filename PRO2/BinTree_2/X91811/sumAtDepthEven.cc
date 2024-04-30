#include "sumAtDepthEven.hh"
using namespace std;

int layer = -1;

int sumAtDepthEven(BinTree<int> t) {
    // Base Case
    if (t.empty()) return 0;

    // General Case
    layer++;
    int value = t.value();
    int sum_left = sumAtDepthEven(t.left());
    int sum_right = sumAtDepthEven(t.right());
    
    if (layer%2==0) {
        layer--;
        return sum_left+sum_right+value;
    }
    else {
        layer--;
        return sum_left+sum_right;
    }
}