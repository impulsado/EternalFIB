#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<char> > cMatrix;

int calcular_mida(int num) {
    int base = 2, mida = 1;
    for (int i = 0; i<num; i++) mida *= base;
    mida = mida-1;
    return mida;
}

void recursivitat(cMatrix& Matriu, int usr_num) {
    // Cas Base
    if (usr_num==1) {Matriu[0][0] = '#'; return;}

    // Guardar el patrò anterior
    int mida_del_anterior = calcular_mida(usr_num-1);
    cMatrix Anterior(mida_del_anterior, vector<char>(mida_del_anterior));
    recursivitat(Anterior, usr_num-1);

    // Ficar el patrò anterior a Matriu
    int size = Matriu.size();
    for (int row = 0; row<size; row++) {
        for (int col = 0; col<size; col++) {
            // Es un borde
            if (row==0 or row==size-1 or col==0 or col==size-1) Matriu[row][col] = '#';
            // Superior-Esquerra
            else if (row<mida_del_anterior and col<mida_del_anterior) Matriu[row][col] = Anterior[row][col];
            // Superior-Dreta
            else if (row<mida_del_anterior and col>=mida_del_anterior+1) Matriu[row][col] = Anterior[row][col-(mida_del_anterior+1)];
            // Inferior-Esquerra
            else if (row>=mida_del_anterior+1 and col<mida_del_anterior) Matriu[row][col] = Anterior[row-(mida_del_anterior+1)][col];
            // Inferior-Dreta
            else if (row>=mida_del_anterior+1 and col>=mida_del_anterior+1) Matriu[row][col] = Anterior[row-(mida_del_anterior+1)][col-(mida_del_anterior+1)];
            // Separació
            else Matriu[row][col] = '.';
        }
    }
}

void mostrar(cMatrix& Matriu) {
    for (int i = 0; i<Matriu.size(); i++) {
        for (int j = 0; j<Matriu[0].size(); j++) {
            cout << Matriu[i][j];
        }
        cout << endl;
    }
}

int main () {
    int usr_num;
    cin >> usr_num;
    int mida = calcular_mida(usr_num);
    cMatrix Matriu(mida,vector<char>(mida));
    recursivitat(Matriu, usr_num);
    mostrar(Matriu);
}