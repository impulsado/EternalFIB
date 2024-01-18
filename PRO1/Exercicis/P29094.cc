#include <iostream>
#include <vector>
using namespace std;

struct num {
    double num;
    int pos;
};

int position_maximum(const vector<double>& v, int m) {
    // Colega esta gent no diu perque serveix m o que. 
    num maxim;
    maxim.num = 0.0;
    maxim.pos = 0;

    for (int i = 0; i<=m; i++) {
        if (maxim.num<=v[m-i]) {
            maxim.num = v[m-i];
            maxim.pos = m-i;
        }
    }

    return maxim.pos;
}

int main() {
    int m, n;
    while (cin >> m >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i)
            cin >> V[i];
        cout << position_maximum(V, m) << endl;
    }
    return 0;
}
