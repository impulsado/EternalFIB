#include<bits/stdc++.h>
using namespace std;

int main () {
    cout.setf(ios::fixed);
    cout.precision(4);

    double usr_capital, usr_interes, capital_final, interes = 0.0;
    int usr_temps;
    string usr_tipus;

    cin >> usr_capital >> usr_interes >> usr_temps >> usr_tipus;

    if (usr_tipus == "simple") {
        // NO TINC BÉ LES FORMULES
        // https://www.gabilos.com/calculadoras/interessimple/definiciones_interes_simple.htm
        interes = usr_capital*usr_interes*usr_temps;
        capital_final = interes + usr_capital;
    } else { // "compost"

    }

    cout << capital_final << endl;
}

/*
Capital inicial: (c €)
Interes anual: (i %)
Temps: (t anys)
Tipus: (simple/compost)

Calcula en quants euros es transforma el capital inicial
*/