#include<bits/stdc++.h>
using namespace std;

int main () {
    int usr_num, contador = 0;

    cin >> usr_num;

    for (int i = 1; i<=usr_num; i++) {
        while (contador<i) {
            cout << "*";
            contador = contador + 1;
        }
        contador = 0;
        cout << endl;
    }
}