#include <bits/stdc++.h>
using namespace std;

int main () {
    int usr_num, divisor = 1, contador = 0;

    cin >> usr_num;

    // Saber numero de digits
    if (usr_num == 0) {cout << 0 << endl; return 2;}  // Evitar futurs problemes.
    while ((usr_num/divisor) > 0) {
        contador = contador + 1;
        divisor = divisor * 10;
    }

    // Algoritme numeros a l'inversa
    divisor = 1;  // Reiniciar variable
    while (contador > 0) {
        cout << (usr_num/divisor)%10;
        divisor = divisor * 10;
        contador = contador - 1;
    }
    cout << endl;

    return 0;
}