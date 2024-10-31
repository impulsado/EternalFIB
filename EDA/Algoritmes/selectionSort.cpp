#include <vector>
#include <iostream>
using namespace std;

/*
=== IDEA ===
Agafar un element (en ordre de pos.) i buscar si hi ha algun altre més petit.
Si hi ha, significa que aquest no estava en el seu lloc i s'ha de ficar on pertoca.
Sempre assegurem que de v[0] ... v[i] hi haurà els números més petits ja en ordre.

=== COST ===
BEST = AVG = WORST = O(n^2)

=== ASC/DESC ===
Per modificar el funcionament, simplement hem de canviar:
|     ASC    |     DESC   |
| ---------- | ---------- |
| v[j]<v[i]  | v[j]>v[i]  | 
*/

void selectionSort(vector<int>& v) {
    // 1. Comencem per l'inici fins n-1 perquè sino j sortirià de rang.
    for (int i = 0; i<v.size()-1; i++) {
        // 2. Agafem "un punter" que servirà per identificar la pos.
        // de l'element més petit vist en aquesta iteració. 
        // Agafem el primer element d'on partim de referència.
        int min = i;

        // 3. A partir del següent element fins al final, comprovem si hi ha un altre més petit.
        // Si hi ha, actualitzem on està posicionat.
        for (int j = i+1; j<v.size(); j++) {
            if (v[j]<v[min]) min = j;
        }

        // 4. Finalment intercanviem el més petit vist, per l'element per on hem començat.
        // Si aquest ja era el més petit, farem un swap amb ell mateix i no hi haurà problema.
        swap(v[i], v[min]);
    }
}