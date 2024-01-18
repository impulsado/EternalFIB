#include<iostream>
#include<vector>
using namespace std;

typedef vector< vector<char> > cMatrix;

void askMatrix(cMatrix& Matriu, int rows,int cols) {
    for (int row = 0; row<rows; row++) {
        for (int col = 0; col<cols; col++) {
            cin >> Matriu[row][col];
        }
    }
}

int countNeighbors(const cMatrix& Matriu, int row, int col) {
    int counter = 0;
    int rows = Matriu.size();
    int cols = Matriu[0].size();

    for (int i=-1; i<=1; i++) {
        for (int j=-1; j<=1; j++) {
            if (i==0 and j==0) continue;  // És la mateixa
            int newRow = row+i;
            int newCol = col+j;

            if ((0<=newRow and newRow<rows) and (0<=newCol and newCol<cols)) {
                if (Matriu[newRow][newCol]=='B') counter++;
            }
        }
    }

    return counter;
}

void printNextT(cMatrix& Matriu) {
    int rows = Matriu.size();
    int cols = Matriu[0].size();
    cMatrix NovaMatriu = Matriu;
    int veins;

    // Mirar numero al voltant
    for (int row = 0; row<rows; row++) {
        for (int col = 0; col<cols; col++) {
            veins = countNeighbors(Matriu,row,col);

            if (Matriu[row][col]=='.' and veins==3) NovaMatriu[row][col]='B';  // Viu
            else if (Matriu[row][col]=='B' and (veins!=2 and veins!=3)) NovaMatriu[row][col]='.';  // Mort
        }
    }

    // Mostrar resultat
    for (int row = 0; row<rows; row++) {
        for (int col = 0; col<cols; col++) {
            Matriu[row][col]=NovaMatriu[row][col];
            cout << Matriu[row][col];
        }
        cout << endl;  // Salt linia
    }
}

int main() {
    bool is_first = true;
    int usr_rows, usr_cols;

    while (cin >> usr_rows >> usr_cols and usr_rows!=0 and usr_cols!=0) {
        cMatrix Matriu(usr_rows,vector<char>(usr_cols));
        askMatrix(Matriu,usr_rows,usr_cols);
        if (is_first) {is_first = false; continue;} else cout << endl; // Salt Final
        printNextT(Matriu);
    }
}