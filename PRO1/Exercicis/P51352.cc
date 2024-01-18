#include <bits/stdc++.h>
using namespace std;

int main () {
    char element1, element2;

    cin >> element1 >> element2;

    if (element1 == element2) { cout << '-' << endl; return 1; }; 
    if (element1 == 'A' and element2 == 'P') { cout << '1' << endl; return 0; }
    if (element1 == 'P' and element2 == 'A') { cout << '2' << endl; return 0; }
    if (element1 == 'V' and element2 == 'A') { cout << '1' << endl; return 0; }
    if (element1 == 'A' and element2 == 'V') { cout << '2' << endl; return 0; } 
    if (element1 == 'P' and element2 == 'V') { cout << '1' << endl; return 0; }
    if (element1 == 'V' and element2 == 'P') { cout << '2' << endl; return 0; } 
}

/*
Pedra   P
Paper   A
Tisora  V
*/