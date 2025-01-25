#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef vector<int> VI;

void solve(VI& vseen, VI& vsol, int index, const int& n) {
    // === BASE CASE ===
    if (index == n) {
        cout << '(';
        for (int i = 0; i<n-1; i++) cout << vsol[i] << ',';
        cout << vsol[n-1] << ')' << endl;
        return;
    }
    
    // === GENERAL CASE ===
    // REESTRICCIÓ 1: ..., x,y,z ,... on x-2y<=z
    if (1<index && index<n) {  // Estic en "z" i puc accedir a x,y
        int x = vsol[index-2];
        int y = vsol[index-1];
        int num_max_z = 2*y-x;  // z <= 2y-x
        if (num_max_z<1) return;  // Significa que no es pot
        if (num_max_z>n) num_max_z = n;

        for (int num = 1; num<=num_max_z; num++) {
            if (vseen[num]) continue;
            vsol[index] = num;
            vseen[num] = 1;
            solve(vseen, vsol, index+1, n);
            vseen[num] = 0;
        }
    }
    else {
        for (int num = 1; num<=n; num++) {
            if (vseen[num]) continue;
            vsol[index] = num;
            vseen[num] = 1;
            solve(vseen, vsol, index+1, n);
            vseen[num] = 0;
        }
    }
}

int main(void) {
    int n;
    cin >> n;

    int index = 0;
    VI vseen(n+1, 0);
    VI vsol(n);

    solve(vseen, vsol, index, n);
}
