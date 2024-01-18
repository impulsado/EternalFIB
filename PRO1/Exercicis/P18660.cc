#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Matrix; 

// Demanar valors de la matriu
void askMatrix(Matrix& matriu, int rows, int columns) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            cin >> matriu[row][col];
        }
    }
}

// Mostrar matriu
void printMatrix(Matrix& matriu, int rows, int columns) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            if (col==columns-2) cout << matriu[row][col];
            else cout << matriu[row][col] << " ";

        }
        cout << endl;
    }
}

// Buscar paraules en sentit DIAGONAL en una matriu
void searchDiagonal(Matrix& uMatriu, Matrix& tmpMatriu, int rows, int columns, vector<string> vWords) {
    string paraula;
    bool esta;
    char lletra;
    int tmp_col, col = 0;
    int tmp_row, row = 0;
    
    while (row<rows) {
        col = 0;  // Reset de cada columna 
        while (col<columns) {
            for (int pos1 = 0; pos1<vWords.size(); pos1++) {
                esta = true;
                paraula = vWords[pos1];
                tmp_row = row;
                tmp_col = col;
                for (int pos2 = 0; pos2<paraula.size(); pos2++) {
                    lletra = paraula[pos2];
                    if (tmp_row>=rows or tmp_col>=columns) {esta = false; break;}  // Que no es pasi de límit
                    if (lletra == uMatriu[tmp_row][tmp_col] or lletra == uMatriu[tmp_row][tmp_col]+32) {
                        if (tmpMatriu[tmp_row][tmp_col]>=97) tmpMatriu[tmp_row][tmp_col] = tmpMatriu[tmp_row][tmp_col]-32;  // Fer majuscula
                        tmp_row++;
                        tmp_col++;
                    
                    } else {  // Si no coincideix lletra
                        esta = false; break;
                    }
                }
                if (esta) uMatriu = tmpMatriu;  // Copiar la matriu temporal
                else tmpMatriu = uMatriu;
            }

            col++;
        }
        row++;
    }
}

// Buscar paraules en sentit VERTICAL en una matriu
void searchVertical(Matrix& uMatriu, Matrix& tmpMatriu, int rows, int columns, vector<string> vWords) {
    string paraula;
    bool esta;
    char lletra;
    int tmp_row, row = 0;


    while (row<rows) {
       for (int col = 0; col<columns; col++) {
            for (int pos1 = 0; pos1<vWords.size(); pos1++) {
                esta = true;
                paraula = vWords[pos1];
                tmp_row = row;
                for (int pos2 = 0; pos2<paraula.size(); pos2++) {
                    lletra = paraula[pos2];
                    if (tmp_row>=rows) {esta = false; break;}  // Que no es pasi de límit
                    if (lletra == uMatriu[tmp_row][col] or lletra == uMatriu[tmp_row][col]+32) {
                        if (tmpMatriu[tmp_row][col]>=97) tmpMatriu[tmp_row][col] = tmpMatriu[tmp_row][col]-32;
                        tmp_row++;
                    } else {
                        esta = false; break;
                    }
                }
                if (esta) uMatriu = tmpMatriu;  // Copiar la matriu temporal
                else tmpMatriu = uMatriu;
            }
        
        }
    
        row++;
    }
}

// Buscar paraules en sentit HORITZONTAL en una matriu
void searchHorizontal(Matrix& uMatriu, Matrix& tmpMatriu, int rows, int columns, vector<string> vWords) {
    string paraula;
    bool esta;
    char lletra;
    int tmp_col, col;

    for (int row = 0; row<rows; row++) {
        tmp_col = col = 0; // Reset
        while (col<columns) {
            for (int pos1 = 0; pos1<vWords.size(); pos1++) {
                esta = true;
                paraula = vWords[pos1];
                tmp_col = col;
                for (int pos2 = 0; pos2<paraula.size(); pos2++) {
                    lletra = paraula[pos2];
                    if (tmp_col>=columns) {esta = false; break;}  // Que no es pasi de límit
                    if (lletra == uMatriu[row][tmp_col] or lletra == uMatriu[row][tmp_col]+32) {
                        if (tmpMatriu[row][tmp_col]>=97) tmpMatriu[row][tmp_col] = tmpMatriu[row][tmp_col]-32;  
                        tmp_col++;
                    } else {
                        esta = false; break;
                    }
                }
                if (esta) uMatriu = tmpMatriu;  // Copiar la matriu temporal
                else tmpMatriu = uMatriu;
            }

            col++;
        }
    }
}

int main () {
    int usr_words, rows, columns;

    while (cin >> usr_words >> rows >> columns) {
        // Demanar Paraules
        vector<string> uWords(usr_words);
        for (int i = 0; i<usr_words; i++) cin >> uWords[i];

        // Demanar Matriu
        Matrix uMatrix(rows,vector<char>(columns));
        askMatrix(uMatrix,rows,columns);

        // Crear matriu temporal
        Matrix tmpMatrix(rows,vector<char>(columns));
        tmpMatrix = uMatrix;

        // Buscar Paraules
        searchHorizontal(uMatrix,tmpMatrix,rows,columns,uWords);
        searchVertical(uMatrix,tmpMatrix,rows,columns,uWords);
        searchDiagonal(uMatrix,tmpMatrix,rows,columns,uWords);

        // Mostrar Resultat
        printMatrix(uMatrix,rows,columns);
        cout << endl;
    }
}