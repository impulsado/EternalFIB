#include <bits/stdc++.h>
using namespace std;

int main () {
    int x, a, b, c, d, inici, final, contador;

    cin >> x >> a >> b >> c >> d;

    // Determinar SI hi ha RANG COMÚ
    if (a > d or c > b) contador = -1; else contador = 0;  // -1 --> NO ; 0 --> SI

    // Definir RANG COMÚ
    // Aqui contador serveix per determinar si hi ha o no rang comu.
    if (contador == 0) {
        if (c >= a) inici = c; else inici = a;
        if (b <= d) final = b; else final = d;
        // El if esta dins perque nomes ho comprovo si hi ha rang comu.
        // El que passa es que pot agafar altres valors perque no especifico el valor de les variables.
        if (inici <= x and x <= final) contador++;  // Interval Comú.
    }
    
    // Ara ja faig servir el contador per saber si esta dins d'algun interval
    contador = 0;
    if (a <= x and x <= b) contador++;  // Interval 1
    if (c <= x and x <= d) contador++;  // Interval 2

    if (contador != 0) cout << "yes" << endl; else cout << "no" << endl;
}