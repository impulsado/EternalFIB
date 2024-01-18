#include<bits/stdc++.h>
using namespace std;

int main () {
    int usr_files, usr_columnes, numero;
    
    while (cin >> usr_files >> usr_columnes) {
        numero = 9;
        for (int fila = 1; fila <= usr_files; fila++) {
            for (int col = 1; col <= usr_columnes; col++) {
                if (numero<0) numero = 9;
                cout << numero;
                numero = numero - 1;
            }
            cout << endl;  // final de fila
        }
        cout << endl; // Final de rectangle
    }
}

/*  Hi ha un salt de mes al final
OUTPUT:
9876⤶
⤶

Expected:
9876⤶
*/