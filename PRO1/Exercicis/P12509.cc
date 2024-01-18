#include <iostream>
using namespace std;

int factorial(int n) {  // Important que sigui 0 perquè aquest és l'últim
    if (n==0) return 1;
    else return n*factorial(n-1);
}

int main() {
    int x;
    while (cin >> x) {
        cout << factorial(x) << endl;
    }
    return 0;
}
