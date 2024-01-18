#include <iostream>
#include <cmath>
using namespace std;

int suma (int n) {
    if (n<10) return n;
    else return suma(n/10) + n%10;
}

bool es_primer_perfecte(int n) {
    bool is_prime = true;

    if (n==2 or n==3 or n==5 or n==7) return true;
    else if (n<10) return false;
    else {
        for (int i = 2; i<=sqrt(n); i++) if (n%i==0) return false;
        if (is_prime) {
            return es_primer_perfecte(suma(n));
        } else {
            return false;
        }
    }
}


int main() {
    int n;
    while (cin >> n) cout << (es_primer_perfecte(n) ? "true" : "false") << endl;
    return 0;    
}
