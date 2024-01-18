#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool prime(int suma) {
    if (suma<2) return false;
    else if (suma==2 or suma==3) return true;
    else if (suma%2==0 or suma%3==0) return false;

    for (int i = 5; i<=sqrt(suma); i++) {
        if (suma%i==0) return false;
    }

    return true;
}

int main () {
    int usr_quant;

    while (cin >> usr_quant) {
        bool is_prime = false;
        int suma = 0;
        vector<int> vNums(usr_quant);

        for (int i = 0; i<usr_quant; i++) {
            cin >> vNums[i];
        }

        for (int i = 0; i<vNums.size(); i++) {
            for (int j = i+1; j<vNums.size(); j++) {
                suma = vNums[i]+vNums[j];
                is_prime = prime(suma);
                if (is_prime) break;  // Trencar bucle perquè hem trovat el que buscàvem.
            }
            if (is_prime) break;  // Mateix motiu que l'anterior.
        }

        if (is_prime) cout << "si" << endl;
        else cout << "no" << endl;
    }
}