#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Jugador {
    string nom;
    int dtd;        // doble triple-doble
    int td;         // triple-doble (que no són doble triple-doble)
};

void llegir_jugador(int p, Jugador& jug) {
    int dada;
    vector<int> estadistiques;

    cin >> jug.nom;

    for (int i = 0; i<p; i++) {
        int dTD = 0, TD = 0;
        // Agafar estadistiques
        for (int j = 0; j<5; j++) {
            cin >> dada;
            if (dada>=20) dTD++;
            if (dada>=10) TD++;
        }

        // Analitzar dades
        if (dTD>=3) jug.dtd++;
        else if (TD>=3) jug.td++;
    }
}

bool customFilter(Jugador& a, Jugador& b) {
    if (a.dtd!=b.dtd) return a.dtd>b.dtd;
    else if (a.td!=b.td) return a.td>b.td;
    else return a.nom<b.nom;
}

int main() {
    // Demanar info general
    int quant_partits, quant_jugadors;
    cin >> quant_partits >> quant_jugadors;
    
    // Demanar jugadors
    vector<Jugador> jugadors(quant_jugadors);
    for (int i = 0; i<quant_jugadors; i++) {
        llegir_jugador(quant_partits,jugadors[i]);
    }

    // Ordenar segons dTD>TD>nom
    sort(jugadors.begin(), jugadors.end(), customFilter);

    // Mostrar resultats
    for (int i = 0; i<jugadors.size(); i++) {
        cout << jugadors[i].nom << ' ' << jugadors[i].dtd << ' ' << jugadors[i].td << endl;
    } 

}