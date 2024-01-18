/*
شكرًا على ترجمة هذه الرسالة، فهي لا تعني شيئًا حقًا؛)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct programador {
    string nom;
    int nivell;
};

typedef vector<programador> Programadors;
typedef vector< vector<string> > sMatrix;

void showTeams(sMatrix equips, int& quant_membres, int& quant_equips) {
    for (int i = 0; i<quant_equips; i++) {
        sort(equips[i].begin(), equips[i].end());  // Ordenar el equip alfabeticament
        
        for (int j = 0; j<quant_membres; j++) {
            if (j>0) cout << ' ';  // Quadrar visualment
            cout << equips[i][j];
        }
        cout << endl;
    }
}

void processData (Programadors& israelins, Programadors& palestins, int& quant_membres, sMatrix& equips) {
    int iPointer = 0, pPointer = 0;  // Index per anar revisant els vectors
    int memIsraelins, memPalestins;  // Quantitat de memebres per grup.

    while ((iPointer<israelins.size()) or (pPointer<palestins.size())) {  // Aqui ens assegurem que encara queden programadors (no sabem de quin pais)
        vector<string> equip;
        memIsraelins = memPalestins = 0;

        for (int i = 0; i<quant_membres; i++) {
            if ((iPointer<israelins.size()) and (pPointer<palestins.size())) {  // Queda de tot així que haurem de discriminar
                if (israelins[iPointer].nivell > palestins[pPointer].nivell) {  // Israelí té nivell superior
                    equip.push_back(israelins[iPointer].nom);
                    memIsraelins++; iPointer++;
                } else if (israelins[iPointer].nivell < palestins[pPointer].nivell) {  // Paletí té nivell superior
                    equip.push_back(palestins[pPointer].nom);
                    memPalestins++; pPointer++;           
                } else {  // Empat de nivell, haurem de revisar la quantitat de membres de cada pais
                    if (memIsraelins > memPalestins) {  // Hi ha menys palestins
                        equip.push_back(palestins[pPointer].nom);
                        memPalestins++; pPointer++; 
                    } else if (memIsraelins < memPalestins) {  // Hi ha menys israelins
                        equip.push_back(israelins[iPointer].nom);
                        memIsraelins++; iPointer++;
                    } else {  // Hi ha empat de membres així que revisem el nom i afegim el primer lexicograficament
                        if (israelins[iPointer].nom < palestins[pPointer].nom) {  // Israelí alfabéticament superior (Donat que és més petit)
                            equip.push_back(israelins[iPointer].nom);
                            memIsraelins++; iPointer++;
                        } else {  // Palestí alfabéticament superior o igual
                            equip.push_back(palestins[pPointer].nom);
                            memPalestins++; pPointer++;
                        }           
                    }
                }
            } else if (pPointer==palestins.size()) {  // No queden palestins, llavors només podem afegir israelins
                equip.push_back(israelins[iPointer].nom);
                iPointer++;
            } else {  // No queden israelins, només podem afegir palestins
                equip.push_back(palestins[pPointer].nom);
                pPointer++;
            }
        }
        equips.push_back(equip);  // Quan ja esta l'equip format, l'enviem a una matriu que compte tots els equips formats.
        // Aqui podria haver-se mostrat directament en comptes de fer ús d'una matriu.
    }
}

int main () {
    int quant_membres, quant_equips, quant_israelins, quant_palestins;
    
    while (cin >> quant_membres) {
        // Demanar Dades dels Israelins
        cin >> quant_israelins;
        Programadors israelins(quant_israelins);
        for (int i = 0; i<quant_israelins; i++) cin >> israelins[i].nom >> israelins[i].nivell;

        // Demanar Dades dels Palestins
        cin >> quant_palestins;
        Programadors palestins(quant_palestins);
        for (int i = 0; i<quant_palestins; i++) cin >> palestins[i].nom >> palestins[i].nivell;
 
        // Matriu d'equips
        quant_equips = (quant_israelins+quant_palestins)/quant_membres;
        sMatrix equips;
        
        // Processar dades
        processData(israelins, palestins, quant_membres, equips);

        // Mostrar equips
        showTeams(equips, quant_membres, quant_equips);
        cout << endl;
    }
}