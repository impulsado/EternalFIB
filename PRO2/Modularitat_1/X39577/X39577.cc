#include <vector>
#include "Estudiant.hh"
#include <iostream>
using namespace std;

int main () {
    int num_est, num_assig, num_selec;
    cin >> num_est >> num_assig >> num_selec;

    vector<int> seleccionades(num_selec);
    for (int i = 0; i<num_selec; i++) cin >> seleccionades[i];

    vector<Estudiant> estudiants(num_est);
    vector<double> notes(num_assig);
    int dni;
    for (int i = 0; i<num_est; i++) {
        // Crear Alumne
        cin >> dni;
        estudiants[i] = Estudiant(dni);
        
        // Demanar notes
        for (int j = 0; j<num_assig; j++) cin >> notes[j];

        // Fer Mitjana
        double nota = 0;
        for (int j = 0; j<num_selec; j++) nota += notes[seleccionades[j]-1];
        nota /= num_selec;

        // Guardar nota
        estudiants[i].afegir_nota(nota);

        // Mostrar resultat
        cout << dni << ' ' << nota << endl;
    }

}