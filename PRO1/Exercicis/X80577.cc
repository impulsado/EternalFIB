#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int max(int a, int b) {
    if (a>=b) return a;
    else return b;
}

bool afitat(vector<int> llista) {
    // Saber el maxim de tota la llista
    int maxim = llista[0];
    for (int i = 1; i<llista.size()-1; i++) {
        maxim = max(maxim,llista[i]);
    }

    // Saber si tots els valors menys el primer compleixen
    int valor = maxim+1;
    for (int i = 1; i<llista.size();i++) {
        if (llista[i]>valor) return false;
    }

    return true;
}

int main() {
    // Demanar numeros
    int usr_num;
    vector<int> numeros;
    while (cin >> usr_num) {
        if (usr_num!=-1) numeros.push_back(usr_num);
        else {
            // Cas Especial
            if (numeros.empty()) {cout << 0 << endl; return -1;}

            // Buscar llistes
            vector<int> valors;
            int i = 0, j;
            while (i<numeros.size()) {
                bool possible = true;
                vector<int> llista;
                llista.push_back(numeros[i]);
                j = i+1;
                while (j<numeros.size()) {
                    llista.push_back(numeros[j]);
                    if(afitat(llista)) j++;
                    else {
                        possible = false; 
                        break;
                    }
                }
                if (possible) valors.push_back(llista.size());
                else valors.push_back(llista.size()-1);
                i++;
            }

            // Mostrar valor
            sort(valors.begin(), valors.end());
            cout << valors.back() << endl;
            numeros = {};  // Reset
        }
    } 
}