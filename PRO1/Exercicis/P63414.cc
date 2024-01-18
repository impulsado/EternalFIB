#include <iostream>
#include <vector>
using namespace std;

int main () {
    int usr_quant, usr_num, resta = 0;
    /*
    Aquest número servirà per a restar-lo al número que introdueixi l'usuari.
    Així s'aconsegueix poder guardar en la pos. del vector vFreq[resta] la quantitat de vegades que surt.
    Si no fessim això, vFreq[1000000000] seria exagerat.
    També ens servirà per a l'hora de mostrar el número, només sumar la "i" i així no haver de guardar els nombres que diu usuari.
    */
    int numero = 1000000000;
    /*
    Juntament haurem d'inicialitzar un vector amb un màxim de 1001 pos. donat que enunciat diu que el rang és:
    1000000000 ~ 1000001000 --> pos = 0 ~ pos = 1000 --> Total 1001 posicions 
    */
    vector<int> vFreq(1001,0);

    cin >> usr_quant;  // Quantitat de números que entrarà

    // Demanar i guardar
    for (int i = 0; i<usr_quant; i++) {
        cin >> usr_num;

        resta = usr_num-numero;
        vFreq[resta] = vFreq[resta] + 1;  // Això no donarà error perquè hem inicialitzar TOT el vector amb TOTES les pos. a 0.
    }

    // Mostrar resultat
    // No fa falta preocupar-se d'ordenar perquè ja està ordenat donat que no es guarden els nombres sino només les vegades que apareix.
    for (int i = 0; i<1001; i++) {
        if (vFreq[i] != 0) cout << numero+i << " : " << vFreq[i] << endl;
    }
}

/*  VERSIÓ LENTA
#include <iostream>
#include <vector>
using namespace std;

int main () {
    bool found = false, swapped;
    int usr_quant, usr_num, temp_num, temp_freq;
    temp_num = temp_freq = 0;
    vector<int> vNums;
    vector<int> vFreq;

    
    cin >> usr_quant;  // Quantitat de números que entrarà
    
    // Demanar i guardar
    for (int i = 0; i<usr_quant; i++) {
        cin >> usr_num;

        if (i==0) {vNums.push_back(usr_num); vFreq.push_back(1); continue;}  // Primer cas

        for (int j = 0; j<=vNums.size()-1; j++) {
            if (vNums[j] == usr_num) {  // Busca si ja s'ha escrit
                found = true;  // Determinar que l'ha trobat per no afegir-lo de nou
                vFreq[j] = vFreq[j]+1;  // Suma 1 al contador i estarà sincro. amb els números
                break;  // Trenca bucle aquest de la 'j' per optimitzar el codi
            }
        }

        if (not found) {vNums.push_back(usr_num); vFreq.push_back(1);} // Si no el troba el guarda
        found = false;  // Reset
    }

    // Ordenar vectors de números juntament amb el freq. (Mètode Bubble Sort)
    for (int i = 0; i<vNums.size()-1; i++) {
        swapped = false;
        for (int j = 0; j<vNums.size()-i-1; j++) {
            if (vNums[j]>vNums[j+1]) {  // Fem el canvi tant del número com la relació amb el seu comptador.
                temp_num = vNums[j+1];
                temp_freq = vFreq[j+1];
                vNums[j+1] = vNums[j];
                vFreq[j+1] = vFreq[j];
                vNums[j] = temp_num;
                vFreq[j] = temp_freq;
                swapped = true;
            }
        }
        if (not swapped) break;  // Optimitzar perquè significarà que no ha fet cap moviment (aka tot ordenat)
    }

    // Mostrar Resultats
    for (int i = 0; i<=vNums.size()-1; i++) {
        cout << vNums[i] << " : " << vFreq[i] << endl;
    }
}
*/