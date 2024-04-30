#include "evaluate.hh"
using namespace std;

void reverseString(string &word) {
    int i = 0;
    int j = word.size()-1;
    while (i<j) {
        char temp = word[i];
        word[i] = word[j];
        word[j] = temp;
        i++;
        j--;
    }
}

string evaluate(BinTree<string> t) {
    // Base Case
    if (t.empty()) return "";

    // General Case
    if (t.value()=="Concat") {
        string left = evaluate(t.left());
        string right = evaluate(t.right());

        return left+right;
    } else if (t.value()=="Reverse") {
        string left = evaluate(t.left());
        reverseString(left);

        return left;
    }

    return t.value();
}