#include <vector>
#include <iostream>
using namespace std;

/*
=== IDEA ===
Agafem un element de v (key).
Si hi ha elements més grans que aquest previament, significa que s'hauràn de moure per deixar 
un lloc i posteriorment insertar on toca el key.
Això ho anem fent n-1 vegades perque el primer (v[0]) no té amb qui comparar-se previament.

=== COST ===
WORST = AVG = O(n^2)
BEST = O(n)

=== ASC/DESC ===
|    ASC    |   DESC    |
|-----------|-----------|
|  v[j]>key | v[j]<key  |
*/

void insertionSort(vector<int>& v) {
    // 1. Mirem tots els elements menys el primer
    for (int i = 1; i<v.size(); i++) {
        // 2. Seleccionem el nombre que haurem de reposicionar si es que 
        // hi ha elements més grans que ell previament.
        int key = v[i];

        // 3. Fem el bucle de buscar previament fins al final (v[0]).
        // Ens aturem si arribem al final o hem trobat un nombre més petit que el que hem agafat de ref.
        // Aquest últim cas és perquè significarà que els previs a aquest primer, també seràn més
        // petits, així que ja hem troba la posició on va key.
        int j = i-1;
        while (j>=0 && v[j]>key) {
            // 4. Anem creant "el forat" per a ficar el key.
            v[j+1] = v[j];
            j--;
        }
        
        // 5. Donat que no hem pogut aturar-se abans, ara j apunta a un element més petit o igual que key
        // Aixòi siginifica que key va despres d'aquest v[j], es per això que fem j+1.
        v[j+1] = key;
    }
}