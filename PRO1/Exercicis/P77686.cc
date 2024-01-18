#include <iostream>
using namespace std;


bool is_palindromic(int n) {
    int counter = 0, div1 = 1, div2 = 1, xifres = 0;

    for (int divisor = 1; n/divisor>0; divisor = divisor*10) {
        xifres++;
        div1 = divisor;
        counter = xifres;
    }

    while (true) {
        if ((n/div1)%10!=(n/div2)%10) return false;
        div1 = div1/10;
        div2 = div2*10;
        counter--;
        if (counter<=(xifres/2)) return true;
    }
}


int main() {
    int n;
    while (cin >> n) cout << (is_palindromic(n) ? "true" : "false") << endl;
    return 0;
}
