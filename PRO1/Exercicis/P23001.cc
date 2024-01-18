#include<bits/stdc++.h>
using namespace std;

int main () {
    bool es_primera = true;
    int contador=1, maxim=1;
    string usr_principal, usr_paraula;

    while (cin >> usr_paraula) {
        if (es_primera==true) {usr_principal = usr_paraula; es_primera=false; continue;}
        //cout << "Principal: " << " " << usr_principal << " " << "Paraula: " << usr_paraula << " " << "Previa: " << previa << endl;

        if (usr_paraula == usr_principal) {
            contador++;
            //cout << "Contador: " << contador << endl;
        } else {
            contador = 0;
        }

        if (maxim < contador) maxim = contador;
    }

    cout << maxim << endl;
}