#include "Estudiant.hh"
#include <vector>

/* ERROR
3
1111 9
1111 -1
1111 7
*/
void simplificar_vector(vector<Estudiant>& v, int& pos) {
    int size = v.size();
    pos = 0;

    for (int i = 1; i<size; i++) {
        int act_dni = v[i].consultar_DNI();
        int prev_dni = v[pos].consultar_DNI();

        if (act_dni==prev_dni) {
            if (v[i].te_nota()) {
                if (v[pos].te_nota() and v[pos].consultar_nota()<v[i].consultar_nota()) {
                    v[pos].modificar_nota(v[i].consultar_nota());
                }
                else if (not v[pos].te_nota()) {
                    v[pos].afegir_nota(v[i].consultar_nota());
                }
            }
        }
        else {
            pos++;
            swap(v[pos],v[i]);
        }
    }
}
/*
int main () {
    int num, DNI;
    double nota;
    cin >> num;
    vector<Estudiant> alumnes(num);
    for (int i = 0; i<num; i++) {
        cin >> DNI >> nota;
        alumnes[i] = Estudiant(DNI);
        if (0<=nota and nota<=10) alumnes[i].afegir_nota(nota);
    }
    int pos = 0;
    simplificar_vector(alumnes,pos);

    // Mostrar resultat
    for (int i = 0; i<alumnes.size(); i++) {
        cout << alumnes[i].consultar_DNI() << ' ';

        if (alumnes[i].te_nota()) cout << alumnes[i].consultar_nota() << endl;
        else cout << "NP" << endl;
    }
}

*/
/*
void simplificar_vector(vector<Estudiant>& v, int& pos) {
    pos = 1;
    while (pos<v.size()) {
        int last_dni = v[pos-1].consultar_DNI();
        int act_dni = v[pos].consultar_DNI();

        if (last_dni==act_dni) {
            double act_nota = -1;  // Suposem que no te nota per defecte
            if (v[pos].te_nota()) act_nota = v[pos].consultar_nota();
            
            if (act_nota==-1) v.erase(v.begin()+pos);
            else if (v[pos-1].te_nota() and act_nota!=-1) {
                double last_nota = v[pos-1].consultar_nota();
                if (act_nota>last_nota) {
                    v[pos-1].modificar_nota(act_nota);
                    v.erase(v.begin()+pos);
                }
                else {
                    v.erase(v.begin()+pos);
                    pos++;
                }
            }
            else if (not v[pos-1].te_nota() and act_nota!=-1) {
                v[pos-1].afegir_nota(act_nota);
                v.erase(v.begin()+pos);
            }

        } else pos++;
    }
}
*/