#include "Estudiant.hh"
#include <vector>

pair<int,int>  max_min_vest(const vector<Estudiant>& v) {
    pair<int,int> result;
    result.first = -1;
    result.second = -1;
    
    if (v.empty()) return result;

    bool is_first = true;
    int min_dni, max_dni;
    double min_nota, max_nota;
    
    for (int i = 0; i<v.size(); i++) {
        if (v[i].te_nota()) {
            if (is_first) {
                result.first = result.second = i;
                max_nota = min_nota = v[i].consultar_nota();
                max_dni = min_dni = v[i].consultar_DNI();
                is_first = false;
                continue;
            }

            double nota = v[i].consultar_nota();
            int dni = v[i].consultar_DNI();

            if (nota>max_nota or (nota==max_nota and dni<max_dni)) {
                result.first = i;
                max_dni = dni;
                max_nota = nota;
            }
            
            if (nota<min_nota or (nota==min_nota and dni<min_dni)) {
                result.second = i;
                min_dni = dni;
                min_nota = nota;
            }
        }
    }

    return result;
}