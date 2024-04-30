#include "Estudiant.hh"
#include <vector>
#include <set>

vector<Estudiant> round_max() {
    int num, DNI;
    double nota;

    // Agafar estudiants
    cin >> num;
    vector<Estudiant> alumnes(num);
    for (int i = 0; i<num; i++) {
        cin >> DNI >> nota;
        alumnes[i] = Estudiant(DNI);
        if (0<=nota and nota<=10) alumnes[i].afegir_nota(nota);
    }

    // Processar estudiants
    vector<Estudiant> result;
    result.push_back(alumnes[0]);
    
    for (int i = 1; i<num; i++) {
        DNI = alumnes[i].consultar_DNI();
        int last_dni = result[result.size()-1].consultar_DNI();

        if (alumnes[i].te_nota() and DNI==last_dni) {
            if (result[result.size()-1].te_nota()) {
                int last_nota = result[result.size()-1].consultar_nota();
                nota = alumnes[i].consultar_nota();
                if (nota>last_nota) result[result.size()-1] = alumnes[i];
            }
            else {
                result[result.size()-1] = alumnes[i];
            }
        }
        else if (DNI!=last_dni) {
            result.push_back(alumnes[i]);
        }
    }

    // Mostrar resultat
    for (int i = 0; i<result.size(); i++) {
        cout << result[i].consultar_DNI() << ' ';

        if (result[i].te_nota()) cout << result[i].consultar_nota() << endl;
        else cout << "NP" << endl;
    }

    return result;
}

int main () {
    vector<Estudiant> alumnes = round_max();
}
