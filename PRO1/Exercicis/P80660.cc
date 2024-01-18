#include<bits/stdc++.h>
using namespace std;

int main () {
    int usr_num, numero, contador;
    
    while (cin >> usr_num) {
        contador = 0;
        numero = usr_num;
        while (numero!=1) {
            if (numero%2==0) numero = numero/2; else numero = (3*numero)+1;
            contador = contador + 1;
        }
        cout << contador << endl;
    }
}