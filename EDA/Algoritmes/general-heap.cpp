/*
=== OPERACIONS === 
- Auxiliar: Funcions que farem ús.
    - flotar: Comprovar que el seu pare sigui més petit/gran o sino interncanviar [O(logn))]
    - enfonsar: Comprovar si algun dels seus fills es més petit/gran o sino intercanviar [O(logn))]
- Insert: Necessitarem que ficar un element es quedi en la posicio que toca
    - # No podem insertar on ens doni la gana. Insertem a l'ultima posicio. 
    - # Necessitarem "flotar"
- Get min/max: Saber el top() [O(1)]
- Extract min/max: Agafem el top i l'eliminem, ara pot ser que el nou top no sigui el que toca
    - # No podem eliminar el root simplement. Fem interncanvi amb ultim element (fulla) i eliminem l'ultima posicio
    - # Necessitarem "enfonsar"
- Update heap: Actualitzar un valor del heap/arbre no es pot fer que no estigui en la pos correcta.
    - # Necessitarem "enfonsar" o "flotar" (Depen de si new_value > o < old_value)
- Build heap (heapify): Conviertir d'un vector qualsevol un max/min-heap.
    - # Es millor fer "enfonsar" pq aixi no passa que haguem fet flotar un element que hem d'enfonsar posteriorment.
    - # Necessitem "enfonsar"
*/

#include <vector>
#include <iostream>
using namespace std;

typedef vector<int> VI;

int get_pos_father(const int& pos) {
    if (pos <= 1) return -1;  // Pare no te arrel
    return pos/2;
}

int get_pos_left_child(const VI& v, const int& pos) {
    return 2*pos;
}

int get_pos_right_child(const VI& v, const int& pos) {
    return (2*pos)+1;
}

void flotar(VI& v, const int& pos, const string& mode) {
    bool swapped = true;
    int pare = get_pos_father(pos);

    while (pare > 0 && swapped) {
        if (mode == "min" && v[pare]>v[pos]) swap(v[pare], v[pos]);
        else if (mode == "max" && v[pare]<v[pos]) swap(v[pare], v[pos]);
        else swapped = false;
        pare = get_pos_father(pare);
    }
}

void enfonsar(VI& v, int pos, const string& mode) {
    int n = v.size()-1;

    bool swapped = true;

    while (pos<=n/2 && swapped) {
        int left = get_pos_left_child(v, pos);
        int right = get_pos_right_child(v, pos);
        int target_pos = pos;
        swapped = false;

        if (mode == "min") {
            if (left<=n && v[left]<v[target_pos]) target_pos = left;
            if (right<=n && v[right]<v[target_pos]) target_pos = right;
        }
        else if (mode == "max") {
            if (left<=n && v[left]>v[target_pos]) target_pos = left;
            if (right<=n && v[right]>v[target_pos]) target_pos = right;
        }
        
        if (target_pos == pos) continue;
        swap(v[pos], v[target_pos]);
        swapped = true;
        pos = target_pos;  // Actualitzar la nova posicio de l'enfonsament
    }
}

void insert(VI& v, const int& num, const string& mode) {
    v.push_back(num);
    int n = v.size();

    flotar(v, n-1, mode);
}

int get_top(const VI& v) {
    return v[1];
}

void extract_pos(VI& v, int& pos, const string& mode) {
    int n = v.size();
    swap(v[pos], v[n-1]);
    v.pop_back(); n--;
    
    enfonsar(v, pos, mode);
}

void update_heap(VI& v, int& pos, const int& new_value, const string& mode) {
    int old_value = v[pos];
    v[pos] = new_value;

    if (old_value<new_value && mode == "max") flotar(v, pos, mode);
    else if (old_value>new_value && mode == "min") flotar(v, pos, mode);
    else enfonsar(v, pos, mode);

    return;
}

// Convertir vector desordenat en un {max,min}-heap
void heapify(VI& v, const string& mode) {
    int n = v.size()-1;
    
    // NOTA: Les fulles no es poden enfonsar. Sabem que els arbres complets tenen n/2 fulles
    for (int i = n/2; i>0; i--) {
        enfonsar(v, i, mode);
    }
}

int main(void) {
    VI vnums = {0,9,8,7,13,12};
    for (int num : vnums) cout << num << ','; cout << endl;
    heapify(vnums, "max");
    for (int num : vnums) cout << num << ','; cout << endl;
}