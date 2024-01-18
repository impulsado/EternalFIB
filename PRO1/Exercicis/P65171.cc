#include <bits/stdc++.h>
using namespace std;

int main () {
    cout.setf(ios::fixed);
    cout.precision(2);

    double usr_iterations, usr_num, suma_esquerra = 0.0, suma_dreta = 0.0, resultat = 0.0, sumatori_esquerra = 0.0, sumatori_dreta = 0.0;

    cin >> usr_iterations;

    for (int i = 1; i<=usr_iterations; i++) {
        cin >> usr_num;

        suma_esquerra = suma_esquerra + (usr_num*usr_num);
        suma_dreta = suma_dreta + usr_num;
    }

    sumatori_esquerra = (1/(usr_iterations-1))*suma_esquerra;
    sumatori_dreta = (1/(usr_iterations*(usr_iterations-1))*(suma_dreta*suma_dreta));
    resultat = sumatori_esquerra - sumatori_dreta;
    
    cout << resultat << endl;
}