#include <iostream>
using namespace std;

int sum_of_digits(int n) {
    if (n<10) return n;
    return sum_of_digits(n/10)+(n%10);
}

int reduction_of_digits(int n) {
    if (n<10) return n;
    else return reduction_of_digits(sum_of_digits(n));
}

int main() {
    int n;
    while (cin >> n) {
        cout << reduction_of_digits(n) << endl;
    }
    return 0;
}

/*
int reduction_of_digits(int n) {
    int suma = 0;

    if (n < 10) return n;
    else {
        while (n>0) {
            suma = suma + n%10;  // Agafar  últim dígit.
            n = n/10; // Eliminar últim dígit.
        }
        return reduction_of_digits(suma);
    }
}
*/
