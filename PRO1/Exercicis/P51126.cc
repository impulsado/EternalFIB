#include<bits/stdc++.h>
using namespace std;

int main () {
    int a1, b1, a2, b2;
    int contador = 0;
    int inici = 0;
    int final = 0;

    cin >> a1 >> b1 >> a2 >> b2;

    // Comprovar si NO hi ha RANG COMÚ
    if (b1 < a2 or a1 > b2) {
        cout << "[]" << endl;
        return 1;
    }

    // Determinar el INICI del RANG COMÚ
    if (a1 >= a2) inici = a1; else inici = a2;

    // Determinar el FINAL del RANG COMÚ
    if (b1 <= b2) final = b1; else final = b2;
    
    // Mostrar RESULTAT
    cout << "[" << inici << "," << final << "]" << endl;

    return 0;
}