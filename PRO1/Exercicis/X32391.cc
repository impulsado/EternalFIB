#include<bits/stdc++.h>
using namespace std;

int main () {
    int usr_gastos, usr_estalvis, usr_num_weeks, contador = 0;

    cin >> usr_gastos >> usr_estalvis >> usr_num_weeks;

    if (usr_num_weeks == 0) {
        if ((usr_estalvis-usr_gastos)>0) {
            cout << 1 << endl;
            return 1;
        } else {
            cout << 0 << endl;
            return 2;
        }
    }

    for (int i = 1; i <= usr_num_weeks; i++) {
        int usr_estalvis_setmana;
        cin >> usr_estalvis_setmana;

        usr_estalvis = usr_estalvis + (usr_estalvis_setmana - usr_gastos);
        if (usr_estalvis> 0) contador++;
    }

    cout << contador << endl;
    return 0;
}