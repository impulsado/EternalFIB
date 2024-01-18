#include<bits/stdc++.h>
using namespace std;

int main () {
    int a1, b1, a2, b2;
    int interval = 0;

    cin >> a1 >> b1 >> a2 >> b2;

    // Comprovar si NO hi ha RANG COMÚ
    if (b1 < a2 or a1 > b2) {
        cout << "?" << endl;
        return 1;
    }

    // Comprovar si són els MATEIXOS
    if (a1 == a2 and b1 == b2) {
        cout << "=" << endl;
        return 2;
    }

    // Comprovar INTERVAL 1
    if (a1 >= a2 and b1 <= b2) interval = 1;

    // Comprovar INTERVAL 2
    if (a2 >= a1 and b2 <= b1) interval = 2;
    
    // Mostrar RESULTAT
    if (interval != 0) {
        cout << interval << endl;
    } else {
        cout << "?" << endl;
    }

    return 0;
}