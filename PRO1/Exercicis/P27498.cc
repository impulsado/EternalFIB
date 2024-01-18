#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> Matriu;

void swap(int& a, int& b) {
    int c;
    c = a;
    a = b;
    b = c;
}

void transposa(Matriu& M) {
    int rows = M.size();
    int columns = M.size();

    for (int row = 0; row<rows-1; row++) {
        for (int col = row+1; col<columns; col++) {
            swap(M[row][col],M[col][row]);
        }
    }
}

int main() {
    int n;
    while (cin >> n) {
        vector<vector<int>> M(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> M[i][j];
            }
        }
        transposa(M);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << M[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
