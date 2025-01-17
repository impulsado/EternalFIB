/*
=== IDEA ===
Tindre un max-heap, agafar l'element del top() [El més gran] i ficar-ho en posicio del final del vector.
Decrementar index, i reconfigurem el heap, perque torni a ser un max-heap.
Repetim proces.
Notem que de l'element ficat fins al final estarà ordenat.

=== OBSERVACIONS ===
Necessitarem:
- Funció que faci el max-heap d'un vector qualsevol
- Funció que pugui re-adaptar un heap per fer un max-heap
Podem veure que la primera funció pot estar inclosa en la segona.
*/

#include <vector>
#include <iostream>
using namespace std;

typedef vector<int> VI;

void heapify(VI& v, const int& act, const int& limit) {
    int left = 2*act;
    int right = 2*act + 1;

    if (left <= limit) {

    }
    if (right <= limit) {

    }
}

void vector_to_max_heap(VI& v, const int& limit) {

}

// Donat un v, l'ordena creixent
void heap_sort(VI& v) {
    int n = v.size();
    vector_to_max_heap(v, n);
    
    for (int i = n-1; i>0; i--) {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}