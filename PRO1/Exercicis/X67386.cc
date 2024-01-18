#include <iostream>
using namespace std;

int main () {
    bool found = false;
    int contador = 1, posicio = 0; 
    string main_paraula, usr_paraula;

    cin >> main_paraula;
    while (cin >> usr_paraula) {
        if (usr_paraula == main_paraula and not found) posicio = contador, found = true;
        contador++;
    }

    if (posicio == 0) {
        cout << "No existe" << endl;
    } else {
        cout << posicio << endl;
    }
}