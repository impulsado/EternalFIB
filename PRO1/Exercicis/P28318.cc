#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> Matrix;

void createMatrix(Matrix& matrix, int rows, int columns) {
    for (int i = 0; i<rows; i++) {
        for (int j = 0; j<columns; j++) {
            cin >> matrix[i][j];
        }
    }
}

int main () {
    int usr_fil, usr_col;
    cin >> usr_fil >> usr_col;
    Matrix uMatrix(usr_fil,vector<int>(usr_col));
    createMatrix(uMatrix, usr_fil, usr_col);

    int e1,e2;
    string usr_op;
    while (cin >> usr_op) {
        if (usr_op=="fila") {
            cin >> e1;
            cout << usr_op << " " << e1 << ":";
            e1--;
            for (int j = 0; j<usr_col; j++) cout << " " << uMatrix[e1][j];
            cout << endl;
        } else if (usr_op=="columna") {
            cin >> e1;
            cout << usr_op << " " << e1 << ":";
            e1--;
            for (int i = 0; i<usr_fil; i++) cout << " " << uMatrix[i][e1];
            cout << endl;
        } else if (usr_op=="element") {
            cin >> e1 >> e2;
            cout << usr_op << " " << e1 << " " << e2 << ":";
            e1--; e2--;
            cout << " " << uMatrix[e1][e2];
            cout << endl;
        }
    }
}