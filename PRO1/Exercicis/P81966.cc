#include <iostream>
#include <vector>
using namespace std;

int posicio(double x, const vector<double>& v, int esq, int dre) {
    if (esq>dre) return -1; // Ho diu enunciat

    int mig = esq + (dre-esq)/2;  // Calculat d'aquesta manera perque no hi hagi ovf

    if (x<v[mig]) return posicio(x,v,esq,mig-1);
    else if (x>v[mig]) return posicio(x,v,mig+1,dre);
    else return mig;
}

int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i)
            cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            int esq, dre;
            cin >> x >> esq >> dre;
            cout << posicio(x, V, esq, dre) << endl;
        }
    }
    return 0;
}
