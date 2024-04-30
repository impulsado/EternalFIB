#include "BinTree.hh"
#include "utils.hh"
using namespace std;

int evaluate(BinTree<string> t) {
    // Base Case: Father was a leaf
    if (t.empty()) return 0;

    if (t.value()=="*") return evaluate(t.right())*evaluate(t.left());
    else if (t.value()=="+") return evaluate(t.right())+evaluate(t.left());
    else if (t.value()=="-") return evaluate(t.left())-evaluate(t.right());  // !! Operand order is important
    else {
        int num = mystoi(t.value());
        return num;
    }
}

/*
int evaluate(BinTree<string> t) {
    // Base Case: Father was a leaf
    if (t.empty()) return 0;

    if (t.value()=="*") {
        int num1 = evaluate(t.right());
        int num2 = evaluate(t.left());
        cout << "NUM1: " << num1;
        cout << " * NUM2: " << num2 << endl;
        return num1*num2;
    }
    else if (t.value()=="+") {
        int num1 = evaluate(t.right());
        int num2 = evaluate(t.left());
        cout << "NUM1: " << num1;
        cout << " + NUM2: " << num2 << endl;
        return num1+num2;
    }
    else if (t.value()=="-") {
        int num1 = evaluate(t.right());
        int num2 = evaluate(t.left());
        cout << "NUM2: " << num1;
        cout << " - NUM1: " << num2 << endl;
        return num2-num1;
    }
    else {
        int num = mystoi(t.value());
        cout << "Im leaf : " << num << endl;
        return num;
    }
}
*/
