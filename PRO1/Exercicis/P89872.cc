#include<bits/stdc++.h>
using namespace std;

int main () {
    string usr_paraula, ultima="a", penultima="a";

    while (cin >> usr_paraula) {
        if (usr_paraula>ultima) penultima = ultima, ultima = usr_paraula;
        if (usr_paraula>penultima and usr_paraula<ultima) penultima = usr_paraula;
    }

    cout << penultima << endl;
}