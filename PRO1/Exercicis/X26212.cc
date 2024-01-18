#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<char> > Matrix;

// Demanar valors de la matriu
void askMatrix(Matrix& matriu, int rows, int columns) {
    for (int row = 0; row<rows; row++) {
        for (int col = 0; col<columns; col++) {
            cin >> matriu[row][col];
        }
    }
}

int searchHorizontal(Matrix& matriu, int rows, int columns) {
    int counter = 0;

    for (int row = 0; row<rows; row++) {
        for (int col = 0; col<columns-2; col++) {
            if (matriu[row][col]==':' and matriu[row][col+1]=='-' and matriu[row][col+2]==')') counter++;
            else if (matriu[row][col]=='(' and matriu[row][col+1]=='-' and matriu[row][col+2]==':') counter++;
        }
    }

    return counter;
}

int searchVertical(Matrix& matriu, int rows, int columns) {
    int counter = 0;

    for (int row = 0; row<rows-2; row++) {
        for (int col = 0; col<columns; col++) {
            if (matriu[row][col]=='"' and matriu[row+1][col]=='|' and matriu[row+2][col]=='v') counter++;
            else if (matriu[row][col]=='^' and matriu[row+1][col]=='|' and matriu[row+2][col]=='"') counter++;
        }
    }

    return counter;
}

int main () {
    int usr_rows, usr_cols;

    while (cin >> usr_rows >> usr_cols) {
        int counter = 0;

        // Demanar matriu
        Matrix matriu(usr_rows, vector<char>(usr_cols));
        askMatrix(matriu,usr_rows,usr_cols);

        // Buscar cares
        counter = searchHorizontal(matriu,usr_rows,usr_cols);
        counter = counter + searchVertical(matriu,usr_rows,usr_cols);
    
        // Mostrar resultat
        cout << counter << endl;
    }
}