#include <iostream>
#include <vector>
using namespace std;

vector<double> difference(const vector<double>& V1, const vector<double>& V2) {
    int V1_size = V1.size(), V2_size = V2.size();
    vector<double> auxiliar(V1_size);  // Donat que està ple de 0's i només volem els únics
    vector<double> resultats;  
    int iV1, iV2, iAux;
    iV1 = iV2 = iAux = 0;

    while (iV1<V1_size and iV2<V2_size) {
        if (V1[iV1]<V2[iV2]) {
            if (iAux==0 or auxiliar[iAux-1]!=V1[iV1]) {
                auxiliar[iAux] = V1[iV1];
                iAux++;
            }
            iV1++;
        } else if (V1[iV1]>V2[iV2]) {
            iV2++;
        } else {
            iV1++;
        }
    }

    while (iV1<V1_size) {  // Ficar els elements retants de V1
        if (auxiliar[iAux-1]!=V1[iV1]) {
            auxiliar[iAux] = V1[iV1];
            iAux++;
        }
        iV1++;
    }

    // Ficar només els que no són 0's
    for (int i = 0; i<iAux; i++) resultats.push_back(auxiliar[i]);

    return resultats;
}

int main() {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(4);
    int n1;
    while (cin >> n1) {
        vector<double> V1(n1);
        for (int i = 0; i < n1; ++i)
            cin >> V1[i];
        int n2;
        cin >> n2;
        vector<double> V2(n2);
        for (int i = 0; i < n2; ++i)
            cin >> V2[i];

        vector<double> res = difference(V1, V2);

        int n3 = res.size();
        cout << n3 << endl;
        for (int i = 0; i < n3; ++i)
            cout << " " << res[i];
        cout << endl
             << endl;

        for (int r = 0; r < 200; ++r) {
            vector<double> res2 = difference(V1, V2);
            if (res2 != res)
                cout << "Resultats diferents amb la mateixa entrada!" << endl;
        }
    }
    return 0;
}
