#include <iostream>
#include "Estudiant.hh"
#include "Cjt_estudiants.hh"
using namespace std;

double redondear(double r) {  
    return int(10.*(r + 0.05)) / 10.0;
}

int main () {
    Cjt_estudiants cjt_alumnes;
    cjt_alumnes.llegir();

    int usr_op, DNI;
    double nota;
    while (cin >> usr_op and usr_op!=-6) {
        // Afegir nou estudiant
        if (usr_op==-1) {
            cin >> DNI >> nota;
            bool alum_existeix = cjt_alumnes.existeix_estudiant(DNI);
            if (not alum_existeix) {
                Estudiant temp(DNI);
                if (0<=nota and nota<=10) temp.afegir_nota(nota);
                cjt_alumnes.afegir_estudiant(temp);
            }
            else {
                cout << "el estudiante " << DNI << " ya estaba" << endl;
                cout << endl;
            }
        }
        // Consultar nota d'estudiant amb DNI
        else if (usr_op==-2) {
            cin >> DNI;
            bool alum_existeix = cjt_alumnes.existeix_estudiant(DNI);
            if (alum_existeix) {
                if (cjt_alumnes.consultar_estudiant(DNI).te_nota()) cout << "el estudiante " << DNI << " tiene nota " << cjt_alumnes.consultar_estudiant(DNI).consultar_nota() << endl;
                else cout << "el estudiante " << DNI << " no tiene nota" << endl;
            }
            else cout << "el estudiante " << DNI << " no esta" << endl;
            cout << endl;
        }
        // Modificar nota
        else if (usr_op==-3) {
            cin >> DNI >> nota;
            bool alum_existeix = cjt_alumnes.existeix_estudiant(DNI);
            if (alum_existeix) {
                Estudiant temp(DNI);
                temp.afegir_nota(nota);
                cjt_alumnes.modificar_estudiant(temp);  // No se jo aquest
            }
            else {
                cout << "el estudiante " << DNI << " no esta" << endl;
                cout << endl;
            }
            

        }
        // Arrodonir la nota de tots els alumnes
        else if (usr_op==-4) {
            int mida = cjt_alumnes.mida();
            for (int i = 1; i<=mida; i++) {
                Estudiant temp = cjt_alumnes.consultar_iessim(i);
                if (temp.te_nota()) {
                    double nota_arro = redondear(temp.consultar_nota());
                    temp.modificar_nota(nota_arro);
                    cjt_alumnes.modificar_iessim(i,temp);
                }
            }
        }
        // Mostrar estudiants
        else if (usr_op==-5) {
            cjt_alumnes.escriure();
            cout << endl;
        }
    }
}