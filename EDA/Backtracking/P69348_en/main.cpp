#include <vector>
#include <iostream>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;

void solve(VI v, int i, VB& seen) {
    int n = v.size();

    // === BASE CASE
    if (i == n) {
        cout << '(';
        for (int j = 0; j<n-1; j++) cout << v[j] << ',';
        cout << v[n-1] << ')' << endl;
        return;
    }

    // === GENERAL CASE
    for (int num = 1; num<=n; num++) {
        if (seen[num]) continue;

        v[i] = num;
        seen[num] = true;
        solve(v, i+1, seen);
        seen[num] = false;
    }
    return;
}

int main() {
    int n, i = 0;
    cin >> n;
    VI v(n);
    VB seen(n+1, false);
    solve(v,i,seen);
}