#include <iostream>
using namespace std;


bool c_frac(int n1, int d1, int n2, int d2) {
    double frac1, frac2;
    double num1, num2, deno1, deno2;

    // Passar de int a double
    num1 = 1.0*n1;
    num2 = 1.0*n2;
    deno1 = 1.0*d1;
    deno2 = 1.0*d2;

    // Saber a quin numero equivalen
    frac1 = num1/deno1;
    frac2 = num2/deno2;

    if (frac1<frac2) return true; else return false;
}


int main() {
    int n1, d1, n2, d2;
    while (cin >> n1 >>  d1 >> n2 >> d2) {
        if (c_frac(n1,d1,n2,d2)) cout << "yes" << endl;
        else cout << "no" << endl;
    }   
}
