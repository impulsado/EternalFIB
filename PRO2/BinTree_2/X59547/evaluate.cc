#include "evaluate.hh"
#include "utils.hh"
using namespace std;

int evaluate(map<string,int> &variable2value, BinTree<string> t) {
    // Base Case
    if (t.empty()) return 0;

    // General Case
    if (isVariable(t.value())) {
        int value = variable2value[t.value()];
        return value;
    }
    else if (isNumber(t.value())) {
        int value = mystoi(t.value());
        return value;
    }
    else if (t.value()=="+") {
        int num1 = evaluate(variable2value,t.left());
        int num2 = evaluate(variable2value,t.right());
        return num1+num2;
    }
    else if (t.value()=="-") {
        int num1 = evaluate(variable2value,t.left());
        int num2 = evaluate(variable2value,t.right());
        return num1-num2;
    }
    else if (t.value()=="*") {
        int num1 = evaluate(variable2value,t.left());
        int num2 = evaluate(variable2value,t.right());
        return num1*num2;
    }

    return 0;
}