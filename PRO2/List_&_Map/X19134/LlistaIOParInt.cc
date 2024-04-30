#include "LlistaIOParInt.hh"
using namespace std;

void LlegirLlistaParInt(list<ParInt>& l) {
    ParInt usr_num;
    while (usr_num.llegir()) {
        /*
        if (usr_num.primer()==0 and usr_num.segon()==0) break;
        Això no fa falta donat que llegir() retorna true si no són 0s
        */
        l.push_back(usr_num);
    }
}