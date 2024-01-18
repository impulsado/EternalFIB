#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > iMatrix;

void askMatrix(iMatrix& Matriu, int rows, int cols) {
    for (int row = 0; row<rows; row++) {
        for (int col = 0; col<cols; col++) {
            cin >> Matriu[row][col];
        }
    }
}

void exploreFields(iMatrix& Matriu, int row, int col, int value) {
    // Cas Base
    if (row<0 or row>=Matriu.size() or col<0 or col>=Matriu[0].size()) return;  // No es passi dels límits
    else if (Matriu[row][col]!=value) return;  // Significa que es un cantonada o ja s'ha vist

    // Marcar com a vist
    Matriu[row][col] = -1;
    
    // Continuar explorant
    exploreFields(Matriu,row+1,col,value);
    exploreFields(Matriu,row-1,col,value);
    exploreFields(Matriu,row,col+1,value);
    exploreFields(Matriu,row,col-1,value);
}

int countFields(iMatrix& Matriu, int rows, int cols) {
    int counter = 0;
    
    for (int row = 0; row<rows; row++) {
        for (int col = 0; col<cols; col++) {
            if (Matriu[row][col]>0) { // No sigui borde '0' ni estigui marcat com a vist '-1'
                exploreFields(Matriu, row, col, Matriu[row][col]);
                counter++;
            }
        }
    }

    return counter;
}

int main() {
    int usr_rows, usr_cols, fields;

    while (cin >> usr_rows >> usr_cols) {
        // Demanar datos del camp
        iMatrix field(usr_rows,vector<int>(usr_cols));
        askMatrix(field, usr_rows, usr_cols);

        // Comptar quantitat de camps
        fields = countFields(field, usr_rows, usr_cols);

        // Mostrar quantiatat
        cout << fields << endl;
    }
}

/*
// Retorna quin tipus de coordenada es i la guarda en la posicio de coordenades corresponent
int checkCorner(iMatrix& Matriu, int row, int col, vector<coordenada>& coordenades) {

    // Superior Esquerra --> 0
    // Superior Dreta --> 1
    // Inferior Esquerra --> 2
    // Inferior Dreta --> 3
    // Altres --> -1

    if (Matriu[row][col-1]==0 and Matriu[row-1][col-1]==0 and Matriu[row-1][col]==0) {  // Superior Esquerra
        coordenades[0].x = row; coordenades[0].y = col;
        return 0;
    } else if (Matriu[row-1][col]==0 and Matriu[row-1][col+1]==0 and Matriu[row][col+1]==0) {  // Superior Dreta
        coordenades[1].x = row; coordenades[1].y = col;
        return 1;
    } else if (Matriu[row][col-1]==0 and Matriu[row+1][col-1]==0 and Matriu[row+1][col+1]==0) {  // Inferior Esquerra
        coordenades[2].x = row; coordenades[2].y = col;
        return 2;
    } else if (Matriu[row+1][col]==0 and Matriu[row+1][col+1]==0 and Matriu[row][col+1]==0) {  // Inferior Dreta
        coordenades[3].x = row; coordenades[3].y = col;
        return 3;
    } else {  // No es cap cantonada
        return -1;
    }
}
*/
    

    
