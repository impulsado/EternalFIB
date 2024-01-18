#include <iostream>
#include <vector>
using namespace std;

int next_river(int num) {
     int suma = 0;

    for (int i = 1; num/i>0; i*=10) suma += (num/i)%10;

    return suma+num;
}

int trobada_de_rius(int n) {
    int riu1 = 1, riu3 = 3, riu9 = 9;

    while (riu1!=n and riu3!=n and riu9!=n) {
        if (riu1<n) riu1 = next_river(riu1);
        else if (riu3<n) riu3 = next_river(riu3);
        else if (riu9<n) riu9 = next_river(riu9);
        else n = next_river(n);
    }

    return n;
}

int main() {
    int n;
    while (cin >> n) {
        cout << n << " " << trobada_de_rius(n) << endl;
    }

    return 0;
}
