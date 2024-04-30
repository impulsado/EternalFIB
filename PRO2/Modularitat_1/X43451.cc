#include "Estudiant.hh"
#include <vector>
 
void arroduniment(Estudiant& est){
    est.modificar_nota(((int) (10. * (est.consultar_nota() + 0.05)))/ 10.0);
}
 
void arrodonir_vector(vector<Estudiant>& v){
    int alumne_seleccionat = 0;
 
    while (alumne_seleccionat < v.size())
    {
        if (v[alumne_seleccionat].te_nota()){
            arroduniment(v[alumne_seleccionat]);
        }
        alumne_seleccionat ++;
    }
 
}