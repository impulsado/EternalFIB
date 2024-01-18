#include <bits/stdc++.h>
using namespace std;

int main () {
    int usr_num, dividendo, num_digits = 0;

    cin >> usr_num;

    dividendo = usr_num;
    for (int base = 2; base <= 16; base++) {
        
        while (dividendo >= base) {
            dividendo = dividendo/base;
            num_digits = num_digits + 1;
        }

        num_digits = num_digits + 1; // Sumar l'últim cocient (que no es resto)
        cout << "Base " << base << ": " << num_digits << " cifras." << endl;

        // Reset counter
        dividendo = usr_num;
        num_digits = 0;
    }
}