#include<bits/stdc++.h>
using namespace std;

int main () {
    int usr_num, contador_mes, resto = 0;

    cin >> usr_num;

    for (int i = 1; i<=usr_num; i++) {
        contador_mes = usr_num - i;  // 7 = 8 - 1
        // "+"
        while (contador_mes>=1) {
            cout << "+";
            contador_mes = contador_mes - 1;
        }
        contador_mes = usr_num - i;  // RESET
        
        // "/"
        cout << "/";

        // "*"
        while (contador_mes+1 < usr_num) {
            cout <<  "*";
            contador_mes = contador_mes + 1;
        }
        cout << endl;
    }
}