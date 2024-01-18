#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int> > Matriu;

void askMatrix(Matriu& matrix,int rows, int cols) {
    for (int row = 0; row<rows; row++) {
        for (int col = 0; col<cols; col++) {
            cin >> matrix[row][col];
        }
    }
}

int suma_linia(const Matriu& matrix, int ogRow, int ogCol, int destRow, int destCol) {
    int rows = matrix.size()-1;
    int cols = matrix[0].size()-1;
    int resultat = 0;

    if (ogRow>destRow) {  // Endarre
        if (ogRow>0) ogRow--;  // "-1" perque ja he sumat l'actual en el "is_first"
        
        while (ogRow>=destRow) {
            resultat += matrix[ogRow][ogCol];
            if (ogRow>0) ogRow--;
            else break;
        }
        
    } else if (ogRow<destRow) {  // Endavant
        if (ogRow<rows) ogRow++;
        
        while (ogRow<=destRow) {
            resultat += matrix[ogRow][ogCol];
            if (ogRow<rows) ogRow++;
            else break;
        }

    } else if (ogCol>destCol) {  // Esquerra
        if (ogCol>0) ogCol--;
        
        while (ogCol>=destCol) {
            resultat += matrix[ogRow][ogCol];
            if (ogCol>0) ogCol--;
            else break;
        }

    } else if (ogCol<destCol) {  // Dreta
        if(ogCol<cols) ogCol++;
        
        while (ogCol<=destCol) {
            resultat += matrix[ogRow][ogCol];
            if(ogCol<cols) ogCol++;
            else break;
        }
    }

    return resultat;
}

int main() {
    int suma = 0;
    int usr_rows, usr_cols;
    
    // Demanar Dades
    cin >> usr_rows >> usr_cols;
    Matriu matrix(usr_rows,vector<int>(usr_cols));
    askMatrix(matrix, usr_rows, usr_cols);

    // Demanar coordenades
    bool is_first = true;
    int ogRow, ogCol, destRow, destCol;
    while (cin >> destRow >> destCol) {
        if (is_first) {
            is_first = false;
            ogRow = destRow; ogCol = destCol;
            suma = matrix[ogRow][ogCol];
        } else {
            suma += suma_linia(matrix,ogRow,ogCol,destRow,destCol);
            ogRow = destRow; ogCol = destCol;
        }
    }

    // Mostrar resultat
    cout << "suma = " << suma << endl;
}

/*
int suma_linia(const Matriu& matrix, int ogRow, int ogCol, int destRow, int destCol) {
    int rows = matrix.size()-1;
    int cols = matrix[0].size()-1;
    int resultat = 0;

    if (ogRow>destRow) {  // Endarre
        if (ogRow>0) ogRow--;  // "-1" perque ja he sumat l'actual en el "is_first"
        
        while (ogRow>=destRow) {
            resultat += matrix[ogRow][ogCol];
            if (ogRow>0) ogRow--;
            else break;
        }

        if (ogCol>destCol) {  // Esquerra
            if (ogCol>0) ogCol--;

            while (ogCol>=destCol) {
                resultat += matrix[ogRow][ogCol];
                if (ogCol>0) ogCol--;
                else break;
            }
        } else if (ogCol<destCol) {  // Dreta
            if(ogCol<cols) ogCol++;
            
            while (ogCol<=destCol) {
                resultat += matrix[ogRow][ogCol];
                if(ogCol<cols) ogCol++;
                else break;
            }
        }
    } else if (ogRow<destRow) {  // Endavant
        if (ogRow<rows) ogRow++;
        
        while (ogRow<=destRow) {
            resultat += matrix[ogRow][ogCol];
            if (ogRow<rows) ogRow++;
            else break;
        }

        if (ogCol>destCol) {  // Esquerra
            if (ogCol>0) ogCol--;

            while (ogCol>=destCol) {
                resultat += matrix[ogRow][ogCol];
                if (ogCol>0) ogCol--;
                else break;
            }
        } else if(ogCol<destCol) {  // Dreta
            if(ogCol<cols) ogCol++;

            while (ogCol<=destCol) {
                resultat += matrix[ogRow][ogCol];
                if(ogCol<cols) ogCol++;
                else break;
            }
        }
    }

    return resultat;
}
*/