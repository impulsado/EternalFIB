#include <bits/stdc++.h>
using namespace std;

bool es_perfecte(int x) {
    int max, suma = 0, divi = 0;
    max = sqrt(x);

    if (x==0 or x==1) return false;

    for (int i = 1; i<=max; i++) {
        if (x%i==0) suma = suma + i, divi = i;
    }

    for (int j = divi; j>1; j--) {
        if (x%j==0) suma = suma + (x/j);
    }

    if (suma==x) return true; else return false;
}

int main() {
    int x;
    while (cin >> x)
        cout << (es_perfecte(x) ? "true" : "false") << endl;

    return 0;
}
