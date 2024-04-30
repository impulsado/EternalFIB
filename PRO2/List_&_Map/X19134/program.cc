#include <iostream>
#include "ParInt.hh"
#include "LlistaIOParInt.hh"
using namespace std;

ParInt Calculs(list<ParInt> llista, int usr_num) {
    int counter, sum;
    counter = sum = 0;

    list<ParInt>::iterator it;
    for (it = llista.begin(); it != llista.end(); it++) {
        ParInt temp = *it;
        if (temp.primer() == usr_num) counter++, sum += temp.segon();
    }

    ParInt resultat(counter,sum);
    return resultat;
}

int main() {
    list<ParInt> llista;
    LlegirLlistaParInt(llista);
    int usr_num;
    cin >> usr_num;
    ParInt resultat; 
    resultat = Calculs(llista, usr_num);
    cout << usr_num << ' '; resultat.escriure();
}