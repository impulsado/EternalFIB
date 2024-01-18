#include<iostream>
#include<vector>
using namespace std;

typedef vector< vector<char> > cMatrix;

void recursiu(cMatrix& Matriu, int num) {
    int rows = Matriu.size()-1;
    int cols = Matriu[0].size()-1;

    if (num!=0) {
        for (int row = 0; row<=rows; row++) {
            for (int col = 0; col<=cols; col++) {
                // Superior Inferior
                if (row == 0 or row==rows) {
                    if (col==0 or col==cols/2 or col==cols) Matriu[row][col] = '|';
                }
                
                // Laterals
                if (col==0 or col==cols) Matriu[row][col] = '|';

                // Central
                if (row==rows/2) {
                    if (col==(cols/2)-1 or col==(cols/2)+1) Matriu[row][col] = '-';
                    if (col==cols/2) Matriu[row][col] = 'o'
                }
            }
        }
    }
}

void principal(cMatrix& Matriu, int num) {
    int rows = Matriu.size()-1;
    int cols = Matriu[0].size()-1;
    recursiu(num-1);
    /*
    Codi Part central
    */
    recursiu(num-1);
}

int main() {
    int usr_num, rows = 3, cols;
    cin >> usr_num;

    // Calcular files i columnes ! IMPORTANT NO FICAR "<="
    for (int i = 1; i<usr_num; i++) rows*=3;
    cols = rows+2;

    cMatrix Matriu(rows,vector<char>(cols,' '));
    principal(Matriu, usr_num);
    
}