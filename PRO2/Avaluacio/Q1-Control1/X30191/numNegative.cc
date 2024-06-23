#include "numNegative.hh"
#include "utils.hh"
using namespace std;

int countNegtives(BinTree<string> t, int &counter) {
    // Base Case
    if (t.empty()) return 0;

    // General Case
    int value = 0, left_value, right_value;
    if (t.value()=="+") {
        left_value = countNegtives(t.left(),counter);
        right_value = countNegtives(t.right(),counter);
        value = left_value+right_value;
    }
    else if (t.value()=="*") {
        left_value = countNegtives(t.left(),counter);
        right_value = countNegtives(t.right(),counter);
        value = left_value*right_value;
    }
    else if (t.value()=="-") {
        left_value = countNegtives(t.left(),counter);
        right_value = countNegtives(t.right(),counter);
        value = left_value-right_value;
    }
    else {  // Is num.
        value = mystoi(t.value());
    } 

    if (value<0) counter++;
    return value;
}

int numNegative(BinTree<string> t) {
    int counter = 0;
    countNegtives(t,counter);
    return counter;
}