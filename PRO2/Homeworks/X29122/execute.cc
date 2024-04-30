#include "execute.hh"
using namespace std;

int evaluate(map<string,int> &var2val, BinTree<string> t) {
    if (t.value()=="+") {
        int num1 = evaluate(var2val,t.left());
        int num2 = evaluate(var2val,t.right());
        return (num1+num2)%10;
    } 
    else if (t.value()=="*") {
        int num1 = evaluate(var2val,t.left());
        int num2 = evaluate(var2val,t.right());
        return (num1*num2)%10;
    } 
    else if ("0"<=t.value() and t.value()<="9") {
        int num = stoi(t.value());
        return num;
    }

    return var2val[t.value()];
}

void execute(map<string,int> &var2val, BinTree<string> t) {
    // Base Case
    if (t.empty()) return;

    // General Case
    if (t.value()=="=") {
        int value = evaluate(var2val,t.right());
        var2val[t.left().value()] = value;
    }
    else if (t.value()=="print") {
        cout << evaluate(var2val,t.left()) << endl;
    }
    else if (t.value()=="if") {
        int value = evaluate(var2val,t.left());
        if (value!=0) execute(var2val,t.right());
    } 
    else if (t.value()=="while") {
        while (evaluate(var2val,t.left())!=0) {
            execute(var2val,t.right());
        }
    }
    else if (t.value()=="list") {
        execute(var2val,t.left());
        execute(var2val,t.right());
    }

    return;
}