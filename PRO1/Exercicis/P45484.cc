#include <iostream>
#include <vector>
using namespace std;

void calcFiles(const vector<vector<int>>& M, vector<int>& resultatsFiles) {
    int rows = M.size(), cols = M[0].size();
    int suma = 0;
    for (int row = 0; row<rows; row++) {
        for (int col = 0; col<cols; col++) {
            suma += M[row][col];
        }
        resultatsFiles.push_back(suma);
        suma = 0;  // Reset
    }
}

void calcColumnes(const vector<vector<int>>& M, vector<int>& resultatsColumnes) {
    int rows = M.size(), cols = M[0].size();
    int suma = 0;
    for (int col = 0; col<cols; col++) {
        for (int row = 0; row<rows; row++) {
            suma += M[row][col];
        }
        resultatsColumnes.push_back(suma);
        suma = 0;  // Reset
    }
}

void calcDiagonals(const vector<vector<int>>& M, vector<int>& resultatsDiagonals) {
    int rows = M.size(), cols = M[0].size();
    int suma = 0;

    // Diagonal Principal
    for (int row = 0; row<rows; row++) {
        suma += M[row][row];
    }
    resultatsDiagonals.push_back(suma);
    suma = 0;  // Reset

    // Diagonal Secundaria
    int col = cols-1;
    for (int row = 0; row<rows; row++) {
        suma += M[row][col];
        col--;
    }
    resultatsDiagonals.push_back(suma);
}

bool magic_square(const vector<vector<int>>& M) {
    vector<int> resultatsFiles;
    vector<int> resultatsColumnes;
    vector<int> resultatsDiagonals;

    calcFiles(M, resultatsFiles);
    calcColumnes(M, resultatsColumnes);
    calcDiagonals(M, resultatsDiagonals);

    int valor = resultatsFiles[0];  // Agafo un valor qualsevol amb el que aniré comparant
    for (int i = 0; i<resultatsFiles.size(); i++) if (resultatsFiles[i]!=valor) return false;
    for (int i = 0; i<resultatsColumnes.size(); i++) if (resultatsColumnes[i]!=valor) return false;
    for (int i = 0; i<resultatsDiagonals.size(); i++) if (resultatsDiagonals[i]!=valor) return false;

    return true; 
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
        cout << magic_square(M) << endl;
    }
    return 0;
}
