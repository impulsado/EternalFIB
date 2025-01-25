#include <vector>
#include <iostream>
using namespace std;

#define n 9

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;

bool check_num_ok(const VVI& sudoku, const VVI& files, const VVI& columnes, const VVI& grups, const int& i, const int& j, const int& num) {
    if (files[i][num]) return false;
    else if (columnes[j][num]) return false;
    else if (grups[(i/3)+3*(j/3)][num]) return false;

    return true;
}

PII find_next_valid_pos(const VVI& sudoku, const int& i, const int& j) {
    for (int row = i; row<n; row++) {
        for (int col = 0; col<n; col++) {
            if (row == i && col<=j) continue;
            if (sudoku[row][col] == 0) return PII(row, col);
        }
    }

    // Aixo només passa si ja hem completat el sudoku
    return PII(-1,-1);
}

void solve(VVI& sudoku, VVI& files, VVI& columnes, VVI& grups, int i, int j, bool& solved) {
    // === BASE CASE
    // 1. Si arribo al final, aquesta es la solucio
    if (i == -1 && j == -1) {solved = true; return;}
    // 2. Si ja he trobat una solució, no continuar
    else if (solved) return;
    // 3. El actual pot ser un numero predefinit
    else if (sudoku[i][j] != 0) {
        PII next_valid_pos = find_next_valid_pos(sudoku, i, j);
        solve(sudoku, files, columnes, grups, next_valid_pos.first, next_valid_pos.second, solved);
        return;
    }

    // === GENERAL CASE
    /*
    1. Comprovar tots els valor 0-9
    2. El que passi tots el OK, ficarlo
    3. Vull saber la seguent posicio a ficar-ho:
    - No hi hagi un previ
    - Que si hem acabat la fila, anem a la següent
    */
    for (int num = 1; num<=n && !solved; num++) {
        if (!check_num_ok(sudoku, files, columnes, grups, i, j, num)) continue;
        sudoku[i][j] = num;
        files[i][num] = 1;
        columnes[j][num] = 1;
        grups[(i/3)+3*(j/3)][num] = 1;
        PII next_valid_pos = find_next_valid_pos(sudoku, i, j);
        solve(sudoku, files, columnes, grups, next_valid_pos.first, next_valid_pos.second, solved);
        if (!solved) {
            sudoku[i][j] = 0;
            files[i][num] = 0;
            columnes[j][num] = 0;
            grups[(i/3)+3*(j/3)][num] = 0;
        }
    }

}

int main(void) {
    int usr_quant_sudokus;
    cin >> usr_quant_sudokus;
    cout << usr_quant_sudokus << endl;

    for (int id_sudoku = 0; id_sudoku<usr_quant_sudokus; id_sudoku++) {
        cout << endl;

        // === DEMANAR DADES
        VVI sudoku(n, VI(n));
        VVI columnes(n, VI(n+1,0));
        VVI files(n, VI(n+1,0));
        VVI grups(n, VI(n+1,0));  

        char usr_char;
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                cin >> usr_char;
                if (usr_char != '.') {
                    int num =  usr_char-'0';
                    sudoku[i][j] =  num;  // convertir a numero
                    files[i][num] = 1;
                    columnes[j][num] = 1;
                    grups[(i/3)+3*(j/3)][num] = 1;
                }
                else sudoku[i][j] = 0;
            }
        }

        // === RESOLDRE
        int i, j;
        bool solved = false;

        i = j = 0;
        solve(sudoku, files, columnes, grups, i, j, solved);

        // === MOSTRAR RESULTAT
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n-1; j++) cout << sudoku[i][j] << " ";
            cout << sudoku[i][n-1] << endl;
        }
    }
}