#include <iostream>
#include <stack>
using namespace std;

int main () {
    stack<char> pila;
    string s;
    
    while (cin >> s) {
        int pCounter = 0, bCounter = 0, eCounter = 0;

        for (int i = 0; i<s.size(); i++) {
            if (s[i]=='(') {
                pCounter++;
                pila.push(s[i]);
            }
            else if (s[i]=='[') {
                bCounter++;
                pila.push(s[i]);
            }
            else if (s[i]==')') {
                if (pila.top()!='(') eCounter++;
                pila.pop();
            }
            else if (s[i]==']') {
                if (pila.top()!='[') eCounter++;
                pila.pop();
            }
        }

        cout << eCounter << endl;
    }
}