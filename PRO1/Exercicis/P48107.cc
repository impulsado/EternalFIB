#include<bits/stdc++.h>
using namespace std;

int main () {
    int dividendo, divisor;

    cin >> dividendo >> divisor;

    // Comprovació de DIVISOR
    if (divisor <= 0) return 1;

    // Mostrar RESULTATS
    cout << dividendo/divisor << " " << dividendo%divisor << endl;
}