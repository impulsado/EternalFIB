#include <iostream>
#include <stack>
using namespace std;

int main () {
    string s;

    while (cin >> s) {
        stack<char> pila;
        int max = 0, b_counter = 0, p_counter = 0, counter = 0;

        for (int i = 0; i<s.size(); i++) {
            if (s[i]=='(') {
                p_counter++;
                pila.push(s[i]);
            }
            else if (s[i]=='[') {
                b_counter++;
                pila.push(s[i]);
            }
            else if (s[i]==')') {
                if (!pila.empty() and pila.top()=='(') {
                    if (p_counter>0) p_counter--;
                    counter++;
                    pila.pop();
                }
                else {
                    counter = p_counter = b_counter = 0;
                    pila.push(s[i]);
                }
            }
            else if (s[i]==']') {
                if (!pila.empty() and pila.top()=='[') {
                    if (b_counter>0) b_counter--;
                    counter++;
                    pila.pop();
                }
                else {
                    counter = p_counter = b_counter = 0;
                    pila.push(s[i]);
                }
            }

            if (p_counter==0 and b_counter==0 and 2*counter>max and pila.empty()) max = 2*counter;
        }
        
        cout << max << endl;
    }
}