#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
https://youtu.be/QZOLb0xHB_Q?si=f7tsSC_Qk2r0qdmn
*/

bool closedCorrectly(string& usr_string) {
    vector<char> stack;
    int i = 0, j = 0;  // i --> string || j --> stack

    while (i<usr_string.size()) {
        char simbol = usr_string[i];
    
        if (simbol == '(' or simbol == '[') stack.push_back(simbol), j++;
        if (simbol == ')') {
            if (j==0) return false; // perque no busqui a -1 
            
            if (stack[j-1]=='(') stack.pop_back(), j--;
            else return false;  // Significa que hem trobat [)
        } else if (simbol == ']') {
            if (j==0) return false; // perque no busqui a -1 

            if (stack[j-1]=='[') stack.pop_back(), j--;
            else return false;  // Significa que hem trobat (]            
        }

        i++;
    }

    if (stack.empty()) return true;
    else return false;
}

int main () {
    string usr_string;

    while (cin >> usr_string) {
        if (closedCorrectly(usr_string)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}