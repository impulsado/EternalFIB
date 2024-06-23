#include "evaluatePrefix.hh"
#include <algorithm>
using namespace std;

void reverse(string& s) {
    string result;
    for (int i = 0; i<s.size()/2; i++) {
        swap(s[i], s[s.size()-1-i]);
    }
}

string evaluatePrefixAux(BinTree<string> t, const int& max_size, bool last_was_reverse) {
    // === Base Case
    if (t.empty()) return "";

    // === General Case
    string node = t.value();
    if (node == "Concat") {
        string left = evaluatePrefixAux(t.left(), max_size, false);
        
        if (left.size() < max_size) {
            string right = evaluatePrefixAux(t.right(), max_size, false);
            left += right;
        }
        
        if (last_was_reverse) reverse(left);
        return string(left, 0, max_size);
    }
    else if (node == "Reverse") {
        // Anar negant fara el cicle de T,F,T,F,... sense haver de necesitar un if
        string left = evaluatePrefixAux(t.left(), max_size, not last_was_reverse);
        return string(left, 0, max_size);
    }

    if (last_was_reverse) reverse(node);
    return string(node, 0, max_size);
}

string evaluatePrefix(BinTree<string> t, int n) {
    if (n<=0) return "";
    return evaluatePrefixAux(t, n, false);
}