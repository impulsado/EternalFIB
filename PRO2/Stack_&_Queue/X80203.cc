#include <iostream>
#include <stack>
using namespace std;

int main () {
    string seq;

    while (cin >> seq) {
        int id = 0;
        stack<char> parentesis;
        stack<int> numeros;
        
        for (int i = 0; i<seq.size(); i++) {
            if (seq[i]=='(') {
                id++;
                parentesis.push(seq[i]);
                numeros.push(id);
                cout << '(' << id;
            } else {  // ')'
                cout << ')' << numeros.top();
                parentesis.pop();
                numeros.pop();
            }
        }
        cout << endl;
    }
}