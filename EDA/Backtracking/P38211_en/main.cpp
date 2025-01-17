#include <iostream>
#include <vector>
using namespace std;

bool printed = false;

bool pos_ok(const vector<int>& vcols, const vector<vector<int>>& vdiag, const int& i, const int& j) {
    int n = vcols.size();

    // 1. Columa
    if (vcols[j]) return false;
    
    // 2. Diag_Up (i+j)
    int d = i+j;
    if (vdiag[0][d]) return false;

    // 3. Diag_Down (i-j)+n
    d = i-j+n;
    if (vdiag[1][d]) return false;

    return true;
}

void solve(vector<int>& vpos, int i, vector<int>& vcols, vector<vector<int>>& vdiag) {
    int n = vpos.size();

    // === BASE CASE
    // 0. Ja ha sigut printat
    if (printed) return;
    
    // 1. Es una opciÃ³ correcta
    if (i == n) {
        printed = true;
        
        for (int row = 0; row<n; row++) {
            for (int col = 0; col<n; col++) {
                if (col == vpos[row]) cout << 'Q';
                else cout << '.';
            }
            cout << endl;
        }
        return;
    }
    
    // === GENERAL CASE
    for (int j = 0; j<n && !printed; j++) {
        vpos[i] = j;
        if (pos_ok(vcols,vdiag,i,j)) {
            vcols[j] = 1;
            vdiag[0][i+j] = 1;
            vdiag[1][i-j+n] = 1;
            solve(vpos, i+1, vcols, vdiag);
            vcols[j] = 0;
            vdiag[0][i+j] = 0;
            vdiag[1][i-j+n] = 0;
        }

    }
    return;
}

void nQueens(vector<int>& vpos) {
    int i = 0;
    int n = vpos.size();
    vector<int> vcols(n, 0);  // Guardar columnes ocupades
    vector<vector<int>> vdiag(2,vector<int> ((2*n)-1, 0));
    // vdiag[0] = Guardar columnes i+j
    // vdiag[1] = Guardar columnes i-j
    solve(vpos, i, vcols, vdiag);
}

int main() {
    int n;
    cin >> n;
    vector<int> vpos(n);
    nQueens(vpos);
    if (!printed) cout << "NO SOLUTION" << endl;
}