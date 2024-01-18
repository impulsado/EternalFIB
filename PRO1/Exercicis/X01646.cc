#include<bits/stdc++.h>
using namespace std;

int main () {
    int base, usr_num, dividendo, cociente, residuo, suma = 0;

    cin >> base;

    while (cin >> usr_num) {
        if (usr_num == 0) {cout << "0: 0" << endl; continue;}
        if (usr_num < base) {cout << usr_num << ": " << usr_num << endl; continue;}

        dividendo = usr_num;
        while (dividendo>base) {
            residuo = dividendo%base;
            suma = suma + residuo;
            cociente = (dividendo/base);
            dividendo = cociente;
        }
        if (dividendo == base) {
            suma = suma + 1;
        } else {
            suma = suma + cociente; // Agadfar l'ultim digit a.k.a primer
        }

        cout << usr_num << ": " << suma << endl;
        suma = 0;  // Reset Counter
    } 
}