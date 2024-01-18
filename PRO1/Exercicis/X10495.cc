#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Numero {
    long num;
    int col;
};

typedef vector< vector<int> > iMatrix;
typedef vector< Numero > nVector;

void askMatrix(iMatrix& Matriu, int rows, int cols) {
    for (int row = 0; row<rows; row++) {
        for (int col = 0; col<cols; col++) {
            cin >> Matriu[row][col];
        }
    }
}

void getNumbers(const iMatrix& Matriu, nVector& numeros, int rows, int cols) {
    for (int col = 0; col<cols; col++) {
        long numero, posicio = 0;
        // Paritat
        if (Matriu[rows-1][col]==1) numero = 1;
        else numero = 0;

        // Calcular quin numero es
        for (int row = rows-2; row>=0; row--) {
            long valor = 2;
            posicio++;
            if (Matriu[row][col]==0) continue;  // Si es 0 no fa falta fer res
            for (int i = 1; i<=posicio; i++) valor *= 2;  // 2^i
            numero += valor;
        }

        // Guardar valor
        numeros[col].num = numero; numeros[col].col = col;
    }
}

bool customFilter(Numero& num1, Numero& num2) {
    if (num1.num!=num2.num) return num1.num>num2.num;
    else return num2.num<num1.num;
}

int main() {
    // Demanar Dades
    int usr_rows, usr_cols;
    while (cin >> usr_rows >> usr_cols) {
        iMatrix Matriu(usr_rows,vector<int>(usr_cols));
        askMatrix(Matriu, usr_rows, usr_cols);

        // Analitzar Numeros
        nVector numeros(usr_cols);
        getNumbers(Matriu, numeros, usr_rows, usr_cols);

        // Ordenar numeros gran petit
        sort(numeros.begin(), numeros.end(), customFilter);
        int columna = numeros[1].col;  // El segon més gran

        // Mostrar resultats
        cout << Matriu[0][columna];
        for (int row = 1; row<usr_rows; row++) cout << ' ' << Matriu[row][columna];
        cout << endl;

        // Salt final
        cout << endl;
    }
}