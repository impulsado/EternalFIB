#include<bits/stdc++.h>
using namespace std;

int main () {
    int usr_year;
    string last_2digits;

    cin >> usr_year;

    last_2digits = to_string(usr_year%100);
    if (last_2digits == "0") last_2digits = "00";  // Arreglar error que afegeix "0" en comptes de "00" tot i que sigui "00". 

    if (last_2digits == "00") {
        if ((usr_year/100)%4 == 0) cout << "YES" << endl; else cout << "NO" << endl;
    } else if (usr_year%4 == 0) cout << "YES" << endl; else cout << "NO" << endl; 
}