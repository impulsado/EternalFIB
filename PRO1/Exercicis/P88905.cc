#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matriu;

Matriu producte(const Matriu& A, const Matriu& B) {
    int p = A.size();
    int q = A[0].size();
    int r = B[0].size(); 
    Matriu C(p, vector<int>(r));  // Crear matriu resultat

    for (int row = 0; row<p; row++) {
        for (int col = 0; col<r; col++) {
            for (int j = 0; j<q; j++) {
                C[row][col] = C[row][col] + (A[row][j]*B[j][col]);
            }
        }
    }

    return C;
}

int main()
{
    int p, q, r;
    while (cin >> p >> q >> r) {
        Matriu A(p, vector<int>(q));
        Matriu B(q, vector<int>(r));
        for (int i = 0; i < p; ++i) {
            for (int j = 0; j < q; ++j) {
                cin >> A[i][j];
            }
        }
        for (int i = 0; i < q; ++i) {
            for (int j = 0; j < r; ++j) {
                cin >> B[i][j];
            }
        }
        Matriu C = producte(A, B);
        for (int i = 0; i < p; ++i) {
            for (int j = 0; j < r; ++j) {
                cout << C[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
