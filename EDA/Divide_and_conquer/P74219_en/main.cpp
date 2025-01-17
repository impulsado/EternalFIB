#include <iostream>
#include <vector>
using namespace std;

/* PROPIETAT DE FIBONACCI
Hi ha una propietat dels números de fibonacci amb ús de matrius tal que:
(F_n+1)   (1 1)^n   (F_1)
(F_n  ) = (1 0)   * (F_0)
*/

vector<vector<long long>> multi(const vector<vector<long long>>& A, const vector<vector<long long>>& B, int modulo) {
    vector<vector<long long>> R(2, vector<long long>(2));
    
    R[0][0] = ((A[0][0]*B[0][0])+(A[0][1]*B[1][0]))%modulo;
    R[0][1] = ((A[0][0]*B[0][1])+(A[0][1]*B[1][1]))%modulo;
    R[1][0] = ((A[1][0]*B[0][0])+(A[1][1]*B[1][0]))%modulo;
    R[1][1] = ((A[1][0]*B[0][1])+(A[1][1]*B[1][1]))%modulo;
    
    return R;
}

long long fib(long long n, long long m) {
    // Matriu Propietat Fibonacci
    vector<vector<long long>> FIB(2, vector<long long>(2));
    FIB[0][0] = FIB[0][1] = FIB[1][0] = 1;
    FIB[1][1] = 0;
    
    // Matriu resultat
    vector<vector<long long>> R(2, vector<long long>(2));
    R[0][0] = R[1][1] = 1;
    R[1][0] = R[0][1] = 0;
    
    // Calcular R = FIB^n
    while (n) {
        if (n%2) R = multi(FIB, R, m);
        FIB = multi(FIB, FIB, m);
        n /= 2;
    }

    return R[1][0];
}

int main() {
    long long n, m;
    while (cin >> n >> m) {
        cout << fib(n, m) << endl;
    }
    return 0;
}