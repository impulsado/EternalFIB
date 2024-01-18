#include<iostream>
#include<vector>
using namespace std;

typedef vector< vector<int> > iMatrix;

void askMatrix(iMatrix& Matriu, int rows, int cols) {
    for (int row = 0; row<rows; row++) {
        for (int col = 0; col<cols; col++) {
            cin >> Matriu[row][col];
        }
    }
}

bool squares(iMatrix& Sudoku) {
    for (int row = 0; row<9; row+=3) {
        for (int col = 0; col<9; col+=3) {
            vector<bool> Numeros(11);
            int c1 = Sudoku[row][col];
            Numeros[c1] = true;
            int c2 = Sudoku[row][col+1];
            Numeros[c2] = true;
            int c3 = Sudoku[row][col+2];
            Numeros[c3] = true;

            int c4 = Sudoku[row+1][col];
            Numeros[c4] = true;
            int c5 = Sudoku[row+1][col+1];
            Numeros[c5] = true;
            int c6 = Sudoku[row+1][col+2];
            Numeros[c6] = true;

            int c7 = Sudoku[row+2][col];
            Numeros[c7] = true;
            int c8 = Sudoku[row+2][col+1];
            Numeros[c8] = true;
            int c9 = Sudoku[row+2][col+2];
            Numeros[c9] = true;

            // Estiguin tots
            for (int i = 1; i<10; i++) if (Numeros[i]==false) return false;  
        }
    }

    return true;
}

bool vertical(iMatrix& Sudoku) {
    for (int row=0; row<9; row++) {
        vector<bool> Numeros(11);
        for (int col=0; col<9; col++) {
            Numeros[Sudoku[row][col]] = true;
        }
        // Estiguin tots
        for (int i = 1; i<10; i++) if (Numeros[i]==false) return false; 
    }

    return true;
}

bool horizontal(iMatrix& Sudoku) {
    for (int row=0; row<9; row++) {
        vector<bool> Numeros(11);
        for (int col=0; col<9; col++) {
            Numeros[Sudoku[col][row]] = true;
        }
        // Estiguin tots
        for (int i = 1; i<10; i++) if (Numeros[i]==false) return false; 
    }

    return true;
}

bool solved(iMatrix& Sudoku) {
    if (not squares(Sudoku)) return false;
    if (not vertical(Sudoku)) return false;
    if (not horizontal(Sudoku)) return false;

    return true;
}

int main() {
    int usr_quant;
    bool solution;
    cin >> usr_quant;

    for (int i = 0; i<usr_quant; i++) {
        iMatrix Sudoku(9,vector<int>(9));
        askMatrix(Sudoku,9,9);
        solution = solved(Sudoku);
        if (solution) cout << "yes" << endl; else cout << "no" << endl;
    }
}