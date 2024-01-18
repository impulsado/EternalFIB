#include<bits/stdc++.h>
using namespace std;

int main () {
    string usr_paraula;
    int counter=0;
    bool inici = false;

    // Si que llegeix la paraula, però si és final, no entra
    while (cin >> usr_paraula and usr_paraula != "final") {  // Posterior a "final" no interessa
        if (usr_paraula == "principi") {inici=true; continue;}
        if (inici) counter++;
    }

    // Si no es com toca, es que serà error
    if (inici and usr_paraula == "final") cout << counter << endl;
    else cout << "sequencia incorrecta" << endl;
}
