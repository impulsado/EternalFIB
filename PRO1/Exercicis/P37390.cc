#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matriu;

Matriu producte(const Matriu& A, const Matriu& B) {
    // ! Enunciat diu que son quadrades.
    int rows = A.size();
    Matriu C(rows, vector<int>(rows));  // Crear matriu resultat

    for (int row = 0; row<rows; row++) {
        for (int col = 0; col<rows; col++) {
            for (int j = 0; j<rows; j++) {
                C[row][col] = C[row][col] + (A[row][j]*B[j][col]);
            }
        }
    }

    return C;
}

int main()
{
    int n;
    while (cin >> n) {
        Matriu A(n, vector<int>(n));
        Matriu B(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> A[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> B[i][j];
            }
        }
        Matriu C = producte(A, B);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << C[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
