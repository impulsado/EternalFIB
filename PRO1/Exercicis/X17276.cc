#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector< vector<int> > iMatrix;

void askMatrix(iMatrix& Matriu, int rows, int cols) {
    for (int row = 0; row<rows; row++) {
        for (int col = 0; col<cols; col++) {
            cin >> Matriu[row][col];
        }
    }
}

bool topLeftDiagonal(iMatrix& Matriu, int rowOG, int colOG){
    int row = rowOG-1;
    int col = colOG-1;

    while (row>=0 and col>=0) {
        if (Matriu[row][col]<=Matriu[rowOG][colOG]) return false;
        rowOG = row; colOG = col;
        row--; col--;
    }

    return true;
}

bool topRightDiagonal(iMatrix& Matriu, int rowOG, int colOG) {
    int row = rowOG-1;
    int col = colOG+1;
    int cols = Matriu[0].size();

    while (row>=0 and col<cols) {
        if (Matriu[row][col]<=Matriu[rowOG][colOG]) return false;
        rowOG = row; colOG = col;
        row--; col++;
    }

    return true;
}

bool bottomLeftDiagonal(iMatrix& Matriu, int rowOG, int colOG) {
    int row = rowOG+1;
    int col = colOG-1;
    int rows = Matriu.size();

    while (row<rows and col>=0) {
        if (Matriu[row][col]<=Matriu[rowOG][colOG]) return false;
        rowOG = row; colOG = col;
        row++; col--;
    }

    return true;
}

bool bottomRightDiagonal(iMatrix& Matriu, int rowOG, int colOG) {
    int row = rowOG+1;
    int col = colOG+1;
    int rows = Matriu.size();
    int cols = Matriu[0].size();

    while (row<rows and col<cols) {
        if (Matriu[row][col]<=Matriu[rowOG][colOG]) return false;
        rowOG = row; colOG = col;
        row++; col++;
    }

    return true;
}

string searchDiagonals(iMatrix& Matriu, int rowOG, int colOG) {
    int rows = Matriu.size();
    int cols = Matriu[0].size();

    if (rowOG==0 and colOG==0) {  // Cantonada Superior Esquerra
        bool bottomRight = bottomRightDiagonal(Matriu, rowOG, colOG);
        if (not bottomRight) return "no";
        else return "si";
    } else if (rowOG==0 and colOG==cols-1) {  // Cantonada Superior Dreta
        bool bottomLeft = bottomLeftDiagonal(Matriu, rowOG, colOG);
        if (not bottomLeft) return "no";
        else return "si";
    } else if (rowOG==rows-1 and colOG==0) {  // Cantonada Inferior Esquerra
        bool topRight = topRightDiagonal(Matriu, rowOG, colOG);
        if (not topRight) return "no";
        else return "si";
    } else if (rowOG==rows-1 and colOG==cols-1) {  // Cantonada Inferior Dreta
        bool topLeft = topLeftDiagonal(Matriu, rowOG, colOG);
        if (not topLeft) return "no";
        else return "si";
    } else {  // No està en cap cantonada
        bool topLeft = topLeftDiagonal(Matriu, rowOG, colOG);
        if (not topLeft) return "no";

        bool topRight = topRightDiagonal(Matriu, rowOG, colOG);
        if (not topRight) return "no";

        bool bottomLeft = bottomLeftDiagonal(Matriu, rowOG, colOG);
        if (not bottomLeft) return "no";

        bool bottomRight = bottomRightDiagonal(Matriu, rowOG, colOG);
        if (not bottomRight) return "no";

        return "si";
    }
}

int main() {
    string resultat;
    int usr_rows, usr_cols;
    int rowOG, colOG;

    while (cin >> usr_rows >> usr_cols) {
        iMatrix Matriu(usr_rows,vector<int>(usr_cols));
        askMatrix(Matriu, usr_rows, usr_cols);
        cin >> rowOG >> colOG;
        resultat = searchDiagonals(Matriu, rowOG, colOG);
        cout << resultat << endl;
    }
}