#include<bits/stdc++.h>
using namespace std;

int main () {
    int usr_posicio, usr_numero, contador = 1, num_a_la_posicio = 0;
    bool existeix = false;

    cin >> usr_posicio;

    while (cin >> usr_numero) {
        if (contador==usr_posicio){num_a_la_posicio = usr_numero; existeix=true;}
        contador++;
    }

    if (existeix == false) {
        cout << "Posicio incorrecta." << endl;
        return 1;
    }

    cout << "A la posicio " << usr_posicio << " hi ha un " << num_a_la_posicio << "." << endl;
    return 0;
}