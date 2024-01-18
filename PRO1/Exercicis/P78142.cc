#include<bits/stdc++.h>
using namespace std;

int main () {
    cout.setf(ios::fixed);
    cout.precision(2);

    double usr_num, media = 0.0, counter = 0.0, suma = 0.0;

    while (cin >> usr_num) {  // Aixo permet a l'usuari fer Ctrl+Z quan vulgui deixar de llegir
        suma = suma + usr_num;
        counter = counter + 1;
    }

    media = suma / counter;

    cout << media << endl;
    return 0;
}