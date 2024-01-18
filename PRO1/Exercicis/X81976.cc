#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > iMatrix;

void askMatrix(iMatrix& Matriu, int rows, int cols) {
    char usr_char;
    for (int row = 0; row<rows; row++) {
        for (int col = 0; col<cols; col++) {
            cin >> usr_char;
            Matriu[row][col] = usr_char-'0';
        }
    }
}

void countOcurrences(const iMatrix& Matriu, iMatrix& FreqRows, iMatrix& FreqCols, int rows, int cols) {
    for (int row = 0; row<rows; row++) {
        for (int col = 0; col<cols; col++) {
            int num = Matriu[row][col];
            FreqRows[row][num]++;
            FreqCols[col][num]++;
        }
    }
}

void showMatrix(const iMatrix& Matriu, const iMatrix& FreqRows, const iMatrix& FreqCols, int rows, int cols) {
    int resultat;
    for (int row = 0; row<rows; row++) {
        for (int col = 0; col<cols; col++) {
            int num = Matriu[row][col];
            resultat = FreqRows[row][num]+FreqCols[col][num];
            cout << resultat%10;
        }
        cout << endl;
    }
}

int main() {
    int usr_rows, usr_cols;
    while (cin >> usr_rows >> usr_cols) {
        iMatrix Matriu(usr_rows,vector<int>(usr_cols));
        askMatrix(Matriu, usr_rows, usr_cols);
        
        // Guardar Frequencia del numero en la seva fila o columna. Fent ús del index
        iMatrix FreqRows(usr_rows,vector<int>(10,0));
        iMatrix FreqCols(usr_cols,vector<int>(10,0));
        countOcurrences(Matriu, FreqRows, FreqCols, usr_rows, usr_cols);

        showMatrix(Matriu, FreqRows, FreqCols, usr_rows, usr_cols);
        cout << endl;
    }
}