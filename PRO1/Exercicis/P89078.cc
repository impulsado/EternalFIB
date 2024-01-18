#include<bits/stdc++.h>
using namespace std;

int main () {
    int usr_num, posicio=0, contador=0;
    bool existeix=false;

    while (cin >> usr_num) {
        contador++;
        if (usr_num%2==0 and existeix==false) posicio = contador, existeix=true;
    }

    cout << posicio << endl;
}