#include <vector>
#include <iostream>
using namespace std;

/*
=== IDEA ===
Agafar meitat esquerra i ordenar-ho.
Agafar meitat dreta i ordenar-ho.
Com que hi ha elements de la dreta que poden anar a l'esquerra i viceversa, s'ha de recorrer
desde l'inici de l'esquerra (low) fins el final de la dreta (high) i reposicionar els que estiguin malament.
Això es fa en un vector temporal per a no perdre rastre de tots els nombres i posteriorment sobrescius.

=== COST ===
BEST = AVG = WORST = O(n*log(n))

=== ASC/DESC ===
Per modificar el funcionament, simplement hem de canviar:
|           ASC         |           DESC         |
| --------------------- | ---------------------- |
| v[left] <= v[right]   | v[left] >= v[right]    |
| temp[k++] = v[left++] | temp[k++] = v[right++] |
*/

void merge(vector<int>& v, int low, int high) {
    // 1. Crear vector temporal on anirem ficant l'ordre obtingut del merge
    int k = 0;
    vector<int> temp(high-low+1);
    
    // 2. Determinar minim esquerra i mínim dreta
    int mid = low + (high-low)/2;
    int left = low, right = mid+1;

    // 3. Avançar els mínims fins als seus respectius màxims
    // Guardar en el vector temporal en ordre, perque supossem que left --> mid estàn ordentats
    // i que right --> high també (Per la màgia de la recursivitat).
    while (left<=mid && right<=high) {
        if (v[left]<=v[right]) temp[k++] = v[left++];
        else temp[k++] = v[right++];
    }

    // 4. Ficar els elements que ens falten per si hi havia algun subvector més petit que l'altre.
    while (left<=mid) temp[k++] = v[left++];
    while (right<=high) temp[k++] = v[right++];

    // 5. Sobreescriure el rang on hem estat treballant amb el vector temporal que si esta ordenat.
    for (k = low; k<high; k++) v[k] = temp[k];
}

void mergeSort(vector<int>& v, int low, int high) {
    // === BASE CASE ===
    if (low>=high) return;

    // === GENERAL CASE ===
    // 1. Trobar el mid per a dividir vector en dues parts
    int mid = low + (high-low)/2;
    
    // 2. Fer crida recursiva amb les respectives meitats.
    mergeSort(v, low, mid);
    mergeSort(v, mid+1, high);
    
    // 3. Ordenar el rang total que hem mirat.
    merge(v, low, high);
}