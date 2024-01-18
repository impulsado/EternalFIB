#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > iMatrix;

void askMatrix(iMatrix& Matriu, int rows, int cols) {
    char usr_char;
    for (int row = 0; row<rows; row++) {
        for (int col = 0; col<cols; col++) {
            cin >> usr_char;
            Matriu[row][col] = usr_char-48;
        }
    }
}

bool checkSubmatrix(iMatrix Matriu, int row, int col, int value, int limit) {
    int rows = row+limit;
    int cols = col+limit;

    for (int i = row; i<rows; i++) {
        for (int j = col; j<cols; j++) {
            if (Matriu[i][j]!=value) return false;
        }
    }

    return true;
}

void searchSubmatrixs(iMatrix Matriu,int rows,int cols,int& counter) {
    int maxim;
    if (rows<cols) maxim = rows; else maxim = cols;

    for (int lim = maxim; lim>1; lim--) {  // El 1 el fare multiplicant
        for (int row = 0; row<rows; row++) {
            if (lim+row>rows) break;
            for (int col = 0; col<cols; col++) {
                if (lim+col>cols) break;
                if (checkSubmatrix(Matriu,row,col,Matriu[row][col],lim)) counter++;
            }
        }
    }
    counter = counter + (rows*cols);
}

int main() {
    int usr_rows, usr_cols;
    while (cin >> usr_rows >> usr_cols) {
        int counter = 0;
        iMatrix Matriu(usr_rows,vector<int>(usr_cols));
        askMatrix(Matriu,usr_rows,usr_cols);
        searchSubmatrixs(Matriu,usr_rows,usr_cols,counter);
        cout << counter << endl;
    }
}