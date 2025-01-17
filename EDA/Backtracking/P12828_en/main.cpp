#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;

bool solve(VI& v, int z, int o, int i) {
    // === BASE CASE
    int n = v.size();
    if (i == n) {
        if (z+o == n) {
            for (int j = 0; j<n-1; j++) cout << v[j] << ' ';
            cout << v[n-1] << endl;
            return true;
        }
        else return false;
    }

    // === GENERAL CASE
    // Cas 1
    v[i] = 0;
    solve(v, z, o+1, i+1);

    // Cas 2
    v[i] = 1;
    solve(v, z+1, o, i+1);
    
    return true;
}

int main() {
    int i, z, o, n;
    i = z = o = 0;
    cin >> n;
    VI v(n, -1);
    solve (v,z,o,i);
}