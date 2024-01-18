#include<bits/stdc++.h>
using namespace std;

int main () {
    int usr_quantitat, usr_numero, max_passos;
    bool is_prime=true;

    cin >> usr_quantitat;

    for (int i = 1; i<=usr_quantitat; i++) {
        is_prime=true; // Reset
        cin >> usr_numero;
        max_passos = sqrt(usr_numero);

        for (int j = 2; j<=max_passos; j++) {
            if (usr_numero%j==0) is_prime=false;
        }
        if (usr_numero<=1) is_prime=false;

        if (is_prime==true) {  // SI
            cout << usr_numero << " is prime" << endl;
        } else {  // NO
            cout << usr_numero << " is not prime" << endl;
        }
    }
}