#include<bits/stdc++.h>
using namespace std;

int main () {
    bool possible = true;
    char usr_parentesi;
    int contador = 0, total=0;

    while (cin >> usr_parentesi) {
        total++;
        if (contador<0) possible = false;
        if (usr_parentesi == '(') contador ++; 
        if (usr_parentesi == ')') contador --;
    }

    if (total%2!=0) {cout << "no" << endl; return 1;}
    if (possible==false) {cout << "no" << endl; return 1;}
    if (contador==0) {cout << "yes" << endl; return 0;} else {cout << "no" << endl; return 1;}
    return 0;
}