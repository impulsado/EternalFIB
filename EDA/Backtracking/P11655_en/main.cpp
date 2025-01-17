/*
Mostrar conjunt de numeros que la seva suma faci la ingressada per l'usuari.
Consideracions:
- Numeros naturals (0) inclos.
- Tindre en compte el que falta.
*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;


void solve(const VI& vnums, VI& vseen, int suma_actual, int suma_restant, const int& usr_sum, int index) {
    int n = vnums.size();

    // === BASE CASE
    if (suma_actual > usr_sum) return;
    else if (suma_actual + suma_restant < usr_sum) return;

    // 1. És valid per a la suma
    // NOTA: Si no especifico que index == n, hi haura solucions valides que es printant n-index vegades
    // Això és perque el vnums[index] ha passat els requisits i si printem una altra vegada la solució, hi haura solucions repetides. 
    if (suma_actual == usr_sum && index == n) {
        bool is_first = true;
        cout << '{';
        for (int i = 0; i<n; i++) {
            if (is_first && vseen[i]) {cout << vnums[i]; is_first = false;}
            else if (vseen[i]) cout << ',' << vnums[i];
        }
        cout << '}' << endl;
    
        return;
    }

    // === GENERAL CASE
    // NOTA: Per a exercicis d'incloure o no, un element, es millor fer-ho aixi que no pas amb un for().
    
    // Opció 1: Inclós
    vseen[index] = 1;
    solve(vnums, vseen, suma_actual+vnums[index], suma_restant-vnums[index], usr_sum, index+1);

    // Opció 2: No Inclós
    vseen[index] = 0;
    solve(vnums, vseen, suma_actual, suma_restant-vnums[index], usr_sum, index+1);
}

int main(void) {
    int usr_sum, usr_quant_nums, usr_num;
    cin >> usr_sum;
    cin >> usr_quant_nums;
    VI vnums(usr_quant_nums);
    VI vseen(usr_quant_nums, 0);  // Guardar indexs vistos
    VI vsol;
    int suma_actual, suma_restant;
    suma_actual = suma_restant = 0;
    for (int i = 0; i<usr_quant_nums; i++) {
        cin >> usr_num;
        vnums[i] = usr_num;
        suma_restant += usr_num;
    }

    int index = 0;
    solve(vnums, vseen, suma_actual, suma_restant, usr_sum, index);
}