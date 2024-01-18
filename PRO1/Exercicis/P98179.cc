#include <iostream>
#include <vector>
using namespace std;

void insert(vector<double>& v) {
    bool changed = true;
    double tmp;
    int i = v.size()-1;

    //Bubble sort des del final
    while (i>0 and changed) {
        if (v[i]<v[i-1]) {
            changed = true;
            tmp = v[i];
            v[i] = v[i-1];
            v[i-1] = tmp;
        } else changed = false;
        i--;
    }
}

int main() {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(4);
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) {
            cin >> V[i];
        }
        insert(V);
        for (int i = 0; i < n; ++i) {
            cout << " " << V[i];
        }
        cout << endl;
    }
    return 0;
}
