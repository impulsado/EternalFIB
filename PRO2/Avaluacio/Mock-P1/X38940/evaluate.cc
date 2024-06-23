#include "evaluate.hh"
using namespace std;

bool evaluate(const BinTree<string> t) {
    // Base Case (It will not be used)
    if (t.empty()) return true;

    // General case
    bool left_val, right_val, value = true;

    if (t.value()=="true") return true;
    else if (t.value()=="false") return false;
    else if (t.value()=="and") {
        left_val = evaluate(t.left());
        if (not left_val) return false;
        right_val = evaluate(t.right());
        return left_val and right_val;
    }
    else if (t.value()=="or") {
        left_val = evaluate(t.left());
        if (left_val) return true;
        right_val = evaluate(t.right());
        return left_val or right_val;  
    }
    else if (t.value()=="not") {
        left_val = evaluate(t.left());
        return not left_val;
    }

    return value;  // It will not be used
}