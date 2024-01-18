#include <iostream>
#include <vector>
using namespace std;

int avalua(const vector<int>& P, int x) {
    int suma = 0;

    for (int i = P.size()-1; i>0; i--) {
        suma = (P[i]+suma)*x;
    }

    suma = suma + P[0];  // Sumar terme independent
    return suma;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> P(n);
        for (int i = 0; i < n; ++i)
            cin >> P[i];
        int x;
        cin >> x;
        cout << avalua(P, x) << endl;
    }
    return 0;
}