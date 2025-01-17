#include <iostream>
#include <vector>
using namespace std;


vector<vector<long long>> multi(const vector<vector<long long>>& A, const vector<vector<long long>>& B, int modulo) {
    vector<vector<long long>> R(2, vector<long long>(2));
    
    R[0][0] = ((A[0][0]*B[0][0])+(A[0][1]*B[1][0]))%modulo;
    R[0][1] = ((A[0][0]*B[0][1])+(A[0][1]*B[1][1]))%modulo;
    R[1][0] = ((A[1][0]*B[0][0])+(A[1][1]*B[1][0]))%modulo;
    R[1][1] = ((A[1][0]*B[0][1])+(A[1][1]*B[1][1]))%modulo;
    
    return R;
}

void potencia(vector<vector<long long>>& M, int exp, int modulo) {
    vector<vector<long long>> R(2, vector<long long>(2));    
    R[0][0] = 1; R[0][1] = 0; R[1][0] = 0; R[1][1] = 1;
    
    while (exp>0) {
        if (exp%2) R = multi(M,R,modulo);
        M = multi(M,M,modulo);
        exp /= 2;
    }

    // Ficar valors
    M = R;
}

int main() {
    vector<vector<long long>> M(2, vector<long long>(2));
    while (cin >> M[0][0] >> M[0][1]) {
        // Demanar dades
        int exp, mod;
        cin >> M[1][0] >> M[1][1];
        cin >> exp >> mod;
        
        // Calcular
        potencia(M, exp, mod);
        
        // Mostrar
        cout << M[0][0] << ' ' << M[0][1] << endl;
        cout << M[1][0] << ' ' << M[1][1] << endl;
        cout << "----------" << endl;
        
        // Menjar-se salt de linea
        char empty;
        cin.getline(&empty,1);
    }
}