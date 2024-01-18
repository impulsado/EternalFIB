#include<bits/stdc++.h>
using namespace std;

int main () {
    int edat_menor;
    string frase="", nom, edat, paraula, paraula_pre;

    while (cin >> frase) {
        for (int i = 0; i<frase.length(); i++) {
            cout << "LLETRA: " << frase[i] << endl;
            // LA COSA ESTA EN QUE LA FRASE TE ESPAIS
        }
        cout << "NOM: " << nom << " EDAT: " << edat << endl;
    }
}
/*
IN: My name is [NAME] and I am [N] years old.
OUT: [NAME], you look younger. I thought you were [M] years old.

10-19 --> 1 any menys
20-29 --> 2 anys menys
30-39 --> 3 anys menys
*/