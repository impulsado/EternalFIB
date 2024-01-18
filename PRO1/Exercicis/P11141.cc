#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
using namespace std;

struct Estudiant {
    int dni;
    string nom;
    double nota;
    bool repetidor;
};

void informacio(const vector<Estudiant>& es, double& min, double& max, double& mitj) {
    int counter;  // Alumnes que compleixen criteri
    max = mitj = counter = 0;
    min = 10;

    for (int i = 0; i<es.size(); i++) {
        if (es[i].repetidor or es[i].nota==-1) continue;
        
        counter++;  // Compleix criteri pq ha passat els filtres
        if (es[i].nota<min) min = es[i].nota;
        if (es[i].nota>max) max = es[i].nota;
        mitj += es[i].nota;
    }

    if (counter==0) max = min = mitj = -1;
    else mitj /= counter;
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(4); 
    int n;
    while (cin >> n) {
        vector<Estudiant> es(n);
        for (int i=0; i<n; ++i) {
            cin >> es[i].nota >> es[i].repetidor;
        }
        double min, max, avg;
        informacio(es, min, max, avg);
        cout << min << " " << max << " " << avg << endl;
    }
}