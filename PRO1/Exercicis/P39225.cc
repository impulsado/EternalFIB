#include<bits/stdc++.h>
using namespace std;

int main () {
    int usr_posicio, usr_numero, contador = 0, num_a_la_posicio = 0;

    cin >> usr_posicio;

    while (cin >> usr_numero) {
        contador++;
        if (contador==usr_posicio) num_a_la_posicio = usr_numero;
    }
    cout << "A la posicio " << usr_posicio << " hi ha un " << num_a_la_posicio << "." << endl;
}