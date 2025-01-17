#include <iostream>
#include <vector>
using namespace std;

bool pos_ok(const vector<bool>& vcols, const vector<vector<bool>>& vdiag, const int& i, const int& j) {
    // 1. Columa
    if (vcols[j]) return false;
    
    // 2. Diag_Up (i+j)
    int d = i+j;
    if (vdiag[0][d]) return false;

    // 3. Diag_Down (i-j)+3
    d = i-j+3;
    if (vdiag[1][d]) return false;

    return true;
}

void solve(vector<int>& vpos, int i, int& counter, vector<bool>& vcols, vector<vector<bool>>& vdiag) {
    int n = vpos.size();

    // === BASE CASE
    // 1. Es una opció correcta
    if (i == n) {
        for (int row = 0; row<n; row++) {
            for (int col = 0; col<n; col++) {
                if (col == vpos[row]) cout << 'Q';
                else cout << '.';
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    
    // === GENERAL CASE
    for (int j = 0; j<n; j++) {
        vpos[i] = j;
        if (pos_ok(vcols,vdiag,i,j)) {
            vcols[j] = true;
            vdiag[0][i+j] = true;
            vdiag[1][i-j+3] = true;
            solve(vpos, i+1, counter, vcols, vdiag);
            vcols[j] = false;
            vdiag[0][i+j] = false;
            vdiag[1][i-j+3] = false;
        }

    }
    return;
}

void nQueens(vector<int>& vpos) {
    int counter = 0;
    int i = 0;
    int n = vpos.size();
    vector<bool> vcols(n, false);  // Guardar columnes ocupades
    vector<vector<bool>> vdiag(2,vector<bool> ((2*n)-1, false));
    // vdiag[0] = Guardar columnes i+j
    // vdiag[1] = Guardar columnes i-j
    solve(vpos, i, counter, vcols, vdiag);
}

int main() {
    int n;
    cin >> n;
    vector<int> vpos(n);
    nQueens(vpos);
}