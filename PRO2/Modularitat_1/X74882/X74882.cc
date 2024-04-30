#include "Estudiant.hh"
#include "Cjt_estudiants.hh"

int main () {
    Cjt_estudiants aval1;
    Cjt_estudiants aval2;
    aval1.llegir();
    aval2.llegir();
    int mida = aval1.mida();

    for (int i = 1; i<=mida; i++) {
        Estudiant est1 = aval1.consultar_iessim(i);
        Estudiant est2 = aval2.consultar_iessim(i);

        if (est1.te_nota() and not est2.te_nota()) continue;
        else if (not est1.te_nota() and est2.te_nota()) {
            double est2_nota = est2.consultar_nota();
            Estudiant temp(est2.consultar_DNI());
            temp.afegir_nota(est2_nota);
            aval1.modificar_iessim(i,temp);
        }
        else if (est1.te_nota() and est2.te_nota()) {
            double est1_nota = est1.consultar_nota();
            double est2_nota = est2.consultar_nota();
            if (est1_nota<est2_nota) {
                Estudiant temp(est2.consultar_DNI());
                temp.afegir_nota(est2_nota);
                aval1.modificar_iessim(i,temp);
            }
        }
    }

    aval1.escriure();
}
