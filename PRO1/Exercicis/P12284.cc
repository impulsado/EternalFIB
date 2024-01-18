#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Paraula {
    string name;
    int times;
};

bool customFilter(const Paraula& p1, const Paraula& p2) {
    if (p1.times!=p2.times) return p1.times>p2.times;
    return p1.name<p2.name;
}

int main() {
    int usr_quant, usr_top;

    while (cin >> usr_quant >> usr_top) {
        // Demanar paraules
        vector<string> paraules(usr_quant);
        for (int i = 0; i<usr_quant; i++) {
            cin >> paraules[i];
        }
        
        // Ordenar alfabeticament (arbitrari)
        sort(paraules.begin(), paraules.end());
        
        // Buscar quantitat de cadascuna
        vector<Paraula> ranking;
        string last_word = paraules[0];
        ranking.push_back({last_word,1});
        
        for (int i = 1; i<usr_quant; i++) {
            if (paraules[i]==last_word) {
                ranking.back().times += 1;
            } else {
                last_word = paraules[i];
                ranking.push_back({last_word,1});
            }
        }

        // Ordenar per times
        sort(ranking.begin(), ranking.end(), customFilter);

        // Mostrar Resultat
        for (int i = 0; i<usr_top and i<ranking.size(); i++) {
            cout << ranking[i].name << endl;
        }
        cout << "----------" << endl;
    }
}