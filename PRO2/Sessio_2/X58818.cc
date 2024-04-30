#include <iostream>
#include <vector>
using namespace std;

/*
1. Faig còpia del 'n-1'
1.1. Si 'n' parell --> return Còpia (n-1) NO Desplaçat + Còpia (n-1) SI Desplaçat
1.2. Si 'n' senar --> return Còpia (n-1) SI Desplaçat + Còpia (n-1) NO Desplaçat
*/

vector<string> dibuix(int num) {
    // Cas Base
    if (num==0) {
        vector<string> temp;
        temp.push_back("*");
        return temp;
    }

    // Quantitat espais i mida
    int base = 2, mida = 1;
    string espais = "";
    for (int i = 0; i<num; i++) mida *= base;
    for (int i = 0; i<mida/2; i++) espais += " ";

    // Crear 2 vectors amb el patró anterior i el actual
    if (num%2==0) {  // [Anterior] NO Desplaçat + [Actual] SI Desplaçat
        vector<string> anterior = dibuix(num-1);
        
        vector<string> actual(mida/2);
        for (int i = 0; i<actual.size(); i++) actual[i].append(espais);
        vector<string> actual_temp = dibuix(num-1);
        for (int i = 0; i<actual_temp.size(); i++) actual[i] += actual_temp[i];
        
        // Ajuntar vectors
        vector<string> final = anterior;
        final.insert(final.end(), actual.begin(), actual.end());   
        return final;
    } else {  // [Anterior] SI Desplaçat + [Actual] NO Desplaçat
        vector<string> actual(mida/2);
        for (int i = 0; i<actual.size(); i++) actual[i].append(espais);
        vector<string> actual_temp = dibuix(num-1);
        for (int i = 0; i<actual_temp.size(); i++) actual[i] += actual_temp[i];

        vector<string> anterior = dibuix(num-1);

        // Ajuntar vectors
        vector<string> final = actual;
        final.insert(final.end(), anterior.begin(), anterior.end());
        return final;
    }

}

void mostrar(const vector<string>& linies) {
    for (int i = 0; i<linies.size(); i++) cout << linies[i] << endl;
}

int main () {
    int usr_num;

    while (cin >> usr_num) {
        vector<string> linies, actual, anterior;
        linies = dibuix(usr_num);
        mostrar(linies);
        cout << "----------" << endl;
    }
}