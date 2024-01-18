#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > Matriu;

void readMatrix(Matriu& mat, int rows, int cols) {
    for (int row = 0; row<rows; row++) {
        for (int col = 0; col<cols; col++) {
            cin >> mat[row][col];
        }
    }
}

void min_max(const Matriu& mat, int& minim, int& maxim) {
    int rows = mat.size();
    int cols = mat[0].size();
    minim = maxim = mat[0][0];

    for (int row = 0; row<rows; row++) {
        for (int col = 0; col<cols; col++) {
            if (maxim < mat[row][col]) maxim = mat[row][col];
            if (minim > mat[row][col]) minim = mat[row][col];
        }
    }
}

int main() {
    int usr_rows, usr_cols;
    int minim, maxim;
    vector<int> diferencies;

    while (cin >> usr_rows >> usr_cols) {
        // Demanar matriu
        Matriu mat(usr_rows,vector<int>(usr_cols));
        readMatrix(mat, usr_rows, usr_cols);
        
        // Calcular i guardar
        min_max(mat, minim, maxim);
        int resultat = maxim-minim;
        diferencies.push_back(resultat);
    }

    // Obtindre la màxima diferencia guardada
    int last_pos = 0;
    int max_diference = diferencies[0];
    for (int i = 0; i<diferencies.size(); i++) {
        if (max_diference < diferencies[i]) {
            last_pos = i; max_diference = diferencies[i];
        }
    }

    // Mostrar
    cout << "la diferencia maxima es " << max_diference << endl;
    cout << "la primera matriu amb aquesta diferencia es la " << last_pos+1 << endl;
}